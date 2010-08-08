#ifndef HISTOGRAM_H
#define HISTOGRAM_H

class histogram {
	public:
		histogram(int sz, const double *fenceposts);
		~histogram();

		void dump(FILE *fp) const;

		void accumulate(double x, double weight);
	private:
		int _sz;
		double _total;
		double *_fenceposts;
		double *_counts;
		histogram(const histogram&);
		histogram& operator=(const histogram&);
};

#endif
