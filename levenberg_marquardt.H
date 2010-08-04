#ifndef LEVENBERG_MARQUARDT_H
#define LEVENBERG_MARQUARDT_H

/*
 * levenberg_marquardt will take a set of "functions", and
 * generate a parameter array that will best fit.
 */

class function {
	public:
		function(int n) : _number_of_parameters(n) { }
		virtual ~function() { }

		virtual double operator()(const double params[]) = 0;
		double derivative(int n, const double params[]) {
			if (n >= _number_of_parameters) return(0.0);
			else return(d(n, params));
		}

		int number_of_parameters() { return(_number_of_parameters); }
	protected:
		virtual double d(int n, const double params[]) = 0;
		int _number_of_parameters;
	private:
		function(const function&);
		function& operator=(const function&);
};

class levenberg_marquardt {
	public:
		levenberg_marquardt() : _number_of_parameters(0), _number_of_functions(0), _allocated(0), _functions(NULL) { }
		virtual ~levenberg_marquardt() { if (_functions) delete[] _functions; }

		void add(function *f);
		virtual void refine(const double best_guess[], double refined[]) = 0;
	protected:
		int _number_of_parameters;
		int _number_of_functions;
		int _allocated;
		function **_functions;

		void reallocate(int n);

		levenberg_marquardt(const levenberg_marquardt&);
		levenberg_marquardt& operator=(const levenberg_marquardt&);
};

class levenberg_marquardt_binesh : public levenberg_marquardt {
	public:
		void refine(const double best_guess[], double refined[]);
};

class levenberg_marquardt_gsl : public levenberg_marquardt {
	public:
		void refine(const double best_guess[], double refined[]);
		int f(const void *x, void *f);
		int df(const void *x, void *J);
};

#endif
