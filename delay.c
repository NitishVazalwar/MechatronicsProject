#include <MKL25Z4.H>

void Delay_fn (uint32_t dly) {
  volatile uint32_t t;

	for (t=dly*10000; t>0; t--)
		;
}

