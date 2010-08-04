#ifndef BSMODEL_1_V_H
#define BSMODEL_1_V_H

// This model computes, assuming
// CONSTANT risk_free_rate
// variable volatility, but, constant with respect to strike or expiration.

class bsmodel_1_v : public bsmodel_base {
	public:
		bsmodel_1_v(const cboe_option_quote& coq, double rfr);
		virtual ~bsmodel_1_v();

		virtual double risk_free_rate(const double params[]) const;
		virtual double volatility(const double params[]) const;
	protected:
		virtual double d(int pno, const double params[]);
		double _risk_free_rate;
	private:
};

#endif
