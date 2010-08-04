#ifndef BSMODEL_6_VR_H
#define BSMODEL_6_VR_H

// This model computes, assuming
// variable risk_free_rate, dependent on strike and expiration.
// variable volatility, but, constant with respect to strike or expiration.

class bsmodel_6_vr : public bsmodel_base {
	public:
		bsmodel_6_vr(const cboe_option_quote& coq);
		virtual ~bsmodel_6_vr();

		virtual double risk_free_rate(const double params[]) const;
		virtual double volatility(const double params[]) const;

		virtual double VdS(const double params[]) const;
		virtual double VdSdS(const double params[]) const;
		virtual double VdSdSdS(const double params[]) const;
		virtual double VdSdSdSdS(const double params[]) const;
		virtual double VdSdSdSdr(const double params[]) const;
		virtual double VdSdSdSdv(const double params[]) const;
		virtual double VdSdSdSdT(const double params[]) const;
		virtual double VdSdSdr(const double params[]) const;
		virtual double VdSdSdrdr(const double params[]) const;
		virtual double VdSdSdrdv(const double params[]) const;
		virtual double VdSdSdrdT(const double params[]) const;
		virtual double VdSdSdv(const double params[]) const;
		virtual double VdSdSdvdv(const double params[]) const;
		virtual double VdSdSdvdT(const double params[]) const;
		virtual double VdSdSdT(const double params[]) const;
		virtual double VdSdSdTdT(const double params[]) const;
		virtual double VdSdr(const double params[]) const;
		virtual double VdSdrdr(const double params[]) const;
		virtual double VdSdrdrdr(const double params[]) const;
		virtual double VdSdrdrdv(const double params[]) const;
		virtual double VdSdrdrdT(const double params[]) const;
		virtual double VdSdrdv(const double params[]) const;
		virtual double VdSdrdvdv(const double params[]) const;
		virtual double VdSdrdvdT(const double params[]) const;
		virtual double VdSdrdT(const double params[]) const;
		virtual double VdSdrdTdT(const double params[]) const;
		virtual double VdSdv(const double params[]) const;
		virtual double VdSdvdv(const double params[]) const;
		virtual double VdSdvdvdv(const double params[]) const;
		virtual double VdSdvdvdT(const double params[]) const;
		virtual double VdSdvdT(const double params[]) const;
		virtual double VdSdvdTdT(const double params[]) const;
		virtual double VdSdT(const double params[]) const;
		virtual double VdSdTdT(const double params[]) const;
		virtual double VdSdTdTdT(const double params[]) const;
		virtual double Vdr(const double params[]) const;
		virtual double Vdrdr(const double params[]) const;
		virtual double Vdrdrdr(const double params[]) const;
		virtual double Vdrdrdrdr(const double params[]) const;
		virtual double Vdrdrdrdv(const double params[]) const;
		virtual double VdrdrdrdT(const double params[]) const;
		virtual double Vdrdrdv(const double params[]) const;
		virtual double Vdrdrdvdv(const double params[]) const;
		virtual double VdrdrdvdT(const double params[]) const;
		virtual double VdrdrdT(const double params[]) const;
		virtual double VdrdrdTdT(const double params[]) const;
		virtual double Vdrdv(const double params[]) const;
		virtual double Vdrdvdv(const double params[]) const;
		virtual double Vdrdvdvdv(const double params[]) const;
		virtual double VdrdvdvdT(const double params[]) const;
		virtual double VdrdvdT(const double params[]) const;
		virtual double VdrdvdTdT(const double params[]) const;
		virtual double VdrdT(const double params[]) const;
		virtual double VdrdTdT(const double params[]) const;
		virtual double VdrdTdTdT(const double params[]) const;
		virtual double Vdv(const double params[]) const;
		virtual double Vdvdv(const double params[]) const;
		virtual double Vdvdvdv(const double params[]) const;
		virtual double Vdvdvdvdv(const double params[]) const;
		virtual double VdvdvdvdT(const double params[]) const;
		virtual double VdvdvdT(const double params[]) const;
		virtual double VdvdvdTdT(const double params[]) const;
		virtual double VdvdT(const double params[]) const;
		virtual double VdvdTdT(const double params[]) const;
		virtual double VdvdTdTdT(const double params[]) const;
		virtual double VdT(const double params[]) const;
		virtual double VdTdT(const double params[]) const;
		virtual double VdTdTdT(const double params[]) const;
		virtual double VdTdTdTdT(const double params[]) const;
	protected:
		virtual double d(int pno, const double params[]);
	private:
		virtual double da(const double params[]) const;
		virtual double db(const double params[]) const;
		virtual double dc(const double params[]) const;
		virtual double dd(const double params[]) const;

};

#endif
