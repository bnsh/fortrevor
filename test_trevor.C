#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "levenberg_marquardt.H"

class trevorfunction : public function {
	public:
		trevorfunction(double x0, double x1, double y) : function(2), _x0(x0), _x1(x1), _y(y) { }
		virtual ~trevorfunction() { }

		inline double val(const double param[]) {
			double a = param[0];
			double b = param[1];
			return((a * _x0 + b * _x1));
		}

		double operator()(const double param[]) {
			return(val(param) - _y);
		}
		double d(int n, const double []) {
			if (n == 0) return(_x0);
			else if (n == 1) return(_x1);
			else return(0.0);
		}
		double _x0;
		double _x1;
		double _y;
};

int main(int argc,char *argv[]) {
	if (argc >= 2) {
		double a = atof(argv[1]);
		double b = atof(argv[2]);
		int seed = 5;
		if (argc > 3) seed = atoi(argv[3]);
		const int n = 10;
		double errs[n*n] = { 0.2535271, -0.2482354, 0.3585853, -0.4294484, -0.3635830, -0.1696631, -0.4948938, 0.0791455, 0.2004627, -0.2484524, -0.0936738, 0.3483593, 0.4518397, -0.1708851, -0.0299010, -0.0435562, 0.0943921, -0.2384229, -0.2540374, 0.0716383, 0.4205253, 0.2590908, 0.3715887, 0.0019363, 0.3608112, -0.0895933, -0.0439441, 0.4088527, 0.3903124, -0.0453210, 0.0882521, -0.0016900, -0.3777190, 0.4232469, -0.3331225, -0.2193291, -0.3143471, 0.3955825, 0.0152924, -0.3223589, -0.0665982, -0.4871659, -0.2955956, 0.2144398, 0.2942145, 0.0690331, 0.2976102, -0.2199521, -0.3818820, -0.1230703, 0.4443194, -0.1340650, -0.2862486, 0.1210499, -0.3232594, 0.3444538, -0.2048013, -0.2309688, -0.3445365, 0.1527527, -0.3079395, 0.0333177, -0.0868644, 0.2778775, -0.3017519, 0.3442316, -0.2344874, 0.1556237, 0.1914766, 0.3132662, -0.3981846, 0.1022066, 0.3233575, -0.0012388, 0.2912169, 0.1870950, -0.0857613, 0.2171535, -0.2878931, -0.3387995, -0.2294813, -0.2803970, 0.1413633, 0.2014366, -0.3638040, 0.3394389, 0.3511347, 0.4855061, -0.1158256, 0.0396675, 0.1226931, 0.0252966, 0.4137023, 0.4964525, -0.4240764, 0.4597611, 0.4437927, 0.0543712, 0.2573246, 0.2255416 };
		function **f = new function *[n*n];
		srand48(seed);

		double params[2] = { a, b };

		levenberg_marquardt_binesh lm;
		int num = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				double x0 = i;
				double x1 = j;
				trevorfunction cf(x0,x1, 0);
				fprintf(stderr,"%.7f * %.7f + %.7f * %.7f = %.7f\n",params[0],x0,params[1],x1,cf(params));
				f[num] = new trevorfunction(x0, x1, cf(params) + errs[num]);
				lm.add(f[num]);
				num++;
			}
		}
		double guess[4];
		for (int i = 0; i < 2; ++i) guess[i] = 0.0;
		double refined[2] = { 0.0, 0.0 };
		lm.refine(guess, refined);
		for (int i = 0; i < 2; ++i) {
			printf("param[%d]	%.7f	%.7f	%.7f\n", i,guess[i], params[i], refined[i]);
		}
		double sse = 0.0;
		for (int i = 0; i < n*n; ++i) {
			trevorfunction *tf = (trevorfunction *)f[i];
			double r = tf->val(refined);
			double p = tf->_y;
			double err2 = (r-p)*(r-p);
			sse += err2;
			printf("f[%.7f,%.7f] = %.7f (fitted to %.7f) (err^2=%.7f (%.7f))\n",tf->_x0, tf->_x1,p, r, err2, sse);
		}
		printf("sse=%.7f\n",sse);
	}
	return(0);
}
