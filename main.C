#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <getopt.h>
#include <time.h>
#include <math.h>
#include "time2str.H"
#include "levenberg_marquardt.H"
#include "cboe_reader.H"
#include "bsmodel.H"
#include "bsmodels/bsmodel_base.H"
#include "bsmodels/bsmodel_2_vr.H"

static void compute_params(cboe_option_quote *options, int num_options,double *best_guess, double *refined) __attribute__ ((unused));
static void compute_params(cboe_option_quote *options, int num_options,double *best_guess, double *refined) {
	levenberg_marquardt_binesh lm;
	bsmodel_base **model_opts = new bsmodel_base *[num_options];

	for (int j = 0; j < num_options; ++j) {
		bsmodel_base *bm = new bsmodel_2_vr(options[j]);
		model_opts[j] = bm;
		if (
			((options[j].bid() > 0.05) && (options[j].ask() > 0.05)) &&
			1
		) lm.add(bm);
	}
	lm.refine(best_guess,refined);
	for (int j = 0; j < num_options; ++j) { delete model_opts[j]; model_opts[j] = NULL; }
	delete[] model_opts;
}

int main(int argc,char *argv[]) {
	double refined[10];
	double best_guess[10];

	refined[0] = best_guess[0] = 0.30;
	refined[1] = best_guess[1] = log(1.1525);
	for (int j = 2; j < 10; ++j) refined[j] = best_guess[j] = 0.0;

	for (int f = 1; f < argc; ++f) {
		cboe_reader cr;
		cr.read_file(argv[f]);

		int num_options = cr.num_options();
		cboe_option_quote *options = cr.options();

/*
		char buffer[1024];
		for (int i = 0; i < num_options; ++i) {
			fprintf(stderr,"%s",options[i].option_symbol());
			fprintf(stderr,"	%s",time2str(buffer,1024,"%Y-%m-%d",options[i].expiration()));
			if (options[i].type() == 1) fprintf(stderr,"	CALL");
			else if (options[i].type() == -1) fprintf(stderr,"	 PUT");
			else abort(); // Should never happen.
			fprintf(stderr,"	$%.2f",options[i].strike());
			fprintf(stderr,"	$%.2f",options[i].bid());
			fprintf(stderr,"	$%.2f",options[i].ask());
			fprintf(stderr,"\n");
		}
 */

		for (int j = 0; j < 10; ++j) best_guess[j] = refined[j];
		compute_params(options,num_options,best_guess,refined);
		fprintf(stderr,"refined = ");
		for (int j = 0; j < 10; ++j) {
			if (j) fprintf(stderr,", ");
			fprintf(stderr,"%.7f",refined[j]);
		}
		fprintf(stderr,"\n");

		fprintf(stderr,"implied yearly volatility: %.7f\n",refined[0]);
		fprintf(stderr,"implied yearly risk free rate: %.7f\n",refined[1]);

		double binesh_sse = 0.0;
		for (int i = 0; i < num_options; ++i) {
			const double *params = refined;
			bsmodel_2_vr b2vr(options[i]);
			double computed = b2vr.value(params);
			double actual = b2vr.actual_price();

			binesh_sse += (actual - computed) * (actual - computed);
			fprintf(stderr,"black_scholes(%.2f, %.2f, %.7f, %d, %.7f, %.7f) = %.7f	(actual=%.7f)\n",
				b2vr.strike(),
				b2vr.current(),
				b2vr.time_to_expiration(),
				(b2vr.type() == -1),
				b2vr.risk_free_rate(params),
				b2vr.volatility(params),
				computed,
				actual
			);
			fprintf(stderr,"	delta=%.7f\n",b2vr.delta(params));
			fprintf(stderr,"	theta=%.7f\n",b2vr.theta(params));
			fprintf(stderr,"	vega=%.7f\n",b2vr.vega(params));
			fprintf(stderr,"	rho=%.7f\n",b2vr.rho(params));
			fprintf(stderr,"	gamma=%.7f\n",b2vr.gamma(params));
		}
		fprintf(stderr,"binesh_sse=%.7f\n",binesh_sse);

		double trevor_sse = 0.0;
		double trevor_refined[] = {
			.1852,
			.0203
		};
		for (int i = 0; i < num_options; ++i) {
			const double *params = trevor_refined;
			bsmodel_2_vr b2vr(options[i]);
			double computed = b2vr.value(params);
			double actual = b2vr.actual_price();

			trevor_sse += (actual - computed) * (actual - computed);
/*
			fprintf(stderr,"bs(%.2f, %.2f, %.7f, %.7f%%, %.7f%%) = %.7f	(actual=%.7f)\n",b2vr.strike(), b2vr.current(), 365 * b2vr.time_to_expiration(), 100 * b2vr.volatility(params), 100 * b2vr.risk_free_rate(params), computed, actual);
			fprintf(stderr,"	delta=%.7f\n",b2vr.delta(params));
			fprintf(stderr,"	theta=%.7f\n",b2vr.theta(params));
			fprintf(stderr,"	vega=%.7f\n",b2vr.vega(params));
			fprintf(stderr,"	rho=%.7f\n",b2vr.rho(params));
			fprintf(stderr,"	gamma=%.7f\n",b2vr.gamma(params));
 */
		}
		fprintf(stderr,"trevor_sse=%.7f\n",trevor_sse);

	}

	return(0);
}
