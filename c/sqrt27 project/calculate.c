#include <mpfr.h>
#include <stdio.h>

int main()
{
    mpfr_t x;
    mpfr_init2(x, 100000);

    mpfr_set_ui(x, 27, MPFR_RNDN);
    mpfr_sqrt(x, x, MPFR_RNDN);

    mpfr_printf("\n%.100000Rf\n\n", x);

    mpfr_clear(x);
    return 0;
}
