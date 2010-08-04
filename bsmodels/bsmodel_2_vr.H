#ifndef BSMODEL_2_VR_H
#define BSMODEL_2_VR_H

// This model computes, assuming
// variable risk_free_rate, but, constant with respect to strike or expiration.
// variable volatility, but, constant with respect to strike or expiration.

class bsmodel_2_vr : public bsmodel_base {
	public:
		bsmodel_2_vr(const cboe_option_quote& coq);
		virtual ~bsmodel_2_vr();

		virtual double risk_free_rate(const double params[]) const;
		virtual double volatility(const double params[]) const;
	protected:
		virtual double d(int pno, const double params[]);
	private:
};

#endif
