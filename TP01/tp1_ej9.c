#include "..\TDAs\complex.c"
#include <stdio.h>

void main()
{
    complex *z1 = complex_init();
    complex_setReal(z1,1);
    complex_setImg(z1,-3);
    printf("Z1 = %0.3f, %0.3fj\n",complex_getReal(z1),complex_getImg(z1));

    float modulus = complex_getMod(z1);
    float phase = complex_getPhase(z1);

    complex *z2 = complex_init();
    complex_setReal(z2,3);
    complex_setImg(z2,4);
    printf("Z2 = %0.3f, %0.3fj\n",complex_getReal(z2),complex_getImg(z2));
    printf("Modulo de Z2: %0.3f\n",complex_getMod(z2));

    complex *z3 = complex_sum(z1,z2);
    printf("Resultado de la suma (Z1+Z2): %0.3f, %0.3fj\n",complex_getReal(z3),complex_getImg(z3));

    z3 = complex_subtract(z1,z2);
    printf("Resultado de la resta (Z1-Z2): %0.3f, %0.3fj\n",complex_getReal(z3),complex_getImg(z3));

    z3 = complex_product(z1,z2);
    printf("Resultado del producto (Z1*Z2): %0.3f, %0.3fj\n",complex_getReal(z3),complex_getImg(z3));

    z3 = complex_div(z1,z2);
    printf("Division de Z1 por Z2: %0.3f, %0.3fj\n",complex_getReal(z3),complex_getImg(z3));

    z3 = complex_conj(z1);
    printf("Conjugado de Z1 = %0.3f, %0.3fj\n",complex_getReal(z1),complex_getImg(z1));

    //complex_free(z1);complex_free(z2);complex_free(z3);
    return;

}
