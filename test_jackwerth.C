#include <stdio.h>
#include <math.h>
#include "histogram.H"
#include "jackwerth.H"

int main(int ,char *[]) {
	jackwerth j;
	j
		.risk_free_rate(log(1.05))
		.dividend_yield(log(1.00))
		.underlying_current(1.0)
		.expiration(1.0); // In _years_.

	for (int i = 6; i <= 14; ++i) {
		j.option(i/10.0,0.7 - 0.5 * i/10.0);
	}

	histogram *h = j.compute_histogram(0.1,1.9,0.01);
	h->dump(stdout);
	delete h; h = NULL;

	return(0);
}
