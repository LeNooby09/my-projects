#include <mpfr.h>
#include <stdio.h>

int main()
{
    mpfr_t x;
    mpfr_init2(x, 100000); // initialize with 500-bit precision max10000000000

    mpfr_set_ui(x, 27, MPFR_RNDN); // set x to 27
    mpfr_sqrt(x, x, MPFR_RNDN); // calculate the square root of x

    // print the result to 500 decimal places
    mpfr_printf("\n%.100000Rf\n\n", x);

    mpfr_clear(x); // free memory
    return 0;
}