#ifndef BSMODEL_BASE_H
#define BSMODEL_BASE_H

class bsmodel_base : public bsmodel {
	public:
		bsmodel_base(const cboe_option_quote& coq, int numparams);
		virtual ~bsmodel_base();

		virtual double value(const double params[]);

		virtual double blackdelta(const double params[]) const;
		virtual double blackgamma(const double params[]) const;
		virtual double blackvega(const double params[]) const;
		virtual double blackrho(const double params[]) const;
		virtual double blacktheta(const double params[]) const;

		virtual double delta(const double params[]) const;
		virtual double gamma(const double params[]) const;
		virtual double vega(const double params[]) const;
		virtual double rho(const double params[]) const;
		virtual double theta(const double params[]) const;

		virtual double blackdS(const double params[]) const;
		virtual double blackdSdS(const double params[]) const;
		virtual double blackdSdSdS(const double params[]) const;
		virtual double blackdSdSdSdS(const double params[]) const;
		virtual double blackdSdSdSdr(const double params[]) const;
		virtual double blackdSdSdSdv(const double params[]) const;
		virtual double blackdSdSdSdT(const double params[]) const;
		virtual double blackdSdSdr(const double params[]) const;
		virtual double blackdSdSdrdS(const double params[]) const { return(blackdSdSdSdr(params)); }
		virtual double blackdSdSdrdr(const double params[]) const;
		virtual double blackdSdSdrdv(const double params[]) const;
		virtual double blackdSdSdrdT(const double params[]) const;
		virtual double blackdSdSdv(const double params[]) const;
		virtual double blackdSdSdvdS(const double params[]) const { return(blackdSdSdSdv(params)); }
		virtual double blackdSdSdvdr(const double params[]) const { return(blackdSdSdrdv(params)); }
		virtual double blackdSdSdvdv(const double params[]) const;
		virtual double blackdSdSdvdT(const double params[]) const;
		virtual double blackdSdSdT(const double params[]) const;
		virtual double blackdSdSdTdS(const double params[]) const { return(blackdSdSdSdT(params)); }
		virtual double blackdSdSdTdr(const double params[]) const { return(blackdSdSdrdT(params)); }
		virtual double blackdSdSdTdv(const double params[]) const { return(blackdSdSdvdT(params)); }
		virtual double blackdSdSdTdT(const double params[]) const;
		virtual double blackdSdr(const double params[]) const;
		virtual double blackdSdrdS(const double params[]) const { return(blackdSdSdr(params)); }
		virtual double blackdSdrdSdS(const double params[]) const { return(blackdSdSdSdr(params)); }
		virtual double blackdSdrdSdr(const double params[]) const { return(blackdSdSdrdr(params)); }
		virtual double blackdSdrdSdv(const double params[]) const { return(blackdSdSdrdv(params)); }
		virtual double blackdSdrdSdT(const double params[]) const { return(blackdSdSdrdT(params)); }
		virtual double blackdSdrdr(const double params[]) const;
		virtual double blackdSdrdrdS(const double params[]) const { return(blackdSdSdrdr(params)); }
		virtual double blackdSdrdrdr(const double params[]) const;
		virtual double blackdSdrdrdv(const double params[]) const;
		virtual double blackdSdrdrdT(const double params[]) const;
		virtual double blackdSdrdv(const double params[]) const;
		virtual double blackdSdrdvdS(const double params[]) const { return(blackdSdSdrdv(params)); }
		virtual double blackdSdrdvdr(const double params[]) const { return(blackdSdrdrdv(params)); }
		virtual double blackdSdrdvdv(const double params[]) const;
		virtual double blackdSdrdvdT(const double params[]) const;
		virtual double blackdSdrdT(const double params[]) const;
		virtual double blackdSdrdTdS(const double params[]) const { return(blackdSdSdrdT(params)); }
		virtual double blackdSdrdTdr(const double params[]) const { return(blackdSdrdrdT(params)); }
		virtual double blackdSdrdTdv(const double params[]) const { return(blackdSdrdvdT(params)); }
		virtual double blackdSdrdTdT(const double params[]) const;
		virtual double blackdSdv(const double params[]) const;
		virtual double blackdSdvdS(const double params[]) const { return(blackdSdSdv(params)); }
		virtual double blackdSdvdSdS(const double params[]) const { return(blackdSdSdSdv(params)); }
		virtual double blackdSdvdSdr(const double params[]) const { return(blackdSdSdrdv(params)); }
		virtual double blackdSdvdSdv(const double params[]) const { return(blackdSdSdvdv(params)); }
		virtual double blackdSdvdSdT(const double params[]) const { return(blackdSdSdvdT(params)); }
		virtual double blackdSdvdr(const double params[]) const { return(blackdSdrdv(params)); }
		virtual double blackdSdvdrdS(const double params[]) const { return(blackdSdSdrdv(params)); }
		virtual double blackdSdvdrdr(const double params[]) const { return(blackdSdrdrdv(params)); }
		virtual double blackdSdvdrdv(const double params[]) const { return(blackdSdrdvdv(params)); }
		virtual double blackdSdvdrdT(const double params[]) const { return(blackdSdrdvdT(params)); }
		virtual double blackdSdvdv(const double params[]) const;
		virtual double blackdSdvdvdS(const double params[]) const { return(blackdSdSdvdv(params)); }
		virtual double blackdSdvdvdr(const double params[]) const { return(blackdSdrdvdv(params)); }
		virtual double blackdSdvdvdv(const double params[]) const;
		virtual double blackdSdvdvdT(const double params[]) const;
		virtual double blackdSdvdT(const double params[]) const;
		virtual double blackdSdvdTdS(const double params[]) const { return(blackdSdSdvdT(params)); }
		virtual double blackdSdvdTdr(const double params[]) const { return(blackdSdrdvdT(params)); }
		virtual double blackdSdvdTdv(const double params[]) const { return(blackdSdvdvdT(params)); }
		virtual double blackdSdvdTdT(const double params[]) const;
		virtual double blackdSdT(const double params[]) const;
		virtual double blackdSdTdS(const double params[]) const { return(blackdSdSdT(params)); }
		virtual double blackdSdTdSdS(const double params[]) const { return(blackdSdSdSdT(params)); }
		virtual double blackdSdTdSdr(const double params[]) const { return(blackdSdSdrdT(params)); }
		virtual double blackdSdTdSdv(const double params[]) const { return(blackdSdSdvdT(params)); }
		virtual double blackdSdTdSdT(const double params[]) const { return(blackdSdSdTdT(params)); }
		virtual double blackdSdTdr(const double params[]) const { return(blackdSdrdT(params)); }
		virtual double blackdSdTdrdS(const double params[]) const { return(blackdSdSdrdT(params)); }
		virtual double blackdSdTdrdr(const double params[]) const { return(blackdSdrdrdT(params)); }
		virtual double blackdSdTdrdv(const double params[]) const { return(blackdSdrdvdT(params)); }
		virtual double blackdSdTdrdT(const double params[]) const { return(blackdSdrdTdT(params)); }
		virtual double blackdSdTdv(const double params[]) const { return(blackdSdvdT(params)); }
		virtual double blackdSdTdvdS(const double params[]) const { return(blackdSdSdvdT(params)); }
		virtual double blackdSdTdvdr(const double params[]) const { return(blackdSdrdvdT(params)); }
		virtual double blackdSdTdvdv(const double params[]) const { return(blackdSdvdvdT(params)); }
		virtual double blackdSdTdvdT(const double params[]) const { return(blackdSdvdTdT(params)); }
		virtual double blackdSdTdT(const double params[]) const;
		virtual double blackdSdTdTdS(const double params[]) const { return(blackdSdSdTdT(params)); }
		virtual double blackdSdTdTdr(const double params[]) const { return(blackdSdrdTdT(params)); }
		virtual double blackdSdTdTdv(const double params[]) const { return(blackdSdvdTdT(params)); }
		virtual double blackdSdTdTdT(const double params[]) const;
		virtual double blackdr(const double params[]) const;
		virtual double blackdrdS(const double params[]) const { return(blackdSdr(params)); }
		virtual double blackdrdSdS(const double params[]) const { return(blackdSdSdr(params)); }
		virtual double blackdrdSdSdS(const double params[]) const { return(blackdSdSdSdr(params)); }
		virtual double blackdrdSdSdr(const double params[]) const { return(blackdSdSdrdr(params)); }
		virtual double blackdrdSdSdv(const double params[]) const { return(blackdSdSdrdv(params)); }
		virtual double blackdrdSdSdT(const double params[]) const { return(blackdSdSdrdT(params)); }
		virtual double blackdrdSdr(const double params[]) const { return(blackdSdrdr(params)); }
		virtual double blackdrdSdrdS(const double params[]) const { return(blackdSdSdrdr(params)); }
		virtual double blackdrdSdrdr(const double params[]) const { return(blackdSdrdrdr(params)); }
		virtual double blackdrdSdrdv(const double params[]) const { return(blackdSdrdrdv(params)); }
		virtual double blackdrdSdrdT(const double params[]) const { return(blackdSdrdrdT(params)); }
		virtual double blackdrdSdv(const double params[]) const { return(blackdSdrdv(params)); }
		virtual double blackdrdSdvdS(const double params[]) const { return(blackdSdSdrdv(params)); }
		virtual double blackdrdSdvdr(const double params[]) const { return(blackdSdrdrdv(params)); }
		virtual double blackdrdSdvdv(const double params[]) const { return(blackdSdrdvdv(params)); }
		virtual double blackdrdSdvdT(const double params[]) const { return(blackdSdrdvdT(params)); }
		virtual double blackdrdSdT(const double params[]) const { return(blackdSdrdT(params)); }
		virtual double blackdrdSdTdS(const double params[]) const { return(blackdSdSdrdT(params)); }
		virtual double blackdrdSdTdr(const double params[]) const { return(blackdSdrdrdT(params)); }
		virtual double blackdrdSdTdv(const double params[]) const { return(blackdSdrdvdT(params)); }
		virtual double blackdrdSdTdT(const double params[]) const { return(blackdSdrdTdT(params)); }
		virtual double blackdrdr(const double params[]) const;
		virtual double blackdrdrdS(const double params[]) const { return(blackdSdrdr(params)); }
		virtual double blackdrdrdSdS(const double params[]) const { return(blackdSdSdrdr(params)); }
		virtual double blackdrdrdSdr(const double params[]) const { return(blackdSdrdrdr(params)); }
		virtual double blackdrdrdSdv(const double params[]) const { return(blackdSdrdrdv(params)); }
		virtual double blackdrdrdSdT(const double params[]) const { return(blackdSdrdrdT(params)); }
		virtual double blackdrdrdr(const double params[]) const;
		virtual double blackdrdrdrdS(const double params[]) const { return(blackdSdrdrdr(params)); }
		virtual double blackdrdrdrdr(const double params[]) const;
		virtual double blackdrdrdrdv(const double params[]) const;
		virtual double blackdrdrdrdT(const double params[]) const;
		virtual double blackdrdrdv(const double params[]) const;
		virtual double blackdrdrdvdS(const double params[]) const { return(blackdSdrdrdv(params)); }
		virtual double blackdrdrdvdr(const double params[]) const { return(blackdrdrdrdv(params)); }
		virtual double blackdrdrdvdv(const double params[]) const;
		virtual double blackdrdrdvdT(const double params[]) const;
		virtual double blackdrdrdT(const double params[]) const;
		virtual double blackdrdrdTdS(const double params[]) const { return(blackdSdrdrdT(params)); }
		virtual double blackdrdrdTdr(const double params[]) const { return(blackdrdrdrdT(params)); }
		virtual double blackdrdrdTdv(const double params[]) const { return(blackdrdrdvdT(params)); }
		virtual double blackdrdrdTdT(const double params[]) const;
		virtual double blackdrdv(const double params[]) const;
		virtual double blackdrdvdS(const double params[]) const { return(blackdSdrdv(params)); }
		virtual double blackdrdvdSdS(const double params[]) const { return(blackdSdSdrdv(params)); }
		virtual double blackdrdvdSdr(const double params[]) const { return(blackdSdrdrdv(params)); }
		virtual double blackdrdvdSdv(const double params[]) const { return(blackdSdrdvdv(params)); }
		virtual double blackdrdvdSdT(const double params[]) const { return(blackdSdrdvdT(params)); }
		virtual double blackdrdvdr(const double params[]) const { return(blackdrdrdv(params)); }
		virtual double blackdrdvdrdS(const double params[]) const { return(blackdSdrdrdv(params)); }
		virtual double blackdrdvdrdr(const double params[]) const { return(blackdrdrdrdv(params)); }
		virtual double blackdrdvdrdv(const double params[]) const { return(blackdrdrdvdv(params)); }
		virtual double blackdrdvdrdT(const double params[]) const { return(blackdrdrdvdT(params)); }
		virtual double blackdrdvdv(const double params[]) const;
		virtual double blackdrdvdvdS(const double params[]) const { return(blackdSdrdvdv(params)); }
		virtual double blackdrdvdvdr(const double params[]) const { return(blackdrdrdvdv(params)); }
		virtual double blackdrdvdvdv(const double params[]) const;
		virtual double blackdrdvdvdT(const double params[]) const;
		virtual double blackdrdvdT(const double params[]) const;
		virtual double blackdrdvdTdS(const double params[]) const { return(blackdSdrdvdT(params)); }
		virtual double blackdrdvdTdr(const double params[]) const { return(blackdrdrdvdT(params)); }
		virtual double blackdrdvdTdv(const double params[]) const { return(blackdrdvdvdT(params)); }
		virtual double blackdrdvdTdT(const double params[]) const;
		virtual double blackdrdT(const double params[]) const;
		virtual double blackdrdTdS(const double params[]) const { return(blackdSdrdT(params)); }
		virtual double blackdrdTdSdS(const double params[]) const { return(blackdSdSdrdT(params)); }
		virtual double blackdrdTdSdr(const double params[]) const { return(blackdSdrdrdT(params)); }
		virtual double blackdrdTdSdv(const double params[]) const { return(blackdSdrdvdT(params)); }
		virtual double blackdrdTdSdT(const double params[]) const { return(blackdSdrdTdT(params)); }
		virtual double blackdrdTdr(const double params[]) const { return(blackdrdrdT(params)); }
		virtual double blackdrdTdrdS(const double params[]) const { return(blackdSdrdrdT(params)); }
		virtual double blackdrdTdrdr(const double params[]) const { return(blackdrdrdrdT(params)); }
		virtual double blackdrdTdrdv(const double params[]) const { return(blackdrdrdvdT(params)); }
		virtual double blackdrdTdrdT(const double params[]) const { return(blackdrdrdTdT(params)); }
		virtual double blackdrdTdv(const double params[]) const { return(blackdrdvdT(params)); }
		virtual double blackdrdTdvdS(const double params[]) const { return(blackdSdrdvdT(params)); }
		virtual double blackdrdTdvdr(const double params[]) const { return(blackdrdrdvdT(params)); }
		virtual double blackdrdTdvdv(const double params[]) const { return(blackdrdvdvdT(params)); }
		virtual double blackdrdTdvdT(const double params[]) const { return(blackdrdvdTdT(params)); }
		virtual double blackdrdTdT(const double params[]) const;
		virtual double blackdrdTdTdS(const double params[]) const { return(blackdSdrdTdT(params)); }
		virtual double blackdrdTdTdr(const double params[]) const { return(blackdrdrdTdT(params)); }
		virtual double blackdrdTdTdv(const double params[]) const { return(blackdrdvdTdT(params)); }
		virtual double blackdrdTdTdT(const double params[]) const;
		virtual double blackdv(const double params[]) const;
		virtual double blackdvdS(const double params[]) const { return(blackdSdv(params)); }
		virtual double blackdvdSdS(const double params[]) const { return(blackdSdSdv(params)); }
		virtual double blackdvdSdSdS(const double params[]) const { return(blackdSdSdSdv(params)); }
		virtual double blackdvdSdSdr(const double params[]) const { return(blackdSdSdrdv(params)); }
		virtual double blackdvdSdSdv(const double params[]) const { return(blackdSdSdvdv(params)); }
		virtual double blackdvdSdSdT(const double params[]) const { return(blackdSdSdvdT(params)); }
		virtual double blackdvdSdr(const double params[]) const { return(blackdSdrdv(params)); }
		virtual double blackdvdSdrdS(const double params[]) const { return(blackdSdSdrdv(params)); }
		virtual double blackdvdSdrdr(const double params[]) const { return(blackdSdrdrdv(params)); }
		virtual double blackdvdSdrdv(const double params[]) const { return(blackdSdrdvdv(params)); }
		virtual double blackdvdSdrdT(const double params[]) const { return(blackdSdrdvdT(params)); }
		virtual double blackdvdSdv(const double params[]) const { return(blackdSdvdv(params)); }
		virtual double blackdvdSdvdS(const double params[]) const { return(blackdSdSdvdv(params)); }
		virtual double blackdvdSdvdr(const double params[]) const { return(blackdSdrdvdv(params)); }
		virtual double blackdvdSdvdv(const double params[]) const { return(blackdSdvdvdv(params)); }
		virtual double blackdvdSdvdT(const double params[]) const { return(blackdSdvdvdT(params)); }
		virtual double blackdvdSdT(const double params[]) const { return(blackdSdvdT(params)); }
		virtual double blackdvdSdTdS(const double params[]) const { return(blackdSdSdvdT(params)); }
		virtual double blackdvdSdTdr(const double params[]) const { return(blackdSdrdvdT(params)); }
		virtual double blackdvdSdTdv(const double params[]) const { return(blackdSdvdvdT(params)); }
		virtual double blackdvdSdTdT(const double params[]) const { return(blackdSdvdTdT(params)); }
		virtual double blackdvdr(const double params[]) const { return(blackdrdv(params)); }
		virtual double blackdvdrdS(const double params[]) const { return(blackdSdrdv(params)); }
		virtual double blackdvdrdSdS(const double params[]) const { return(blackdSdSdrdv(params)); }
		virtual double blackdvdrdSdr(const double params[]) const { return(blackdSdrdrdv(params)); }
		virtual double blackdvdrdSdv(const double params[]) const { return(blackdSdrdvdv(params)); }
		virtual double blackdvdrdSdT(const double params[]) const { return(blackdSdrdvdT(params)); }
		virtual double blackdvdrdr(const double params[]) const { return(blackdrdrdv(params)); }
		virtual double blackdvdrdrdS(const double params[]) const { return(blackdSdrdrdv(params)); }
		virtual double blackdvdrdrdr(const double params[]) const { return(blackdrdrdrdv(params)); }
		virtual double blackdvdrdrdv(const double params[]) const { return(blackdrdrdvdv(params)); }
		virtual double blackdvdrdrdT(const double params[]) const { return(blackdrdrdvdT(params)); }
		virtual double blackdvdrdv(const double params[]) const { return(blackdrdvdv(params)); }
		virtual double blackdvdrdvdS(const double params[]) const { return(blackdSdrdvdv(params)); }
		virtual double blackdvdrdvdr(const double params[]) const { return(blackdrdrdvdv(params)); }
		virtual double blackdvdrdvdv(const double params[]) const { return(blackdrdvdvdv(params)); }
		virtual double blackdvdrdvdT(const double params[]) const { return(blackdrdvdvdT(params)); }
		virtual double blackdvdrdT(const double params[]) const { return(blackdrdvdT(params)); }
		virtual double blackdvdrdTdS(const double params[]) const { return(blackdSdrdvdT(params)); }
		virtual double blackdvdrdTdr(const double params[]) const { return(blackdrdrdvdT(params)); }
		virtual double blackdvdrdTdv(const double params[]) const { return(blackdrdvdvdT(params)); }
		virtual double blackdvdrdTdT(const double params[]) const { return(blackdrdvdTdT(params)); }
		virtual double blackdvdv(const double params[]) const;
		virtual double blackdvdvdS(const double params[]) const { return(blackdSdvdv(params)); }
		virtual double blackdvdvdSdS(const double params[]) const { return(blackdSdSdvdv(params)); }
		virtual double blackdvdvdSdr(const double params[]) const { return(blackdSdrdvdv(params)); }
		virtual double blackdvdvdSdv(const double params[]) const { return(blackdSdvdvdv(params)); }
		virtual double blackdvdvdSdT(const double params[]) const { return(blackdSdvdvdT(params)); }
		virtual double blackdvdvdr(const double params[]) const { return(blackdrdvdv(params)); }
		virtual double blackdvdvdrdS(const double params[]) const { return(blackdSdrdvdv(params)); }
		virtual double blackdvdvdrdr(const double params[]) const { return(blackdrdrdvdv(params)); }
		virtual double blackdvdvdrdv(const double params[]) const { return(blackdrdvdvdv(params)); }
		virtual double blackdvdvdrdT(const double params[]) const { return(blackdrdvdvdT(params)); }
		virtual double blackdvdvdv(const double params[]) const;
		virtual double blackdvdvdvdS(const double params[]) const { return(blackdSdvdvdv(params)); }
		virtual double blackdvdvdvdr(const double params[]) const { return(blackdrdvdvdv(params)); }
		virtual double blackdvdvdvdv(const double params[]) const;
		virtual double blackdvdvdvdT(const double params[]) const;
		virtual double blackdvdvdT(const double params[]) const;
		virtual double blackdvdvdTdS(const double params[]) const { return(blackdSdvdvdT(params)); }
		virtual double blackdvdvdTdr(const double params[]) const { return(blackdrdvdvdT(params)); }
		virtual double blackdvdvdTdv(const double params[]) const { return(blackdvdvdvdT(params)); }
		virtual double blackdvdvdTdT(const double params[]) const;
		virtual double blackdvdT(const double params[]) const;
		virtual double blackdvdTdS(const double params[]) const { return(blackdSdvdT(params)); }
		virtual double blackdvdTdSdS(const double params[]) const { return(blackdSdSdvdT(params)); }
		virtual double blackdvdTdSdr(const double params[]) const { return(blackdSdrdvdT(params)); }
		virtual double blackdvdTdSdv(const double params[]) const { return(blackdSdvdvdT(params)); }
		virtual double blackdvdTdSdT(const double params[]) const { return(blackdSdvdTdT(params)); }
		virtual double blackdvdTdr(const double params[]) const { return(blackdrdvdT(params)); }
		virtual double blackdvdTdrdS(const double params[]) const { return(blackdSdrdvdT(params)); }
		virtual double blackdvdTdrdr(const double params[]) const { return(blackdrdrdvdT(params)); }
		virtual double blackdvdTdrdv(const double params[]) const { return(blackdrdvdvdT(params)); }
		virtual double blackdvdTdrdT(const double params[]) const { return(blackdrdvdTdT(params)); }
		virtual double blackdvdTdv(const double params[]) const { return(blackdvdvdT(params)); }
		virtual double blackdvdTdvdS(const double params[]) const { return(blackdSdvdvdT(params)); }
		virtual double blackdvdTdvdr(const double params[]) const { return(blackdrdvdvdT(params)); }
		virtual double blackdvdTdvdv(const double params[]) const { return(blackdvdvdvdT(params)); }
		virtual double blackdvdTdvdT(const double params[]) const { return(blackdvdvdTdT(params)); }
		virtual double blackdvdTdT(const double params[]) const;
		virtual double blackdvdTdTdS(const double params[]) const { return(blackdSdvdTdT(params)); }
		virtual double blackdvdTdTdr(const double params[]) const { return(blackdrdvdTdT(params)); }
		virtual double blackdvdTdTdv(const double params[]) const { return(blackdvdvdTdT(params)); }
		virtual double blackdvdTdTdT(const double params[]) const;
		virtual double blackdT(const double params[]) const;
		virtual double blackdTdS(const double params[]) const { return(blackdSdT(params)); }
		virtual double blackdTdSdS(const double params[]) const { return(blackdSdSdT(params)); }
		virtual double blackdTdSdSdS(const double params[]) const { return(blackdSdSdSdT(params)); }
		virtual double blackdTdSdSdr(const double params[]) const { return(blackdSdSdrdT(params)); }
		virtual double blackdTdSdSdv(const double params[]) const { return(blackdSdSdvdT(params)); }
		virtual double blackdTdSdSdT(const double params[]) const { return(blackdSdSdTdT(params)); }
		virtual double blackdTdSdr(const double params[]) const { return(blackdSdrdT(params)); }
		virtual double blackdTdSdrdS(const double params[]) const { return(blackdSdSdrdT(params)); }
		virtual double blackdTdSdrdr(const double params[]) const { return(blackdSdrdrdT(params)); }
		virtual double blackdTdSdrdv(const double params[]) const { return(blackdSdrdvdT(params)); }
		virtual double blackdTdSdrdT(const double params[]) const { return(blackdSdrdTdT(params)); }
		virtual double blackdTdSdv(const double params[]) const { return(blackdSdvdT(params)); }
		virtual double blackdTdSdvdS(const double params[]) const { return(blackdSdSdvdT(params)); }
		virtual double blackdTdSdvdr(const double params[]) const { return(blackdSdrdvdT(params)); }
		virtual double blackdTdSdvdv(const double params[]) const { return(blackdSdvdvdT(params)); }
		virtual double blackdTdSdvdT(const double params[]) const { return(blackdSdvdTdT(params)); }
		virtual double blackdTdSdT(const double params[]) const { return(blackdSdTdT(params)); }
		virtual double blackdTdSdTdS(const double params[]) const { return(blackdSdSdTdT(params)); }
		virtual double blackdTdSdTdr(const double params[]) const { return(blackdSdrdTdT(params)); }
		virtual double blackdTdSdTdv(const double params[]) const { return(blackdSdvdTdT(params)); }
		virtual double blackdTdSdTdT(const double params[]) const { return(blackdSdTdTdT(params)); }
		virtual double blackdTdr(const double params[]) const { return(blackdrdT(params)); }
		virtual double blackdTdrdS(const double params[]) const { return(blackdSdrdT(params)); }
		virtual double blackdTdrdSdS(const double params[]) const { return(blackdSdSdrdT(params)); }
		virtual double blackdTdrdSdr(const double params[]) const { return(blackdSdrdrdT(params)); }
		virtual double blackdTdrdSdv(const double params[]) const { return(blackdSdrdvdT(params)); }
		virtual double blackdTdrdSdT(const double params[]) const { return(blackdSdrdTdT(params)); }
		virtual double blackdTdrdr(const double params[]) const { return(blackdrdrdT(params)); }
		virtual double blackdTdrdrdS(const double params[]) const { return(blackdSdrdrdT(params)); }
		virtual double blackdTdrdrdr(const double params[]) const { return(blackdrdrdrdT(params)); }
		virtual double blackdTdrdrdv(const double params[]) const { return(blackdrdrdvdT(params)); }
		virtual double blackdTdrdrdT(const double params[]) const { return(blackdrdrdTdT(params)); }
		virtual double blackdTdrdv(const double params[]) const { return(blackdrdvdT(params)); }
		virtual double blackdTdrdvdS(const double params[]) const { return(blackdSdrdvdT(params)); }
		virtual double blackdTdrdvdr(const double params[]) const { return(blackdrdrdvdT(params)); }
		virtual double blackdTdrdvdv(const double params[]) const { return(blackdrdvdvdT(params)); }
		virtual double blackdTdrdvdT(const double params[]) const { return(blackdrdvdTdT(params)); }
		virtual double blackdTdrdT(const double params[]) const { return(blackdrdTdT(params)); }
		virtual double blackdTdrdTdS(const double params[]) const { return(blackdSdrdTdT(params)); }
		virtual double blackdTdrdTdr(const double params[]) const { return(blackdrdrdTdT(params)); }
		virtual double blackdTdrdTdv(const double params[]) const { return(blackdrdvdTdT(params)); }
		virtual double blackdTdrdTdT(const double params[]) const { return(blackdrdTdTdT(params)); }
		virtual double blackdTdv(const double params[]) const { return(blackdvdT(params)); }
		virtual double blackdTdvdS(const double params[]) const { return(blackdSdvdT(params)); }
		virtual double blackdTdvdSdS(const double params[]) const { return(blackdSdSdvdT(params)); }
		virtual double blackdTdvdSdr(const double params[]) const { return(blackdSdrdvdT(params)); }
		virtual double blackdTdvdSdv(const double params[]) const { return(blackdSdvdvdT(params)); }
		virtual double blackdTdvdSdT(const double params[]) const { return(blackdSdvdTdT(params)); }
		virtual double blackdTdvdr(const double params[]) const { return(blackdrdvdT(params)); }
		virtual double blackdTdvdrdS(const double params[]) const { return(blackdSdrdvdT(params)); }
		virtual double blackdTdvdrdr(const double params[]) const { return(blackdrdrdvdT(params)); }
		virtual double blackdTdvdrdv(const double params[]) const { return(blackdrdvdvdT(params)); }
		virtual double blackdTdvdrdT(const double params[]) const { return(blackdrdvdTdT(params)); }
		virtual double blackdTdvdv(const double params[]) const { return(blackdvdvdT(params)); }
		virtual double blackdTdvdvdS(const double params[]) const { return(blackdSdvdvdT(params)); }
		virtual double blackdTdvdvdr(const double params[]) const { return(blackdrdvdvdT(params)); }
		virtual double blackdTdvdvdv(const double params[]) const { return(blackdvdvdvdT(params)); }
		virtual double blackdTdvdvdT(const double params[]) const { return(blackdvdvdTdT(params)); }
		virtual double blackdTdvdT(const double params[]) const { return(blackdvdTdT(params)); }
		virtual double blackdTdvdTdS(const double params[]) const { return(blackdSdvdTdT(params)); }
		virtual double blackdTdvdTdr(const double params[]) const { return(blackdrdvdTdT(params)); }
		virtual double blackdTdvdTdv(const double params[]) const { return(blackdvdvdTdT(params)); }
		virtual double blackdTdvdTdT(const double params[]) const { return(blackdvdTdTdT(params)); }
		virtual double blackdTdT(const double params[]) const;
		virtual double blackdTdTdS(const double params[]) const { return(blackdSdTdT(params)); }
		virtual double blackdTdTdSdS(const double params[]) const { return(blackdSdSdTdT(params)); }
		virtual double blackdTdTdSdr(const double params[]) const { return(blackdSdrdTdT(params)); }
		virtual double blackdTdTdSdv(const double params[]) const { return(blackdSdvdTdT(params)); }
		virtual double blackdTdTdSdT(const double params[]) const { return(blackdSdTdTdT(params)); }
		virtual double blackdTdTdr(const double params[]) const { return(blackdrdTdT(params)); }
		virtual double blackdTdTdrdS(const double params[]) const { return(blackdSdrdTdT(params)); }
		virtual double blackdTdTdrdr(const double params[]) const { return(blackdrdrdTdT(params)); }
		virtual double blackdTdTdrdv(const double params[]) const { return(blackdrdvdTdT(params)); }
		virtual double blackdTdTdrdT(const double params[]) const { return(blackdrdTdTdT(params)); }
		virtual double blackdTdTdv(const double params[]) const { return(blackdvdTdT(params)); }
		virtual double blackdTdTdvdS(const double params[]) const { return(blackdSdvdTdT(params)); }
		virtual double blackdTdTdvdr(const double params[]) const { return(blackdrdvdTdT(params)); }
		virtual double blackdTdTdvdv(const double params[]) const { return(blackdvdvdTdT(params)); }
		virtual double blackdTdTdvdT(const double params[]) const { return(blackdvdTdTdT(params)); }
		virtual double blackdTdTdT(const double params[]) const;
		virtual double blackdTdTdTdS(const double params[]) const { return(blackdSdTdTdT(params)); }
		virtual double blackdTdTdTdr(const double params[]) const { return(blackdrdTdTdT(params)); }
		virtual double blackdTdTdTdv(const double params[]) const { return(blackdvdTdTdT(params)); }
		virtual double blackdTdTdTdT(const double params[]) const;
		virtual double dS(const double params[]) const;
		virtual double dSdS(const double params[]) const;
		virtual double dSdSdS(const double params[]) const;
		virtual double dSdSdSdS(const double params[]) const;
		virtual double dSdSdSdr(const double params[]) const;
		virtual double dSdSdSdv(const double params[]) const;
		virtual double dSdSdSdT(const double params[]) const;
		virtual double dSdSdr(const double params[]) const;
		virtual double dSdSdrdS(const double params[]) const { return(dSdSdSdr(params)); }
		virtual double dSdSdrdr(const double params[]) const;
		virtual double dSdSdrdv(const double params[]) const;
		virtual double dSdSdrdT(const double params[]) const;
		virtual double dSdSdv(const double params[]) const;
		virtual double dSdSdvdS(const double params[]) const { return(dSdSdSdv(params)); }
		virtual double dSdSdvdr(const double params[]) const { return(dSdSdrdv(params)); }
		virtual double dSdSdvdv(const double params[]) const;
		virtual double dSdSdvdT(const double params[]) const;
		virtual double dSdSdT(const double params[]) const;
		virtual double dSdSdTdS(const double params[]) const { return(dSdSdSdT(params)); }
		virtual double dSdSdTdr(const double params[]) const { return(dSdSdrdT(params)); }
		virtual double dSdSdTdv(const double params[]) const { return(dSdSdvdT(params)); }
		virtual double dSdSdTdT(const double params[]) const;
		virtual double dSdr(const double params[]) const;
		virtual double dSdrdS(const double params[]) const { return(dSdSdr(params)); }
		virtual double dSdrdSdS(const double params[]) const { return(dSdSdSdr(params)); }
		virtual double dSdrdSdr(const double params[]) const { return(dSdSdrdr(params)); }
		virtual double dSdrdSdv(const double params[]) const { return(dSdSdrdv(params)); }
		virtual double dSdrdSdT(const double params[]) const { return(dSdSdrdT(params)); }
		virtual double dSdrdr(const double params[]) const;
		virtual double dSdrdrdS(const double params[]) const { return(dSdSdrdr(params)); }
		virtual double dSdrdrdr(const double params[]) const;
		virtual double dSdrdrdv(const double params[]) const;
		virtual double dSdrdrdT(const double params[]) const;
		virtual double dSdrdv(const double params[]) const;
		virtual double dSdrdvdS(const double params[]) const { return(dSdSdrdv(params)); }
		virtual double dSdrdvdr(const double params[]) const { return(dSdrdrdv(params)); }
		virtual double dSdrdvdv(const double params[]) const;
		virtual double dSdrdvdT(const double params[]) const;
		virtual double dSdrdT(const double params[]) const;
		virtual double dSdrdTdS(const double params[]) const { return(dSdSdrdT(params)); }
		virtual double dSdrdTdr(const double params[]) const { return(dSdrdrdT(params)); }
		virtual double dSdrdTdv(const double params[]) const { return(dSdrdvdT(params)); }
		virtual double dSdrdTdT(const double params[]) const;
		virtual double dSdv(const double params[]) const;
		virtual double dSdvdS(const double params[]) const { return(dSdSdv(params)); }
		virtual double dSdvdSdS(const double params[]) const { return(dSdSdSdv(params)); }
		virtual double dSdvdSdr(const double params[]) const { return(dSdSdrdv(params)); }
		virtual double dSdvdSdv(const double params[]) const { return(dSdSdvdv(params)); }
		virtual double dSdvdSdT(const double params[]) const { return(dSdSdvdT(params)); }
		virtual double dSdvdr(const double params[]) const { return(dSdrdv(params)); }
		virtual double dSdvdrdS(const double params[]) const { return(dSdSdrdv(params)); }
		virtual double dSdvdrdr(const double params[]) const { return(dSdrdrdv(params)); }
		virtual double dSdvdrdv(const double params[]) const { return(dSdrdvdv(params)); }
		virtual double dSdvdrdT(const double params[]) const { return(dSdrdvdT(params)); }
		virtual double dSdvdv(const double params[]) const;
		virtual double dSdvdvdS(const double params[]) const { return(dSdSdvdv(params)); }
		virtual double dSdvdvdr(const double params[]) const { return(dSdrdvdv(params)); }
		virtual double dSdvdvdv(const double params[]) const;
		virtual double dSdvdvdT(const double params[]) const;
		virtual double dSdvdT(const double params[]) const;
		virtual double dSdvdTdS(const double params[]) const { return(dSdSdvdT(params)); }
		virtual double dSdvdTdr(const double params[]) const { return(dSdrdvdT(params)); }
		virtual double dSdvdTdv(const double params[]) const { return(dSdvdvdT(params)); }
		virtual double dSdvdTdT(const double params[]) const;
		virtual double dSdT(const double params[]) const;
		virtual double dSdTdS(const double params[]) const { return(dSdSdT(params)); }
		virtual double dSdTdSdS(const double params[]) const { return(dSdSdSdT(params)); }
		virtual double dSdTdSdr(const double params[]) const { return(dSdSdrdT(params)); }
		virtual double dSdTdSdv(const double params[]) const { return(dSdSdvdT(params)); }
		virtual double dSdTdSdT(const double params[]) const { return(dSdSdTdT(params)); }
		virtual double dSdTdr(const double params[]) const { return(dSdrdT(params)); }
		virtual double dSdTdrdS(const double params[]) const { return(dSdSdrdT(params)); }
		virtual double dSdTdrdr(const double params[]) const { return(dSdrdrdT(params)); }
		virtual double dSdTdrdv(const double params[]) const { return(dSdrdvdT(params)); }
		virtual double dSdTdrdT(const double params[]) const { return(dSdrdTdT(params)); }
		virtual double dSdTdv(const double params[]) const { return(dSdvdT(params)); }
		virtual double dSdTdvdS(const double params[]) const { return(dSdSdvdT(params)); }
		virtual double dSdTdvdr(const double params[]) const { return(dSdrdvdT(params)); }
		virtual double dSdTdvdv(const double params[]) const { return(dSdvdvdT(params)); }
		virtual double dSdTdvdT(const double params[]) const { return(dSdvdTdT(params)); }
		virtual double dSdTdT(const double params[]) const;
		virtual double dSdTdTdS(const double params[]) const { return(dSdSdTdT(params)); }
		virtual double dSdTdTdr(const double params[]) const { return(dSdrdTdT(params)); }
		virtual double dSdTdTdv(const double params[]) const { return(dSdvdTdT(params)); }
		virtual double dSdTdTdT(const double params[]) const;
		virtual double dr(const double params[]) const;
		virtual double drdS(const double params[]) const { return(dSdr(params)); }
		virtual double drdSdS(const double params[]) const { return(dSdSdr(params)); }
		virtual double drdSdSdS(const double params[]) const { return(dSdSdSdr(params)); }
		virtual double drdSdSdr(const double params[]) const { return(dSdSdrdr(params)); }
		virtual double drdSdSdv(const double params[]) const { return(dSdSdrdv(params)); }
		virtual double drdSdSdT(const double params[]) const { return(dSdSdrdT(params)); }
		virtual double drdSdr(const double params[]) const { return(dSdrdr(params)); }
		virtual double drdSdrdS(const double params[]) const { return(dSdSdrdr(params)); }
		virtual double drdSdrdr(const double params[]) const { return(dSdrdrdr(params)); }
		virtual double drdSdrdv(const double params[]) const { return(dSdrdrdv(params)); }
		virtual double drdSdrdT(const double params[]) const { return(dSdrdrdT(params)); }
		virtual double drdSdv(const double params[]) const { return(dSdrdv(params)); }
		virtual double drdSdvdS(const double params[]) const { return(dSdSdrdv(params)); }
		virtual double drdSdvdr(const double params[]) const { return(dSdrdrdv(params)); }
		virtual double drdSdvdv(const double params[]) const { return(dSdrdvdv(params)); }
		virtual double drdSdvdT(const double params[]) const { return(dSdrdvdT(params)); }
		virtual double drdSdT(const double params[]) const { return(dSdrdT(params)); }
		virtual double drdSdTdS(const double params[]) const { return(dSdSdrdT(params)); }
		virtual double drdSdTdr(const double params[]) const { return(dSdrdrdT(params)); }
		virtual double drdSdTdv(const double params[]) const { return(dSdrdvdT(params)); }
		virtual double drdSdTdT(const double params[]) const { return(dSdrdTdT(params)); }
		virtual double drdr(const double params[]) const;
		virtual double drdrdS(const double params[]) const { return(dSdrdr(params)); }
		virtual double drdrdSdS(const double params[]) const { return(dSdSdrdr(params)); }
		virtual double drdrdSdr(const double params[]) const { return(dSdrdrdr(params)); }
		virtual double drdrdSdv(const double params[]) const { return(dSdrdrdv(params)); }
		virtual double drdrdSdT(const double params[]) const { return(dSdrdrdT(params)); }
		virtual double drdrdr(const double params[]) const;
		virtual double drdrdrdS(const double params[]) const { return(dSdrdrdr(params)); }
		virtual double drdrdrdr(const double params[]) const;
		virtual double drdrdrdv(const double params[]) const;
		virtual double drdrdrdT(const double params[]) const;
		virtual double drdrdv(const double params[]) const;
		virtual double drdrdvdS(const double params[]) const { return(dSdrdrdv(params)); }
		virtual double drdrdvdr(const double params[]) const { return(drdrdrdv(params)); }
		virtual double drdrdvdv(const double params[]) const;
		virtual double drdrdvdT(const double params[]) const;
		virtual double drdrdT(const double params[]) const;
		virtual double drdrdTdS(const double params[]) const { return(dSdrdrdT(params)); }
		virtual double drdrdTdr(const double params[]) const { return(drdrdrdT(params)); }
		virtual double drdrdTdv(const double params[]) const { return(drdrdvdT(params)); }
		virtual double drdrdTdT(const double params[]) const;
		virtual double drdv(const double params[]) const;
		virtual double drdvdS(const double params[]) const { return(dSdrdv(params)); }
		virtual double drdvdSdS(const double params[]) const { return(dSdSdrdv(params)); }
		virtual double drdvdSdr(const double params[]) const { return(dSdrdrdv(params)); }
		virtual double drdvdSdv(const double params[]) const { return(dSdrdvdv(params)); }
		virtual double drdvdSdT(const double params[]) const { return(dSdrdvdT(params)); }
		virtual double drdvdr(const double params[]) const { return(drdrdv(params)); }
		virtual double drdvdrdS(const double params[]) const { return(dSdrdrdv(params)); }
		virtual double drdvdrdr(const double params[]) const { return(drdrdrdv(params)); }
		virtual double drdvdrdv(const double params[]) const { return(drdrdvdv(params)); }
		virtual double drdvdrdT(const double params[]) const { return(drdrdvdT(params)); }
		virtual double drdvdv(const double params[]) const;
		virtual double drdvdvdS(const double params[]) const { return(dSdrdvdv(params)); }
		virtual double drdvdvdr(const double params[]) const { return(drdrdvdv(params)); }
		virtual double drdvdvdv(const double params[]) const;
		virtual double drdvdvdT(const double params[]) const;
		virtual double drdvdT(const double params[]) const;
		virtual double drdvdTdS(const double params[]) const { return(dSdrdvdT(params)); }
		virtual double drdvdTdr(const double params[]) const { return(drdrdvdT(params)); }
		virtual double drdvdTdv(const double params[]) const { return(drdvdvdT(params)); }
		virtual double drdvdTdT(const double params[]) const;
		virtual double drdT(const double params[]) const;
		virtual double drdTdS(const double params[]) const { return(dSdrdT(params)); }
		virtual double drdTdSdS(const double params[]) const { return(dSdSdrdT(params)); }
		virtual double drdTdSdr(const double params[]) const { return(dSdrdrdT(params)); }
		virtual double drdTdSdv(const double params[]) const { return(dSdrdvdT(params)); }
		virtual double drdTdSdT(const double params[]) const { return(dSdrdTdT(params)); }
		virtual double drdTdr(const double params[]) const { return(drdrdT(params)); }
		virtual double drdTdrdS(const double params[]) const { return(dSdrdrdT(params)); }
		virtual double drdTdrdr(const double params[]) const { return(drdrdrdT(params)); }
		virtual double drdTdrdv(const double params[]) const { return(drdrdvdT(params)); }
		virtual double drdTdrdT(const double params[]) const { return(drdrdTdT(params)); }
		virtual double drdTdv(const double params[]) const { return(drdvdT(params)); }
		virtual double drdTdvdS(const double params[]) const { return(dSdrdvdT(params)); }
		virtual double drdTdvdr(const double params[]) const { return(drdrdvdT(params)); }
		virtual double drdTdvdv(const double params[]) const { return(drdvdvdT(params)); }
		virtual double drdTdvdT(const double params[]) const { return(drdvdTdT(params)); }
		virtual double drdTdT(const double params[]) const;
		virtual double drdTdTdS(const double params[]) const { return(dSdrdTdT(params)); }
		virtual double drdTdTdr(const double params[]) const { return(drdrdTdT(params)); }
		virtual double drdTdTdv(const double params[]) const { return(drdvdTdT(params)); }
		virtual double drdTdTdT(const double params[]) const;
		virtual double dv(const double params[]) const;
		virtual double dvdS(const double params[]) const { return(dSdv(params)); }
		virtual double dvdSdS(const double params[]) const { return(dSdSdv(params)); }
		virtual double dvdSdSdS(const double params[]) const { return(dSdSdSdv(params)); }
		virtual double dvdSdSdr(const double params[]) const { return(dSdSdrdv(params)); }
		virtual double dvdSdSdv(const double params[]) const { return(dSdSdvdv(params)); }
		virtual double dvdSdSdT(const double params[]) const { return(dSdSdvdT(params)); }
		virtual double dvdSdr(const double params[]) const { return(dSdrdv(params)); }
		virtual double dvdSdrdS(const double params[]) const { return(dSdSdrdv(params)); }
		virtual double dvdSdrdr(const double params[]) const { return(dSdrdrdv(params)); }
		virtual double dvdSdrdv(const double params[]) const { return(dSdrdvdv(params)); }
		virtual double dvdSdrdT(const double params[]) const { return(dSdrdvdT(params)); }
		virtual double dvdSdv(const double params[]) const { return(dSdvdv(params)); }
		virtual double dvdSdvdS(const double params[]) const { return(dSdSdvdv(params)); }
		virtual double dvdSdvdr(const double params[]) const { return(dSdrdvdv(params)); }
		virtual double dvdSdvdv(const double params[]) const { return(dSdvdvdv(params)); }
		virtual double dvdSdvdT(const double params[]) const { return(dSdvdvdT(params)); }
		virtual double dvdSdT(const double params[]) const { return(dSdvdT(params)); }
		virtual double dvdSdTdS(const double params[]) const { return(dSdSdvdT(params)); }
		virtual double dvdSdTdr(const double params[]) const { return(dSdrdvdT(params)); }
		virtual double dvdSdTdv(const double params[]) const { return(dSdvdvdT(params)); }
		virtual double dvdSdTdT(const double params[]) const { return(dSdvdTdT(params)); }
		virtual double dvdr(const double params[]) const { return(drdv(params)); }
		virtual double dvdrdS(const double params[]) const { return(dSdrdv(params)); }
		virtual double dvdrdSdS(const double params[]) const { return(dSdSdrdv(params)); }
		virtual double dvdrdSdr(const double params[]) const { return(dSdrdrdv(params)); }
		virtual double dvdrdSdv(const double params[]) const { return(dSdrdvdv(params)); }
		virtual double dvdrdSdT(const double params[]) const { return(dSdrdvdT(params)); }
		virtual double dvdrdr(const double params[]) const { return(drdrdv(params)); }
		virtual double dvdrdrdS(const double params[]) const { return(dSdrdrdv(params)); }
		virtual double dvdrdrdr(const double params[]) const { return(drdrdrdv(params)); }
		virtual double dvdrdrdv(const double params[]) const { return(drdrdvdv(params)); }
		virtual double dvdrdrdT(const double params[]) const { return(drdrdvdT(params)); }
		virtual double dvdrdv(const double params[]) const { return(drdvdv(params)); }
		virtual double dvdrdvdS(const double params[]) const { return(dSdrdvdv(params)); }
		virtual double dvdrdvdr(const double params[]) const { return(drdrdvdv(params)); }
		virtual double dvdrdvdv(const double params[]) const { return(drdvdvdv(params)); }
		virtual double dvdrdvdT(const double params[]) const { return(drdvdvdT(params)); }
		virtual double dvdrdT(const double params[]) const { return(drdvdT(params)); }
		virtual double dvdrdTdS(const double params[]) const { return(dSdrdvdT(params)); }
		virtual double dvdrdTdr(const double params[]) const { return(drdrdvdT(params)); }
		virtual double dvdrdTdv(const double params[]) const { return(drdvdvdT(params)); }
		virtual double dvdrdTdT(const double params[]) const { return(drdvdTdT(params)); }
		virtual double dvdv(const double params[]) const;
		virtual double dvdvdS(const double params[]) const { return(dSdvdv(params)); }
		virtual double dvdvdSdS(const double params[]) const { return(dSdSdvdv(params)); }
		virtual double dvdvdSdr(const double params[]) const { return(dSdrdvdv(params)); }
		virtual double dvdvdSdv(const double params[]) const { return(dSdvdvdv(params)); }
		virtual double dvdvdSdT(const double params[]) const { return(dSdvdvdT(params)); }
		virtual double dvdvdr(const double params[]) const { return(drdvdv(params)); }
		virtual double dvdvdrdS(const double params[]) const { return(dSdrdvdv(params)); }
		virtual double dvdvdrdr(const double params[]) const { return(drdrdvdv(params)); }
		virtual double dvdvdrdv(const double params[]) const { return(drdvdvdv(params)); }
		virtual double dvdvdrdT(const double params[]) const { return(drdvdvdT(params)); }
		virtual double dvdvdv(const double params[]) const;
		virtual double dvdvdvdS(const double params[]) const { return(dSdvdvdv(params)); }
		virtual double dvdvdvdr(const double params[]) const { return(drdvdvdv(params)); }
		virtual double dvdvdvdv(const double params[]) const;
		virtual double dvdvdvdT(const double params[]) const;
		virtual double dvdvdT(const double params[]) const;
		virtual double dvdvdTdS(const double params[]) const { return(dSdvdvdT(params)); }
		virtual double dvdvdTdr(const double params[]) const { return(drdvdvdT(params)); }
		virtual double dvdvdTdv(const double params[]) const { return(dvdvdvdT(params)); }
		virtual double dvdvdTdT(const double params[]) const;
		virtual double dvdT(const double params[]) const;
		virtual double dvdTdS(const double params[]) const { return(dSdvdT(params)); }
		virtual double dvdTdSdS(const double params[]) const { return(dSdSdvdT(params)); }
		virtual double dvdTdSdr(const double params[]) const { return(dSdrdvdT(params)); }
		virtual double dvdTdSdv(const double params[]) const { return(dSdvdvdT(params)); }
		virtual double dvdTdSdT(const double params[]) const { return(dSdvdTdT(params)); }
		virtual double dvdTdr(const double params[]) const { return(drdvdT(params)); }
		virtual double dvdTdrdS(const double params[]) const { return(dSdrdvdT(params)); }
		virtual double dvdTdrdr(const double params[]) const { return(drdrdvdT(params)); }
		virtual double dvdTdrdv(const double params[]) const { return(drdvdvdT(params)); }
		virtual double dvdTdrdT(const double params[]) const { return(drdvdTdT(params)); }
		virtual double dvdTdv(const double params[]) const { return(dvdvdT(params)); }
		virtual double dvdTdvdS(const double params[]) const { return(dSdvdvdT(params)); }
		virtual double dvdTdvdr(const double params[]) const { return(drdvdvdT(params)); }
		virtual double dvdTdvdv(const double params[]) const { return(dvdvdvdT(params)); }
		virtual double dvdTdvdT(const double params[]) const { return(dvdvdTdT(params)); }
		virtual double dvdTdT(const double params[]) const;
		virtual double dvdTdTdS(const double params[]) const { return(dSdvdTdT(params)); }
		virtual double dvdTdTdr(const double params[]) const { return(drdvdTdT(params)); }
		virtual double dvdTdTdv(const double params[]) const { return(dvdvdTdT(params)); }
		virtual double dvdTdTdT(const double params[]) const;
		virtual double dT(const double params[]) const;
		virtual double dTdS(const double params[]) const { return(dSdT(params)); }
		virtual double dTdSdS(const double params[]) const { return(dSdSdT(params)); }
		virtual double dTdSdSdS(const double params[]) const { return(dSdSdSdT(params)); }
		virtual double dTdSdSdr(const double params[]) const { return(dSdSdrdT(params)); }
		virtual double dTdSdSdv(const double params[]) const { return(dSdSdvdT(params)); }
		virtual double dTdSdSdT(const double params[]) const { return(dSdSdTdT(params)); }
		virtual double dTdSdr(const double params[]) const { return(dSdrdT(params)); }
		virtual double dTdSdrdS(const double params[]) const { return(dSdSdrdT(params)); }
		virtual double dTdSdrdr(const double params[]) const { return(dSdrdrdT(params)); }
		virtual double dTdSdrdv(const double params[]) const { return(dSdrdvdT(params)); }
		virtual double dTdSdrdT(const double params[]) const { return(dSdrdTdT(params)); }
		virtual double dTdSdv(const double params[]) const { return(dSdvdT(params)); }
		virtual double dTdSdvdS(const double params[]) const { return(dSdSdvdT(params)); }
		virtual double dTdSdvdr(const double params[]) const { return(dSdrdvdT(params)); }
		virtual double dTdSdvdv(const double params[]) const { return(dSdvdvdT(params)); }
		virtual double dTdSdvdT(const double params[]) const { return(dSdvdTdT(params)); }
		virtual double dTdSdT(const double params[]) const { return(dSdTdT(params)); }
		virtual double dTdSdTdS(const double params[]) const { return(dSdSdTdT(params)); }
		virtual double dTdSdTdr(const double params[]) const { return(dSdrdTdT(params)); }
		virtual double dTdSdTdv(const double params[]) const { return(dSdvdTdT(params)); }
		virtual double dTdSdTdT(const double params[]) const { return(dSdTdTdT(params)); }
		virtual double dTdr(const double params[]) const { return(drdT(params)); }
		virtual double dTdrdS(const double params[]) const { return(dSdrdT(params)); }
		virtual double dTdrdSdS(const double params[]) const { return(dSdSdrdT(params)); }
		virtual double dTdrdSdr(const double params[]) const { return(dSdrdrdT(params)); }
		virtual double dTdrdSdv(const double params[]) const { return(dSdrdvdT(params)); }
		virtual double dTdrdSdT(const double params[]) const { return(dSdrdTdT(params)); }
		virtual double dTdrdr(const double params[]) const { return(drdrdT(params)); }
		virtual double dTdrdrdS(const double params[]) const { return(dSdrdrdT(params)); }
		virtual double dTdrdrdr(const double params[]) const { return(drdrdrdT(params)); }
		virtual double dTdrdrdv(const double params[]) const { return(drdrdvdT(params)); }
		virtual double dTdrdrdT(const double params[]) const { return(drdrdTdT(params)); }
		virtual double dTdrdv(const double params[]) const { return(drdvdT(params)); }
		virtual double dTdrdvdS(const double params[]) const { return(dSdrdvdT(params)); }
		virtual double dTdrdvdr(const double params[]) const { return(drdrdvdT(params)); }
		virtual double dTdrdvdv(const double params[]) const { return(drdvdvdT(params)); }
		virtual double dTdrdvdT(const double params[]) const { return(drdvdTdT(params)); }
		virtual double dTdrdT(const double params[]) const { return(drdTdT(params)); }
		virtual double dTdrdTdS(const double params[]) const { return(dSdrdTdT(params)); }
		virtual double dTdrdTdr(const double params[]) const { return(drdrdTdT(params)); }
		virtual double dTdrdTdv(const double params[]) const { return(drdvdTdT(params)); }
		virtual double dTdrdTdT(const double params[]) const { return(drdTdTdT(params)); }
		virtual double dTdv(const double params[]) const { return(dvdT(params)); }
		virtual double dTdvdS(const double params[]) const { return(dSdvdT(params)); }
		virtual double dTdvdSdS(const double params[]) const { return(dSdSdvdT(params)); }
		virtual double dTdvdSdr(const double params[]) const { return(dSdrdvdT(params)); }
		virtual double dTdvdSdv(const double params[]) const { return(dSdvdvdT(params)); }
		virtual double dTdvdSdT(const double params[]) const { return(dSdvdTdT(params)); }
		virtual double dTdvdr(const double params[]) const { return(drdvdT(params)); }
		virtual double dTdvdrdS(const double params[]) const { return(dSdrdvdT(params)); }
		virtual double dTdvdrdr(const double params[]) const { return(drdrdvdT(params)); }
		virtual double dTdvdrdv(const double params[]) const { return(drdvdvdT(params)); }
		virtual double dTdvdrdT(const double params[]) const { return(drdvdTdT(params)); }
		virtual double dTdvdv(const double params[]) const { return(dvdvdT(params)); }
		virtual double dTdvdvdS(const double params[]) const { return(dSdvdvdT(params)); }
		virtual double dTdvdvdr(const double params[]) const { return(drdvdvdT(params)); }
		virtual double dTdvdvdv(const double params[]) const { return(dvdvdvdT(params)); }
		virtual double dTdvdvdT(const double params[]) const { return(dvdvdTdT(params)); }
		virtual double dTdvdT(const double params[]) const { return(dvdTdT(params)); }
		virtual double dTdvdTdS(const double params[]) const { return(dSdvdTdT(params)); }
		virtual double dTdvdTdr(const double params[]) const { return(drdvdTdT(params)); }
		virtual double dTdvdTdv(const double params[]) const { return(dvdvdTdT(params)); }
		virtual double dTdvdTdT(const double params[]) const { return(dvdTdTdT(params)); }
		virtual double dTdT(const double params[]) const;
		virtual double dTdTdS(const double params[]) const { return(dSdTdT(params)); }
		virtual double dTdTdSdS(const double params[]) const { return(dSdSdTdT(params)); }
		virtual double dTdTdSdr(const double params[]) const { return(dSdrdTdT(params)); }
		virtual double dTdTdSdv(const double params[]) const { return(dSdvdTdT(params)); }
		virtual double dTdTdSdT(const double params[]) const { return(dSdTdTdT(params)); }
		virtual double dTdTdr(const double params[]) const { return(drdTdT(params)); }
		virtual double dTdTdrdS(const double params[]) const { return(dSdrdTdT(params)); }
		virtual double dTdTdrdr(const double params[]) const { return(drdrdTdT(params)); }
		virtual double dTdTdrdv(const double params[]) const { return(drdvdTdT(params)); }
		virtual double dTdTdrdT(const double params[]) const { return(drdTdTdT(params)); }
		virtual double dTdTdv(const double params[]) const { return(dvdTdT(params)); }
		virtual double dTdTdvdS(const double params[]) const { return(dSdvdTdT(params)); }
		virtual double dTdTdvdr(const double params[]) const { return(drdvdTdT(params)); }
		virtual double dTdTdvdv(const double params[]) const { return(dvdvdTdT(params)); }
		virtual double dTdTdvdT(const double params[]) const { return(dvdTdTdT(params)); }
		virtual double dTdTdT(const double params[]) const;
		virtual double dTdTdTdS(const double params[]) const { return(dSdTdTdT(params)); }
		virtual double dTdTdTdr(const double params[]) const { return(drdTdTdT(params)); }
		virtual double dTdTdTdv(const double params[]) const { return(dvdTdTdT(params)); }
		virtual double dTdTdTdT(const double params[]) const;
		virtual double RdS(const double params[]) const;
		virtual double RdSdS(const double params[]) const;
		virtual double RdSdSdS(const double params[]) const;
		virtual double RdSdSdSdS(const double params[]) const;
		virtual double RdSdSdSdr(const double params[]) const;
		virtual double RdSdSdSdv(const double params[]) const;
		virtual double RdSdSdSdT(const double params[]) const;
		virtual double RdSdSdr(const double params[]) const;
		virtual double RdSdSdrdS(const double params[]) const { return(RdSdSdSdr(params)); }
		virtual double RdSdSdrdr(const double params[]) const;
		virtual double RdSdSdrdv(const double params[]) const;
		virtual double RdSdSdrdT(const double params[]) const;
		virtual double RdSdSdv(const double params[]) const;
		virtual double RdSdSdvdS(const double params[]) const { return(RdSdSdSdv(params)); }
		virtual double RdSdSdvdr(const double params[]) const { return(RdSdSdrdv(params)); }
		virtual double RdSdSdvdv(const double params[]) const;
		virtual double RdSdSdvdT(const double params[]) const;
		virtual double RdSdSdT(const double params[]) const;
		virtual double RdSdSdTdS(const double params[]) const { return(RdSdSdSdT(params)); }
		virtual double RdSdSdTdr(const double params[]) const { return(RdSdSdrdT(params)); }
		virtual double RdSdSdTdv(const double params[]) const { return(RdSdSdvdT(params)); }
		virtual double RdSdSdTdT(const double params[]) const;
		virtual double RdSdr(const double params[]) const;
		virtual double RdSdrdS(const double params[]) const { return(RdSdSdr(params)); }
		virtual double RdSdrdSdS(const double params[]) const { return(RdSdSdSdr(params)); }
		virtual double RdSdrdSdr(const double params[]) const { return(RdSdSdrdr(params)); }
		virtual double RdSdrdSdv(const double params[]) const { return(RdSdSdrdv(params)); }
		virtual double RdSdrdSdT(const double params[]) const { return(RdSdSdrdT(params)); }
		virtual double RdSdrdr(const double params[]) const;
		virtual double RdSdrdrdS(const double params[]) const { return(RdSdSdrdr(params)); }
		virtual double RdSdrdrdr(const double params[]) const;
		virtual double RdSdrdrdv(const double params[]) const;
		virtual double RdSdrdrdT(const double params[]) const;
		virtual double RdSdrdv(const double params[]) const;
		virtual double RdSdrdvdS(const double params[]) const { return(RdSdSdrdv(params)); }
		virtual double RdSdrdvdr(const double params[]) const { return(RdSdrdrdv(params)); }
		virtual double RdSdrdvdv(const double params[]) const;
		virtual double RdSdrdvdT(const double params[]) const;
		virtual double RdSdrdT(const double params[]) const;
		virtual double RdSdrdTdS(const double params[]) const { return(RdSdSdrdT(params)); }
		virtual double RdSdrdTdr(const double params[]) const { return(RdSdrdrdT(params)); }
		virtual double RdSdrdTdv(const double params[]) const { return(RdSdrdvdT(params)); }
		virtual double RdSdrdTdT(const double params[]) const;
		virtual double RdSdv(const double params[]) const;
		virtual double RdSdvdS(const double params[]) const { return(RdSdSdv(params)); }
		virtual double RdSdvdSdS(const double params[]) const { return(RdSdSdSdv(params)); }
		virtual double RdSdvdSdr(const double params[]) const { return(RdSdSdrdv(params)); }
		virtual double RdSdvdSdv(const double params[]) const { return(RdSdSdvdv(params)); }
		virtual double RdSdvdSdT(const double params[]) const { return(RdSdSdvdT(params)); }
		virtual double RdSdvdr(const double params[]) const { return(RdSdrdv(params)); }
		virtual double RdSdvdrdS(const double params[]) const { return(RdSdSdrdv(params)); }
		virtual double RdSdvdrdr(const double params[]) const { return(RdSdrdrdv(params)); }
		virtual double RdSdvdrdv(const double params[]) const { return(RdSdrdvdv(params)); }
		virtual double RdSdvdrdT(const double params[]) const { return(RdSdrdvdT(params)); }
		virtual double RdSdvdv(const double params[]) const;
		virtual double RdSdvdvdS(const double params[]) const { return(RdSdSdvdv(params)); }
		virtual double RdSdvdvdr(const double params[]) const { return(RdSdrdvdv(params)); }
		virtual double RdSdvdvdv(const double params[]) const;
		virtual double RdSdvdvdT(const double params[]) const;
		virtual double RdSdvdT(const double params[]) const;
		virtual double RdSdvdTdS(const double params[]) const { return(RdSdSdvdT(params)); }
		virtual double RdSdvdTdr(const double params[]) const { return(RdSdrdvdT(params)); }
		virtual double RdSdvdTdv(const double params[]) const { return(RdSdvdvdT(params)); }
		virtual double RdSdvdTdT(const double params[]) const;
		virtual double RdSdT(const double params[]) const;
		virtual double RdSdTdS(const double params[]) const { return(RdSdSdT(params)); }
		virtual double RdSdTdSdS(const double params[]) const { return(RdSdSdSdT(params)); }
		virtual double RdSdTdSdr(const double params[]) const { return(RdSdSdrdT(params)); }
		virtual double RdSdTdSdv(const double params[]) const { return(RdSdSdvdT(params)); }
		virtual double RdSdTdSdT(const double params[]) const { return(RdSdSdTdT(params)); }
		virtual double RdSdTdr(const double params[]) const { return(RdSdrdT(params)); }
		virtual double RdSdTdrdS(const double params[]) const { return(RdSdSdrdT(params)); }
		virtual double RdSdTdrdr(const double params[]) const { return(RdSdrdrdT(params)); }
		virtual double RdSdTdrdv(const double params[]) const { return(RdSdrdvdT(params)); }
		virtual double RdSdTdrdT(const double params[]) const { return(RdSdrdTdT(params)); }
		virtual double RdSdTdv(const double params[]) const { return(RdSdvdT(params)); }
		virtual double RdSdTdvdS(const double params[]) const { return(RdSdSdvdT(params)); }
		virtual double RdSdTdvdr(const double params[]) const { return(RdSdrdvdT(params)); }
		virtual double RdSdTdvdv(const double params[]) const { return(RdSdvdvdT(params)); }
		virtual double RdSdTdvdT(const double params[]) const { return(RdSdvdTdT(params)); }
		virtual double RdSdTdT(const double params[]) const;
		virtual double RdSdTdTdS(const double params[]) const { return(RdSdSdTdT(params)); }
		virtual double RdSdTdTdr(const double params[]) const { return(RdSdrdTdT(params)); }
		virtual double RdSdTdTdv(const double params[]) const { return(RdSdvdTdT(params)); }
		virtual double RdSdTdTdT(const double params[]) const;
		virtual double Rdr(const double params[]) const;
		virtual double RdrdS(const double params[]) const { return(RdSdr(params)); }
		virtual double RdrdSdS(const double params[]) const { return(RdSdSdr(params)); }
		virtual double RdrdSdSdS(const double params[]) const { return(RdSdSdSdr(params)); }
		virtual double RdrdSdSdr(const double params[]) const { return(RdSdSdrdr(params)); }
		virtual double RdrdSdSdv(const double params[]) const { return(RdSdSdrdv(params)); }
		virtual double RdrdSdSdT(const double params[]) const { return(RdSdSdrdT(params)); }
		virtual double RdrdSdr(const double params[]) const { return(RdSdrdr(params)); }
		virtual double RdrdSdrdS(const double params[]) const { return(RdSdSdrdr(params)); }
		virtual double RdrdSdrdr(const double params[]) const { return(RdSdrdrdr(params)); }
		virtual double RdrdSdrdv(const double params[]) const { return(RdSdrdrdv(params)); }
		virtual double RdrdSdrdT(const double params[]) const { return(RdSdrdrdT(params)); }
		virtual double RdrdSdv(const double params[]) const { return(RdSdrdv(params)); }
		virtual double RdrdSdvdS(const double params[]) const { return(RdSdSdrdv(params)); }
		virtual double RdrdSdvdr(const double params[]) const { return(RdSdrdrdv(params)); }
		virtual double RdrdSdvdv(const double params[]) const { return(RdSdrdvdv(params)); }
		virtual double RdrdSdvdT(const double params[]) const { return(RdSdrdvdT(params)); }
		virtual double RdrdSdT(const double params[]) const { return(RdSdrdT(params)); }
		virtual double RdrdSdTdS(const double params[]) const { return(RdSdSdrdT(params)); }
		virtual double RdrdSdTdr(const double params[]) const { return(RdSdrdrdT(params)); }
		virtual double RdrdSdTdv(const double params[]) const { return(RdSdrdvdT(params)); }
		virtual double RdrdSdTdT(const double params[]) const { return(RdSdrdTdT(params)); }
		virtual double Rdrdr(const double params[]) const;
		virtual double RdrdrdS(const double params[]) const { return(RdSdrdr(params)); }
		virtual double RdrdrdSdS(const double params[]) const { return(RdSdSdrdr(params)); }
		virtual double RdrdrdSdr(const double params[]) const { return(RdSdrdrdr(params)); }
		virtual double RdrdrdSdv(const double params[]) const { return(RdSdrdrdv(params)); }
		virtual double RdrdrdSdT(const double params[]) const { return(RdSdrdrdT(params)); }
		virtual double Rdrdrdr(const double params[]) const;
		virtual double RdrdrdrdS(const double params[]) const { return(RdSdrdrdr(params)); }
		virtual double Rdrdrdrdr(const double params[]) const;
		virtual double Rdrdrdrdv(const double params[]) const;
		virtual double RdrdrdrdT(const double params[]) const;
		virtual double Rdrdrdv(const double params[]) const;
		virtual double RdrdrdvdS(const double params[]) const { return(RdSdrdrdv(params)); }
		virtual double Rdrdrdvdr(const double params[]) const { return(Rdrdrdrdv(params)); }
		virtual double Rdrdrdvdv(const double params[]) const;
		virtual double RdrdrdvdT(const double params[]) const;
		virtual double RdrdrdT(const double params[]) const;
		virtual double RdrdrdTdS(const double params[]) const { return(RdSdrdrdT(params)); }
		virtual double RdrdrdTdr(const double params[]) const { return(RdrdrdrdT(params)); }
		virtual double RdrdrdTdv(const double params[]) const { return(RdrdrdvdT(params)); }
		virtual double RdrdrdTdT(const double params[]) const;
		virtual double Rdrdv(const double params[]) const;
		virtual double RdrdvdS(const double params[]) const { return(RdSdrdv(params)); }
		virtual double RdrdvdSdS(const double params[]) const { return(RdSdSdrdv(params)); }
		virtual double RdrdvdSdr(const double params[]) const { return(RdSdrdrdv(params)); }
		virtual double RdrdvdSdv(const double params[]) const { return(RdSdrdvdv(params)); }
		virtual double RdrdvdSdT(const double params[]) const { return(RdSdrdvdT(params)); }
		virtual double Rdrdvdr(const double params[]) const { return(Rdrdrdv(params)); }
		virtual double RdrdvdrdS(const double params[]) const { return(RdSdrdrdv(params)); }
		virtual double Rdrdvdrdr(const double params[]) const { return(Rdrdrdrdv(params)); }
		virtual double Rdrdvdrdv(const double params[]) const { return(Rdrdrdvdv(params)); }
		virtual double RdrdvdrdT(const double params[]) const { return(RdrdrdvdT(params)); }
		virtual double Rdrdvdv(const double params[]) const;
		virtual double RdrdvdvdS(const double params[]) const { return(RdSdrdvdv(params)); }
		virtual double Rdrdvdvdr(const double params[]) const { return(Rdrdrdvdv(params)); }
		virtual double Rdrdvdvdv(const double params[]) const;
		virtual double RdrdvdvdT(const double params[]) const;
		virtual double RdrdvdT(const double params[]) const;
		virtual double RdrdvdTdS(const double params[]) const { return(RdSdrdvdT(params)); }
		virtual double RdrdvdTdr(const double params[]) const { return(RdrdrdvdT(params)); }
		virtual double RdrdvdTdv(const double params[]) const { return(RdrdvdvdT(params)); }
		virtual double RdrdvdTdT(const double params[]) const;
		virtual double RdrdT(const double params[]) const;
		virtual double RdrdTdS(const double params[]) const { return(RdSdrdT(params)); }
		virtual double RdrdTdSdS(const double params[]) const { return(RdSdSdrdT(params)); }
		virtual double RdrdTdSdr(const double params[]) const { return(RdSdrdrdT(params)); }
		virtual double RdrdTdSdv(const double params[]) const { return(RdSdrdvdT(params)); }
		virtual double RdrdTdSdT(const double params[]) const { return(RdSdrdTdT(params)); }
		virtual double RdrdTdr(const double params[]) const { return(RdrdrdT(params)); }
		virtual double RdrdTdrdS(const double params[]) const { return(RdSdrdrdT(params)); }
		virtual double RdrdTdrdr(const double params[]) const { return(RdrdrdrdT(params)); }
		virtual double RdrdTdrdv(const double params[]) const { return(RdrdrdvdT(params)); }
		virtual double RdrdTdrdT(const double params[]) const { return(RdrdrdTdT(params)); }
		virtual double RdrdTdv(const double params[]) const { return(RdrdvdT(params)); }
		virtual double RdrdTdvdS(const double params[]) const { return(RdSdrdvdT(params)); }
		virtual double RdrdTdvdr(const double params[]) const { return(RdrdrdvdT(params)); }
		virtual double RdrdTdvdv(const double params[]) const { return(RdrdvdvdT(params)); }
		virtual double RdrdTdvdT(const double params[]) const { return(RdrdvdTdT(params)); }
		virtual double RdrdTdT(const double params[]) const;
		virtual double RdrdTdTdS(const double params[]) const { return(RdSdrdTdT(params)); }
		virtual double RdrdTdTdr(const double params[]) const { return(RdrdrdTdT(params)); }
		virtual double RdrdTdTdv(const double params[]) const { return(RdrdvdTdT(params)); }
		virtual double RdrdTdTdT(const double params[]) const;
		virtual double Rdv(const double params[]) const;
		virtual double RdvdS(const double params[]) const { return(RdSdv(params)); }
		virtual double RdvdSdS(const double params[]) const { return(RdSdSdv(params)); }
		virtual double RdvdSdSdS(const double params[]) const { return(RdSdSdSdv(params)); }
		virtual double RdvdSdSdr(const double params[]) const { return(RdSdSdrdv(params)); }
		virtual double RdvdSdSdv(const double params[]) const { return(RdSdSdvdv(params)); }
		virtual double RdvdSdSdT(const double params[]) const { return(RdSdSdvdT(params)); }
		virtual double RdvdSdr(const double params[]) const { return(RdSdrdv(params)); }
		virtual double RdvdSdrdS(const double params[]) const { return(RdSdSdrdv(params)); }
		virtual double RdvdSdrdr(const double params[]) const { return(RdSdrdrdv(params)); }
		virtual double RdvdSdrdv(const double params[]) const { return(RdSdrdvdv(params)); }
		virtual double RdvdSdrdT(const double params[]) const { return(RdSdrdvdT(params)); }
		virtual double RdvdSdv(const double params[]) const { return(RdSdvdv(params)); }
		virtual double RdvdSdvdS(const double params[]) const { return(RdSdSdvdv(params)); }
		virtual double RdvdSdvdr(const double params[]) const { return(RdSdrdvdv(params)); }
		virtual double RdvdSdvdv(const double params[]) const { return(RdSdvdvdv(params)); }
		virtual double RdvdSdvdT(const double params[]) const { return(RdSdvdvdT(params)); }
		virtual double RdvdSdT(const double params[]) const { return(RdSdvdT(params)); }
		virtual double RdvdSdTdS(const double params[]) const { return(RdSdSdvdT(params)); }
		virtual double RdvdSdTdr(const double params[]) const { return(RdSdrdvdT(params)); }
		virtual double RdvdSdTdv(const double params[]) const { return(RdSdvdvdT(params)); }
		virtual double RdvdSdTdT(const double params[]) const { return(RdSdvdTdT(params)); }
		virtual double Rdvdr(const double params[]) const { return(Rdrdv(params)); }
		virtual double RdvdrdS(const double params[]) const { return(RdSdrdv(params)); }
		virtual double RdvdrdSdS(const double params[]) const { return(RdSdSdrdv(params)); }
		virtual double RdvdrdSdr(const double params[]) const { return(RdSdrdrdv(params)); }
		virtual double RdvdrdSdv(const double params[]) const { return(RdSdrdvdv(params)); }
		virtual double RdvdrdSdT(const double params[]) const { return(RdSdrdvdT(params)); }
		virtual double Rdvdrdr(const double params[]) const { return(Rdrdrdv(params)); }
		virtual double RdvdrdrdS(const double params[]) const { return(RdSdrdrdv(params)); }
		virtual double Rdvdrdrdr(const double params[]) const { return(Rdrdrdrdv(params)); }
		virtual double Rdvdrdrdv(const double params[]) const { return(Rdrdrdvdv(params)); }
		virtual double RdvdrdrdT(const double params[]) const { return(RdrdrdvdT(params)); }
		virtual double Rdvdrdv(const double params[]) const { return(Rdrdvdv(params)); }
		virtual double RdvdrdvdS(const double params[]) const { return(RdSdrdvdv(params)); }
		virtual double Rdvdrdvdr(const double params[]) const { return(Rdrdrdvdv(params)); }
		virtual double Rdvdrdvdv(const double params[]) const { return(Rdrdvdvdv(params)); }
		virtual double RdvdrdvdT(const double params[]) const { return(RdrdvdvdT(params)); }
		virtual double RdvdrdT(const double params[]) const { return(RdrdvdT(params)); }
		virtual double RdvdrdTdS(const double params[]) const { return(RdSdrdvdT(params)); }
		virtual double RdvdrdTdr(const double params[]) const { return(RdrdrdvdT(params)); }
		virtual double RdvdrdTdv(const double params[]) const { return(RdrdvdvdT(params)); }
		virtual double RdvdrdTdT(const double params[]) const { return(RdrdvdTdT(params)); }
		virtual double Rdvdv(const double params[]) const;
		virtual double RdvdvdS(const double params[]) const { return(RdSdvdv(params)); }
		virtual double RdvdvdSdS(const double params[]) const { return(RdSdSdvdv(params)); }
		virtual double RdvdvdSdr(const double params[]) const { return(RdSdrdvdv(params)); }
		virtual double RdvdvdSdv(const double params[]) const { return(RdSdvdvdv(params)); }
		virtual double RdvdvdSdT(const double params[]) const { return(RdSdvdvdT(params)); }
		virtual double Rdvdvdr(const double params[]) const { return(Rdrdvdv(params)); }
		virtual double RdvdvdrdS(const double params[]) const { return(RdSdrdvdv(params)); }
		virtual double Rdvdvdrdr(const double params[]) const { return(Rdrdrdvdv(params)); }
		virtual double Rdvdvdrdv(const double params[]) const { return(Rdrdvdvdv(params)); }
		virtual double RdvdvdrdT(const double params[]) const { return(RdrdvdvdT(params)); }
		virtual double Rdvdvdv(const double params[]) const;
		virtual double RdvdvdvdS(const double params[]) const { return(RdSdvdvdv(params)); }
		virtual double Rdvdvdvdr(const double params[]) const { return(Rdrdvdvdv(params)); }
		virtual double Rdvdvdvdv(const double params[]) const;
		virtual double RdvdvdvdT(const double params[]) const;
		virtual double RdvdvdT(const double params[]) const;
		virtual double RdvdvdTdS(const double params[]) const { return(RdSdvdvdT(params)); }
		virtual double RdvdvdTdr(const double params[]) const { return(RdrdvdvdT(params)); }
		virtual double RdvdvdTdv(const double params[]) const { return(RdvdvdvdT(params)); }
		virtual double RdvdvdTdT(const double params[]) const;
		virtual double RdvdT(const double params[]) const;
		virtual double RdvdTdS(const double params[]) const { return(RdSdvdT(params)); }
		virtual double RdvdTdSdS(const double params[]) const { return(RdSdSdvdT(params)); }
		virtual double RdvdTdSdr(const double params[]) const { return(RdSdrdvdT(params)); }
		virtual double RdvdTdSdv(const double params[]) const { return(RdSdvdvdT(params)); }
		virtual double RdvdTdSdT(const double params[]) const { return(RdSdvdTdT(params)); }
		virtual double RdvdTdr(const double params[]) const { return(RdrdvdT(params)); }
		virtual double RdvdTdrdS(const double params[]) const { return(RdSdrdvdT(params)); }
		virtual double RdvdTdrdr(const double params[]) const { return(RdrdrdvdT(params)); }
		virtual double RdvdTdrdv(const double params[]) const { return(RdrdvdvdT(params)); }
		virtual double RdvdTdrdT(const double params[]) const { return(RdrdvdTdT(params)); }
		virtual double RdvdTdv(const double params[]) const { return(RdvdvdT(params)); }
		virtual double RdvdTdvdS(const double params[]) const { return(RdSdvdvdT(params)); }
		virtual double RdvdTdvdr(const double params[]) const { return(RdrdvdvdT(params)); }
		virtual double RdvdTdvdv(const double params[]) const { return(RdvdvdvdT(params)); }
		virtual double RdvdTdvdT(const double params[]) const { return(RdvdvdTdT(params)); }
		virtual double RdvdTdT(const double params[]) const;
		virtual double RdvdTdTdS(const double params[]) const { return(RdSdvdTdT(params)); }
		virtual double RdvdTdTdr(const double params[]) const { return(RdrdvdTdT(params)); }
		virtual double RdvdTdTdv(const double params[]) const { return(RdvdvdTdT(params)); }
		virtual double RdvdTdTdT(const double params[]) const;
		virtual double RdT(const double params[]) const;
		virtual double RdTdS(const double params[]) const { return(RdSdT(params)); }
		virtual double RdTdSdS(const double params[]) const { return(RdSdSdT(params)); }
		virtual double RdTdSdSdS(const double params[]) const { return(RdSdSdSdT(params)); }
		virtual double RdTdSdSdr(const double params[]) const { return(RdSdSdrdT(params)); }
		virtual double RdTdSdSdv(const double params[]) const { return(RdSdSdvdT(params)); }
		virtual double RdTdSdSdT(const double params[]) const { return(RdSdSdTdT(params)); }
		virtual double RdTdSdr(const double params[]) const { return(RdSdrdT(params)); }
		virtual double RdTdSdrdS(const double params[]) const { return(RdSdSdrdT(params)); }
		virtual double RdTdSdrdr(const double params[]) const { return(RdSdrdrdT(params)); }
		virtual double RdTdSdrdv(const double params[]) const { return(RdSdrdvdT(params)); }
		virtual double RdTdSdrdT(const double params[]) const { return(RdSdrdTdT(params)); }
		virtual double RdTdSdv(const double params[]) const { return(RdSdvdT(params)); }
		virtual double RdTdSdvdS(const double params[]) const { return(RdSdSdvdT(params)); }
		virtual double RdTdSdvdr(const double params[]) const { return(RdSdrdvdT(params)); }
		virtual double RdTdSdvdv(const double params[]) const { return(RdSdvdvdT(params)); }
		virtual double RdTdSdvdT(const double params[]) const { return(RdSdvdTdT(params)); }
		virtual double RdTdSdT(const double params[]) const { return(RdSdTdT(params)); }
		virtual double RdTdSdTdS(const double params[]) const { return(RdSdSdTdT(params)); }
		virtual double RdTdSdTdr(const double params[]) const { return(RdSdrdTdT(params)); }
		virtual double RdTdSdTdv(const double params[]) const { return(RdSdvdTdT(params)); }
		virtual double RdTdSdTdT(const double params[]) const { return(RdSdTdTdT(params)); }
		virtual double RdTdr(const double params[]) const { return(RdrdT(params)); }
		virtual double RdTdrdS(const double params[]) const { return(RdSdrdT(params)); }
		virtual double RdTdrdSdS(const double params[]) const { return(RdSdSdrdT(params)); }
		virtual double RdTdrdSdr(const double params[]) const { return(RdSdrdrdT(params)); }
		virtual double RdTdrdSdv(const double params[]) const { return(RdSdrdvdT(params)); }
		virtual double RdTdrdSdT(const double params[]) const { return(RdSdrdTdT(params)); }
		virtual double RdTdrdr(const double params[]) const { return(RdrdrdT(params)); }
		virtual double RdTdrdrdS(const double params[]) const { return(RdSdrdrdT(params)); }
		virtual double RdTdrdrdr(const double params[]) const { return(RdrdrdrdT(params)); }
		virtual double RdTdrdrdv(const double params[]) const { return(RdrdrdvdT(params)); }
		virtual double RdTdrdrdT(const double params[]) const { return(RdrdrdTdT(params)); }
		virtual double RdTdrdv(const double params[]) const { return(RdrdvdT(params)); }
		virtual double RdTdrdvdS(const double params[]) const { return(RdSdrdvdT(params)); }
		virtual double RdTdrdvdr(const double params[]) const { return(RdrdrdvdT(params)); }
		virtual double RdTdrdvdv(const double params[]) const { return(RdrdvdvdT(params)); }
		virtual double RdTdrdvdT(const double params[]) const { return(RdrdvdTdT(params)); }
		virtual double RdTdrdT(const double params[]) const { return(RdrdTdT(params)); }
		virtual double RdTdrdTdS(const double params[]) const { return(RdSdrdTdT(params)); }
		virtual double RdTdrdTdr(const double params[]) const { return(RdrdrdTdT(params)); }
		virtual double RdTdrdTdv(const double params[]) const { return(RdrdvdTdT(params)); }
		virtual double RdTdrdTdT(const double params[]) const { return(RdrdTdTdT(params)); }
		virtual double RdTdv(const double params[]) const { return(RdvdT(params)); }
		virtual double RdTdvdS(const double params[]) const { return(RdSdvdT(params)); }
		virtual double RdTdvdSdS(const double params[]) const { return(RdSdSdvdT(params)); }
		virtual double RdTdvdSdr(const double params[]) const { return(RdSdrdvdT(params)); }
		virtual double RdTdvdSdv(const double params[]) const { return(RdSdvdvdT(params)); }
		virtual double RdTdvdSdT(const double params[]) const { return(RdSdvdTdT(params)); }
		virtual double RdTdvdr(const double params[]) const { return(RdrdvdT(params)); }
		virtual double RdTdvdrdS(const double params[]) const { return(RdSdrdvdT(params)); }
		virtual double RdTdvdrdr(const double params[]) const { return(RdrdrdvdT(params)); }
		virtual double RdTdvdrdv(const double params[]) const { return(RdrdvdvdT(params)); }
		virtual double RdTdvdrdT(const double params[]) const { return(RdrdvdTdT(params)); }
		virtual double RdTdvdv(const double params[]) const { return(RdvdvdT(params)); }
		virtual double RdTdvdvdS(const double params[]) const { return(RdSdvdvdT(params)); }
		virtual double RdTdvdvdr(const double params[]) const { return(RdrdvdvdT(params)); }
		virtual double RdTdvdvdv(const double params[]) const { return(RdvdvdvdT(params)); }
		virtual double RdTdvdvdT(const double params[]) const { return(RdvdvdTdT(params)); }
		virtual double RdTdvdT(const double params[]) const { return(RdvdTdT(params)); }
		virtual double RdTdvdTdS(const double params[]) const { return(RdSdvdTdT(params)); }
		virtual double RdTdvdTdr(const double params[]) const { return(RdrdvdTdT(params)); }
		virtual double RdTdvdTdv(const double params[]) const { return(RdvdvdTdT(params)); }
		virtual double RdTdvdTdT(const double params[]) const { return(RdvdTdTdT(params)); }
		virtual double RdTdT(const double params[]) const;
		virtual double RdTdTdS(const double params[]) const { return(RdSdTdT(params)); }
		virtual double RdTdTdSdS(const double params[]) const { return(RdSdSdTdT(params)); }
		virtual double RdTdTdSdr(const double params[]) const { return(RdSdrdTdT(params)); }
		virtual double RdTdTdSdv(const double params[]) const { return(RdSdvdTdT(params)); }
		virtual double RdTdTdSdT(const double params[]) const { return(RdSdTdTdT(params)); }
		virtual double RdTdTdr(const double params[]) const { return(RdrdTdT(params)); }
		virtual double RdTdTdrdS(const double params[]) const { return(RdSdrdTdT(params)); }
		virtual double RdTdTdrdr(const double params[]) const { return(RdrdrdTdT(params)); }
		virtual double RdTdTdrdv(const double params[]) const { return(RdrdvdTdT(params)); }
		virtual double RdTdTdrdT(const double params[]) const { return(RdrdTdTdT(params)); }
		virtual double RdTdTdv(const double params[]) const { return(RdvdTdT(params)); }
		virtual double RdTdTdvdS(const double params[]) const { return(RdSdvdTdT(params)); }
		virtual double RdTdTdvdr(const double params[]) const { return(RdrdvdTdT(params)); }
		virtual double RdTdTdvdv(const double params[]) const { return(RdvdvdTdT(params)); }
		virtual double RdTdTdvdT(const double params[]) const { return(RdvdTdTdT(params)); }
		virtual double RdTdTdT(const double params[]) const;
		virtual double RdTdTdTdS(const double params[]) const { return(RdSdTdTdT(params)); }
		virtual double RdTdTdTdr(const double params[]) const { return(RdrdTdTdT(params)); }
		virtual double RdTdTdTdv(const double params[]) const { return(RdvdTdTdT(params)); }
		virtual double RdTdTdTdT(const double params[]) const;
		virtual double VdS(const double params[]) const;
		virtual double VdSdS(const double params[]) const;
		virtual double VdSdSdS(const double params[]) const;
		virtual double VdSdSdSdS(const double params[]) const;
		virtual double VdSdSdSdr(const double params[]) const;
		virtual double VdSdSdSdv(const double params[]) const;
		virtual double VdSdSdSdT(const double params[]) const;
		virtual double VdSdSdr(const double params[]) const;
		virtual double VdSdSdrdS(const double params[]) const { return(VdSdSdSdr(params)); }
		virtual double VdSdSdrdr(const double params[]) const;
		virtual double VdSdSdrdv(const double params[]) const;
		virtual double VdSdSdrdT(const double params[]) const;
		virtual double VdSdSdv(const double params[]) const;
		virtual double VdSdSdvdS(const double params[]) const { return(VdSdSdSdv(params)); }
		virtual double VdSdSdvdr(const double params[]) const { return(VdSdSdrdv(params)); }
		virtual double VdSdSdvdv(const double params[]) const;
		virtual double VdSdSdvdT(const double params[]) const;
		virtual double VdSdSdT(const double params[]) const;
		virtual double VdSdSdTdS(const double params[]) const { return(VdSdSdSdT(params)); }
		virtual double VdSdSdTdr(const double params[]) const { return(VdSdSdrdT(params)); }
		virtual double VdSdSdTdv(const double params[]) const { return(VdSdSdvdT(params)); }
		virtual double VdSdSdTdT(const double params[]) const;
		virtual double VdSdr(const double params[]) const;
		virtual double VdSdrdS(const double params[]) const { return(VdSdSdr(params)); }
		virtual double VdSdrdSdS(const double params[]) const { return(VdSdSdSdr(params)); }
		virtual double VdSdrdSdr(const double params[]) const { return(VdSdSdrdr(params)); }
		virtual double VdSdrdSdv(const double params[]) const { return(VdSdSdrdv(params)); }
		virtual double VdSdrdSdT(const double params[]) const { return(VdSdSdrdT(params)); }
		virtual double VdSdrdr(const double params[]) const;
		virtual double VdSdrdrdS(const double params[]) const { return(VdSdSdrdr(params)); }
		virtual double VdSdrdrdr(const double params[]) const;
		virtual double VdSdrdrdv(const double params[]) const;
		virtual double VdSdrdrdT(const double params[]) const;
		virtual double VdSdrdv(const double params[]) const;
		virtual double VdSdrdvdS(const double params[]) const { return(VdSdSdrdv(params)); }
		virtual double VdSdrdvdr(const double params[]) const { return(VdSdrdrdv(params)); }
		virtual double VdSdrdvdv(const double params[]) const;
		virtual double VdSdrdvdT(const double params[]) const;
		virtual double VdSdrdT(const double params[]) const;
		virtual double VdSdrdTdS(const double params[]) const { return(VdSdSdrdT(params)); }
		virtual double VdSdrdTdr(const double params[]) const { return(VdSdrdrdT(params)); }
		virtual double VdSdrdTdv(const double params[]) const { return(VdSdrdvdT(params)); }
		virtual double VdSdrdTdT(const double params[]) const;
		virtual double VdSdv(const double params[]) const;
		virtual double VdSdvdS(const double params[]) const { return(VdSdSdv(params)); }
		virtual double VdSdvdSdS(const double params[]) const { return(VdSdSdSdv(params)); }
		virtual double VdSdvdSdr(const double params[]) const { return(VdSdSdrdv(params)); }
		virtual double VdSdvdSdv(const double params[]) const { return(VdSdSdvdv(params)); }
		virtual double VdSdvdSdT(const double params[]) const { return(VdSdSdvdT(params)); }
		virtual double VdSdvdr(const double params[]) const { return(VdSdrdv(params)); }
		virtual double VdSdvdrdS(const double params[]) const { return(VdSdSdrdv(params)); }
		virtual double VdSdvdrdr(const double params[]) const { return(VdSdrdrdv(params)); }
		virtual double VdSdvdrdv(const double params[]) const { return(VdSdrdvdv(params)); }
		virtual double VdSdvdrdT(const double params[]) const { return(VdSdrdvdT(params)); }
		virtual double VdSdvdv(const double params[]) const;
		virtual double VdSdvdvdS(const double params[]) const { return(VdSdSdvdv(params)); }
		virtual double VdSdvdvdr(const double params[]) const { return(VdSdrdvdv(params)); }
		virtual double VdSdvdvdv(const double params[]) const;
		virtual double VdSdvdvdT(const double params[]) const;
		virtual double VdSdvdT(const double params[]) const;
		virtual double VdSdvdTdS(const double params[]) const { return(VdSdSdvdT(params)); }
		virtual double VdSdvdTdr(const double params[]) const { return(VdSdrdvdT(params)); }
		virtual double VdSdvdTdv(const double params[]) const { return(VdSdvdvdT(params)); }
		virtual double VdSdvdTdT(const double params[]) const;
		virtual double VdSdT(const double params[]) const;
		virtual double VdSdTdS(const double params[]) const { return(VdSdSdT(params)); }
		virtual double VdSdTdSdS(const double params[]) const { return(VdSdSdSdT(params)); }
		virtual double VdSdTdSdr(const double params[]) const { return(VdSdSdrdT(params)); }
		virtual double VdSdTdSdv(const double params[]) const { return(VdSdSdvdT(params)); }
		virtual double VdSdTdSdT(const double params[]) const { return(VdSdSdTdT(params)); }
		virtual double VdSdTdr(const double params[]) const { return(VdSdrdT(params)); }
		virtual double VdSdTdrdS(const double params[]) const { return(VdSdSdrdT(params)); }
		virtual double VdSdTdrdr(const double params[]) const { return(VdSdrdrdT(params)); }
		virtual double VdSdTdrdv(const double params[]) const { return(VdSdrdvdT(params)); }
		virtual double VdSdTdrdT(const double params[]) const { return(VdSdrdTdT(params)); }
		virtual double VdSdTdv(const double params[]) const { return(VdSdvdT(params)); }
		virtual double VdSdTdvdS(const double params[]) const { return(VdSdSdvdT(params)); }
		virtual double VdSdTdvdr(const double params[]) const { return(VdSdrdvdT(params)); }
		virtual double VdSdTdvdv(const double params[]) const { return(VdSdvdvdT(params)); }
		virtual double VdSdTdvdT(const double params[]) const { return(VdSdvdTdT(params)); }
		virtual double VdSdTdT(const double params[]) const;
		virtual double VdSdTdTdS(const double params[]) const { return(VdSdSdTdT(params)); }
		virtual double VdSdTdTdr(const double params[]) const { return(VdSdrdTdT(params)); }
		virtual double VdSdTdTdv(const double params[]) const { return(VdSdvdTdT(params)); }
		virtual double VdSdTdTdT(const double params[]) const;
		virtual double Vdr(const double params[]) const;
		virtual double VdrdS(const double params[]) const { return(VdSdr(params)); }
		virtual double VdrdSdS(const double params[]) const { return(VdSdSdr(params)); }
		virtual double VdrdSdSdS(const double params[]) const { return(VdSdSdSdr(params)); }
		virtual double VdrdSdSdr(const double params[]) const { return(VdSdSdrdr(params)); }
		virtual double VdrdSdSdv(const double params[]) const { return(VdSdSdrdv(params)); }
		virtual double VdrdSdSdT(const double params[]) const { return(VdSdSdrdT(params)); }
		virtual double VdrdSdr(const double params[]) const { return(VdSdrdr(params)); }
		virtual double VdrdSdrdS(const double params[]) const { return(VdSdSdrdr(params)); }
		virtual double VdrdSdrdr(const double params[]) const { return(VdSdrdrdr(params)); }
		virtual double VdrdSdrdv(const double params[]) const { return(VdSdrdrdv(params)); }
		virtual double VdrdSdrdT(const double params[]) const { return(VdSdrdrdT(params)); }
		virtual double VdrdSdv(const double params[]) const { return(VdSdrdv(params)); }
		virtual double VdrdSdvdS(const double params[]) const { return(VdSdSdrdv(params)); }
		virtual double VdrdSdvdr(const double params[]) const { return(VdSdrdrdv(params)); }
		virtual double VdrdSdvdv(const double params[]) const { return(VdSdrdvdv(params)); }
		virtual double VdrdSdvdT(const double params[]) const { return(VdSdrdvdT(params)); }
		virtual double VdrdSdT(const double params[]) const { return(VdSdrdT(params)); }
		virtual double VdrdSdTdS(const double params[]) const { return(VdSdSdrdT(params)); }
		virtual double VdrdSdTdr(const double params[]) const { return(VdSdrdrdT(params)); }
		virtual double VdrdSdTdv(const double params[]) const { return(VdSdrdvdT(params)); }
		virtual double VdrdSdTdT(const double params[]) const { return(VdSdrdTdT(params)); }
		virtual double Vdrdr(const double params[]) const;
		virtual double VdrdrdS(const double params[]) const { return(VdSdrdr(params)); }
		virtual double VdrdrdSdS(const double params[]) const { return(VdSdSdrdr(params)); }
		virtual double VdrdrdSdr(const double params[]) const { return(VdSdrdrdr(params)); }
		virtual double VdrdrdSdv(const double params[]) const { return(VdSdrdrdv(params)); }
		virtual double VdrdrdSdT(const double params[]) const { return(VdSdrdrdT(params)); }
		virtual double Vdrdrdr(const double params[]) const;
		virtual double VdrdrdrdS(const double params[]) const { return(VdSdrdrdr(params)); }
		virtual double Vdrdrdrdr(const double params[]) const;
		virtual double Vdrdrdrdv(const double params[]) const;
		virtual double VdrdrdrdT(const double params[]) const;
		virtual double Vdrdrdv(const double params[]) const;
		virtual double VdrdrdvdS(const double params[]) const { return(VdSdrdrdv(params)); }
		virtual double Vdrdrdvdr(const double params[]) const { return(Vdrdrdrdv(params)); }
		virtual double Vdrdrdvdv(const double params[]) const;
		virtual double VdrdrdvdT(const double params[]) const;
		virtual double VdrdrdT(const double params[]) const;
		virtual double VdrdrdTdS(const double params[]) const { return(VdSdrdrdT(params)); }
		virtual double VdrdrdTdr(const double params[]) const { return(VdrdrdrdT(params)); }
		virtual double VdrdrdTdv(const double params[]) const { return(VdrdrdvdT(params)); }
		virtual double VdrdrdTdT(const double params[]) const;
		virtual double Vdrdv(const double params[]) const;
		virtual double VdrdvdS(const double params[]) const { return(VdSdrdv(params)); }
		virtual double VdrdvdSdS(const double params[]) const { return(VdSdSdrdv(params)); }
		virtual double VdrdvdSdr(const double params[]) const { return(VdSdrdrdv(params)); }
		virtual double VdrdvdSdv(const double params[]) const { return(VdSdrdvdv(params)); }
		virtual double VdrdvdSdT(const double params[]) const { return(VdSdrdvdT(params)); }
		virtual double Vdrdvdr(const double params[]) const { return(Vdrdrdv(params)); }
		virtual double VdrdvdrdS(const double params[]) const { return(VdSdrdrdv(params)); }
		virtual double Vdrdvdrdr(const double params[]) const { return(Vdrdrdrdv(params)); }
		virtual double Vdrdvdrdv(const double params[]) const { return(Vdrdrdvdv(params)); }
		virtual double VdrdvdrdT(const double params[]) const { return(VdrdrdvdT(params)); }
		virtual double Vdrdvdv(const double params[]) const;
		virtual double VdrdvdvdS(const double params[]) const { return(VdSdrdvdv(params)); }
		virtual double Vdrdvdvdr(const double params[]) const { return(Vdrdrdvdv(params)); }
		virtual double Vdrdvdvdv(const double params[]) const;
		virtual double VdrdvdvdT(const double params[]) const;
		virtual double VdrdvdT(const double params[]) const;
		virtual double VdrdvdTdS(const double params[]) const { return(VdSdrdvdT(params)); }
		virtual double VdrdvdTdr(const double params[]) const { return(VdrdrdvdT(params)); }
		virtual double VdrdvdTdv(const double params[]) const { return(VdrdvdvdT(params)); }
		virtual double VdrdvdTdT(const double params[]) const;
		virtual double VdrdT(const double params[]) const;
		virtual double VdrdTdS(const double params[]) const { return(VdSdrdT(params)); }
		virtual double VdrdTdSdS(const double params[]) const { return(VdSdSdrdT(params)); }
		virtual double VdrdTdSdr(const double params[]) const { return(VdSdrdrdT(params)); }
		virtual double VdrdTdSdv(const double params[]) const { return(VdSdrdvdT(params)); }
		virtual double VdrdTdSdT(const double params[]) const { return(VdSdrdTdT(params)); }
		virtual double VdrdTdr(const double params[]) const { return(VdrdrdT(params)); }
		virtual double VdrdTdrdS(const double params[]) const { return(VdSdrdrdT(params)); }
		virtual double VdrdTdrdr(const double params[]) const { return(VdrdrdrdT(params)); }
		virtual double VdrdTdrdv(const double params[]) const { return(VdrdrdvdT(params)); }
		virtual double VdrdTdrdT(const double params[]) const { return(VdrdrdTdT(params)); }
		virtual double VdrdTdv(const double params[]) const { return(VdrdvdT(params)); }
		virtual double VdrdTdvdS(const double params[]) const { return(VdSdrdvdT(params)); }
		virtual double VdrdTdvdr(const double params[]) const { return(VdrdrdvdT(params)); }
		virtual double VdrdTdvdv(const double params[]) const { return(VdrdvdvdT(params)); }
		virtual double VdrdTdvdT(const double params[]) const { return(VdrdvdTdT(params)); }
		virtual double VdrdTdT(const double params[]) const;
		virtual double VdrdTdTdS(const double params[]) const { return(VdSdrdTdT(params)); }
		virtual double VdrdTdTdr(const double params[]) const { return(VdrdrdTdT(params)); }
		virtual double VdrdTdTdv(const double params[]) const { return(VdrdvdTdT(params)); }
		virtual double VdrdTdTdT(const double params[]) const;
		virtual double Vdv(const double params[]) const;
		virtual double VdvdS(const double params[]) const { return(VdSdv(params)); }
		virtual double VdvdSdS(const double params[]) const { return(VdSdSdv(params)); }
		virtual double VdvdSdSdS(const double params[]) const { return(VdSdSdSdv(params)); }
		virtual double VdvdSdSdr(const double params[]) const { return(VdSdSdrdv(params)); }
		virtual double VdvdSdSdv(const double params[]) const { return(VdSdSdvdv(params)); }
		virtual double VdvdSdSdT(const double params[]) const { return(VdSdSdvdT(params)); }
		virtual double VdvdSdr(const double params[]) const { return(VdSdrdv(params)); }
		virtual double VdvdSdrdS(const double params[]) const { return(VdSdSdrdv(params)); }
		virtual double VdvdSdrdr(const double params[]) const { return(VdSdrdrdv(params)); }
		virtual double VdvdSdrdv(const double params[]) const { return(VdSdrdvdv(params)); }
		virtual double VdvdSdrdT(const double params[]) const { return(VdSdrdvdT(params)); }
		virtual double VdvdSdv(const double params[]) const { return(VdSdvdv(params)); }
		virtual double VdvdSdvdS(const double params[]) const { return(VdSdSdvdv(params)); }
		virtual double VdvdSdvdr(const double params[]) const { return(VdSdrdvdv(params)); }
		virtual double VdvdSdvdv(const double params[]) const { return(VdSdvdvdv(params)); }
		virtual double VdvdSdvdT(const double params[]) const { return(VdSdvdvdT(params)); }
		virtual double VdvdSdT(const double params[]) const { return(VdSdvdT(params)); }
		virtual double VdvdSdTdS(const double params[]) const { return(VdSdSdvdT(params)); }
		virtual double VdvdSdTdr(const double params[]) const { return(VdSdrdvdT(params)); }
		virtual double VdvdSdTdv(const double params[]) const { return(VdSdvdvdT(params)); }
		virtual double VdvdSdTdT(const double params[]) const { return(VdSdvdTdT(params)); }
		virtual double Vdvdr(const double params[]) const { return(Vdrdv(params)); }
		virtual double VdvdrdS(const double params[]) const { return(VdSdrdv(params)); }
		virtual double VdvdrdSdS(const double params[]) const { return(VdSdSdrdv(params)); }
		virtual double VdvdrdSdr(const double params[]) const { return(VdSdrdrdv(params)); }
		virtual double VdvdrdSdv(const double params[]) const { return(VdSdrdvdv(params)); }
		virtual double VdvdrdSdT(const double params[]) const { return(VdSdrdvdT(params)); }
		virtual double Vdvdrdr(const double params[]) const { return(Vdrdrdv(params)); }
		virtual double VdvdrdrdS(const double params[]) const { return(VdSdrdrdv(params)); }
		virtual double Vdvdrdrdr(const double params[]) const { return(Vdrdrdrdv(params)); }
		virtual double Vdvdrdrdv(const double params[]) const { return(Vdrdrdvdv(params)); }
		virtual double VdvdrdrdT(const double params[]) const { return(VdrdrdvdT(params)); }
		virtual double Vdvdrdv(const double params[]) const { return(Vdrdvdv(params)); }
		virtual double VdvdrdvdS(const double params[]) const { return(VdSdrdvdv(params)); }
		virtual double Vdvdrdvdr(const double params[]) const { return(Vdrdrdvdv(params)); }
		virtual double Vdvdrdvdv(const double params[]) const { return(Vdrdvdvdv(params)); }
		virtual double VdvdrdvdT(const double params[]) const { return(VdrdvdvdT(params)); }
		virtual double VdvdrdT(const double params[]) const { return(VdrdvdT(params)); }
		virtual double VdvdrdTdS(const double params[]) const { return(VdSdrdvdT(params)); }
		virtual double VdvdrdTdr(const double params[]) const { return(VdrdrdvdT(params)); }
		virtual double VdvdrdTdv(const double params[]) const { return(VdrdvdvdT(params)); }
		virtual double VdvdrdTdT(const double params[]) const { return(VdrdvdTdT(params)); }
		virtual double Vdvdv(const double params[]) const;
		virtual double VdvdvdS(const double params[]) const { return(VdSdvdv(params)); }
		virtual double VdvdvdSdS(const double params[]) const { return(VdSdSdvdv(params)); }
		virtual double VdvdvdSdr(const double params[]) const { return(VdSdrdvdv(params)); }
		virtual double VdvdvdSdv(const double params[]) const { return(VdSdvdvdv(params)); }
		virtual double VdvdvdSdT(const double params[]) const { return(VdSdvdvdT(params)); }
		virtual double Vdvdvdr(const double params[]) const { return(Vdrdvdv(params)); }
		virtual double VdvdvdrdS(const double params[]) const { return(VdSdrdvdv(params)); }
		virtual double Vdvdvdrdr(const double params[]) const { return(Vdrdrdvdv(params)); }
		virtual double Vdvdvdrdv(const double params[]) const { return(Vdrdvdvdv(params)); }
		virtual double VdvdvdrdT(const double params[]) const { return(VdrdvdvdT(params)); }
		virtual double Vdvdvdv(const double params[]) const;
		virtual double VdvdvdvdS(const double params[]) const { return(VdSdvdvdv(params)); }
		virtual double Vdvdvdvdr(const double params[]) const { return(Vdrdvdvdv(params)); }
		virtual double Vdvdvdvdv(const double params[]) const;
		virtual double VdvdvdvdT(const double params[]) const;
		virtual double VdvdvdT(const double params[]) const;
		virtual double VdvdvdTdS(const double params[]) const { return(VdSdvdvdT(params)); }
		virtual double VdvdvdTdr(const double params[]) const { return(VdrdvdvdT(params)); }
		virtual double VdvdvdTdv(const double params[]) const { return(VdvdvdvdT(params)); }
		virtual double VdvdvdTdT(const double params[]) const;
		virtual double VdvdT(const double params[]) const;
		virtual double VdvdTdS(const double params[]) const { return(VdSdvdT(params)); }
		virtual double VdvdTdSdS(const double params[]) const { return(VdSdSdvdT(params)); }
		virtual double VdvdTdSdr(const double params[]) const { return(VdSdrdvdT(params)); }
		virtual double VdvdTdSdv(const double params[]) const { return(VdSdvdvdT(params)); }
		virtual double VdvdTdSdT(const double params[]) const { return(VdSdvdTdT(params)); }
		virtual double VdvdTdr(const double params[]) const { return(VdrdvdT(params)); }
		virtual double VdvdTdrdS(const double params[]) const { return(VdSdrdvdT(params)); }
		virtual double VdvdTdrdr(const double params[]) const { return(VdrdrdvdT(params)); }
		virtual double VdvdTdrdv(const double params[]) const { return(VdrdvdvdT(params)); }
		virtual double VdvdTdrdT(const double params[]) const { return(VdrdvdTdT(params)); }
		virtual double VdvdTdv(const double params[]) const { return(VdvdvdT(params)); }
		virtual double VdvdTdvdS(const double params[]) const { return(VdSdvdvdT(params)); }
		virtual double VdvdTdvdr(const double params[]) const { return(VdrdvdvdT(params)); }
		virtual double VdvdTdvdv(const double params[]) const { return(VdvdvdvdT(params)); }
		virtual double VdvdTdvdT(const double params[]) const { return(VdvdvdTdT(params)); }
		virtual double VdvdTdT(const double params[]) const;
		virtual double VdvdTdTdS(const double params[]) const { return(VdSdvdTdT(params)); }
		virtual double VdvdTdTdr(const double params[]) const { return(VdrdvdTdT(params)); }
		virtual double VdvdTdTdv(const double params[]) const { return(VdvdvdTdT(params)); }
		virtual double VdvdTdTdT(const double params[]) const;
		virtual double VdT(const double params[]) const;
		virtual double VdTdS(const double params[]) const { return(VdSdT(params)); }
		virtual double VdTdSdS(const double params[]) const { return(VdSdSdT(params)); }
		virtual double VdTdSdSdS(const double params[]) const { return(VdSdSdSdT(params)); }
		virtual double VdTdSdSdr(const double params[]) const { return(VdSdSdrdT(params)); }
		virtual double VdTdSdSdv(const double params[]) const { return(VdSdSdvdT(params)); }
		virtual double VdTdSdSdT(const double params[]) const { return(VdSdSdTdT(params)); }
		virtual double VdTdSdr(const double params[]) const { return(VdSdrdT(params)); }
		virtual double VdTdSdrdS(const double params[]) const { return(VdSdSdrdT(params)); }
		virtual double VdTdSdrdr(const double params[]) const { return(VdSdrdrdT(params)); }
		virtual double VdTdSdrdv(const double params[]) const { return(VdSdrdvdT(params)); }
		virtual double VdTdSdrdT(const double params[]) const { return(VdSdrdTdT(params)); }
		virtual double VdTdSdv(const double params[]) const { return(VdSdvdT(params)); }
		virtual double VdTdSdvdS(const double params[]) const { return(VdSdSdvdT(params)); }
		virtual double VdTdSdvdr(const double params[]) const { return(VdSdrdvdT(params)); }
		virtual double VdTdSdvdv(const double params[]) const { return(VdSdvdvdT(params)); }
		virtual double VdTdSdvdT(const double params[]) const { return(VdSdvdTdT(params)); }
		virtual double VdTdSdT(const double params[]) const { return(VdSdTdT(params)); }
		virtual double VdTdSdTdS(const double params[]) const { return(VdSdSdTdT(params)); }
		virtual double VdTdSdTdr(const double params[]) const { return(VdSdrdTdT(params)); }
		virtual double VdTdSdTdv(const double params[]) const { return(VdSdvdTdT(params)); }
		virtual double VdTdSdTdT(const double params[]) const { return(VdSdTdTdT(params)); }
		virtual double VdTdr(const double params[]) const { return(VdrdT(params)); }
		virtual double VdTdrdS(const double params[]) const { return(VdSdrdT(params)); }
		virtual double VdTdrdSdS(const double params[]) const { return(VdSdSdrdT(params)); }
		virtual double VdTdrdSdr(const double params[]) const { return(VdSdrdrdT(params)); }
		virtual double VdTdrdSdv(const double params[]) const { return(VdSdrdvdT(params)); }
		virtual double VdTdrdSdT(const double params[]) const { return(VdSdrdTdT(params)); }
		virtual double VdTdrdr(const double params[]) const { return(VdrdrdT(params)); }
		virtual double VdTdrdrdS(const double params[]) const { return(VdSdrdrdT(params)); }
		virtual double VdTdrdrdr(const double params[]) const { return(VdrdrdrdT(params)); }
		virtual double VdTdrdrdv(const double params[]) const { return(VdrdrdvdT(params)); }
		virtual double VdTdrdrdT(const double params[]) const { return(VdrdrdTdT(params)); }
		virtual double VdTdrdv(const double params[]) const { return(VdrdvdT(params)); }
		virtual double VdTdrdvdS(const double params[]) const { return(VdSdrdvdT(params)); }
		virtual double VdTdrdvdr(const double params[]) const { return(VdrdrdvdT(params)); }
		virtual double VdTdrdvdv(const double params[]) const { return(VdrdvdvdT(params)); }
		virtual double VdTdrdvdT(const double params[]) const { return(VdrdvdTdT(params)); }
		virtual double VdTdrdT(const double params[]) const { return(VdrdTdT(params)); }
		virtual double VdTdrdTdS(const double params[]) const { return(VdSdrdTdT(params)); }
		virtual double VdTdrdTdr(const double params[]) const { return(VdrdrdTdT(params)); }
		virtual double VdTdrdTdv(const double params[]) const { return(VdrdvdTdT(params)); }
		virtual double VdTdrdTdT(const double params[]) const { return(VdrdTdTdT(params)); }
		virtual double VdTdv(const double params[]) const { return(VdvdT(params)); }
		virtual double VdTdvdS(const double params[]) const { return(VdSdvdT(params)); }
		virtual double VdTdvdSdS(const double params[]) const { return(VdSdSdvdT(params)); }
		virtual double VdTdvdSdr(const double params[]) const { return(VdSdrdvdT(params)); }
		virtual double VdTdvdSdv(const double params[]) const { return(VdSdvdvdT(params)); }
		virtual double VdTdvdSdT(const double params[]) const { return(VdSdvdTdT(params)); }
		virtual double VdTdvdr(const double params[]) const { return(VdrdvdT(params)); }
		virtual double VdTdvdrdS(const double params[]) const { return(VdSdrdvdT(params)); }
		virtual double VdTdvdrdr(const double params[]) const { return(VdrdrdvdT(params)); }
		virtual double VdTdvdrdv(const double params[]) const { return(VdrdvdvdT(params)); }
		virtual double VdTdvdrdT(const double params[]) const { return(VdrdvdTdT(params)); }
		virtual double VdTdvdv(const double params[]) const { return(VdvdvdT(params)); }
		virtual double VdTdvdvdS(const double params[]) const { return(VdSdvdvdT(params)); }
		virtual double VdTdvdvdr(const double params[]) const { return(VdrdvdvdT(params)); }
		virtual double VdTdvdvdv(const double params[]) const { return(VdvdvdvdT(params)); }
		virtual double VdTdvdvdT(const double params[]) const { return(VdvdvdTdT(params)); }
		virtual double VdTdvdT(const double params[]) const { return(VdvdTdT(params)); }
		virtual double VdTdvdTdS(const double params[]) const { return(VdSdvdTdT(params)); }
		virtual double VdTdvdTdr(const double params[]) const { return(VdrdvdTdT(params)); }
		virtual double VdTdvdTdv(const double params[]) const { return(VdvdvdTdT(params)); }
		virtual double VdTdvdTdT(const double params[]) const { return(VdvdTdTdT(params)); }
		virtual double VdTdT(const double params[]) const;
		virtual double VdTdTdS(const double params[]) const { return(VdSdTdT(params)); }
		virtual double VdTdTdSdS(const double params[]) const { return(VdSdSdTdT(params)); }
		virtual double VdTdTdSdr(const double params[]) const { return(VdSdrdTdT(params)); }
		virtual double VdTdTdSdv(const double params[]) const { return(VdSdvdTdT(params)); }
		virtual double VdTdTdSdT(const double params[]) const { return(VdSdTdTdT(params)); }
		virtual double VdTdTdr(const double params[]) const { return(VdrdTdT(params)); }
		virtual double VdTdTdrdS(const double params[]) const { return(VdSdrdTdT(params)); }
		virtual double VdTdTdrdr(const double params[]) const { return(VdrdrdTdT(params)); }
		virtual double VdTdTdrdv(const double params[]) const { return(VdrdvdTdT(params)); }
		virtual double VdTdTdrdT(const double params[]) const { return(VdrdTdTdT(params)); }
		virtual double VdTdTdv(const double params[]) const { return(VdvdTdT(params)); }
		virtual double VdTdTdvdS(const double params[]) const { return(VdSdvdTdT(params)); }
		virtual double VdTdTdvdr(const double params[]) const { return(VdrdvdTdT(params)); }
		virtual double VdTdTdvdv(const double params[]) const { return(VdvdvdTdT(params)); }
		virtual double VdTdTdvdT(const double params[]) const { return(VdvdTdTdT(params)); }
		virtual double VdTdTdT(const double params[]) const;
		virtual double VdTdTdTdS(const double params[]) const { return(VdSdTdTdT(params)); }
		virtual double VdTdTdTdr(const double params[]) const { return(VdrdTdTdT(params)); }
		virtual double VdTdTdTdv(const double params[]) const { return(VdvdTdTdT(params)); }
		virtual double VdTdTdTdT(const double params[]) const;


		virtual double risk_free_rate(const double params[]) const = 0;
		virtual double volatility(const double params[]) const = 0;
	protected:
		virtual double d(int pno, const double params[]) = 0;
		virtual double cdf(const double params[], double z) const;
		virtual double pdf(const double params[], double z) const;
		virtual double d1(const double params[]) const;
		virtual double d2(const double params[]) const;
	private:
};

#endif
