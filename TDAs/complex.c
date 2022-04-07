#include <stdlib.h>
#include "complex.h"
#include <math.h>
#include <malloc.h>

complex* complex_init()
{
    complex *z = (complex *)calloc(1,sizeof(complex));
    return z;
}

void complex_free(complex *z)
{
    free(z);
}

float complex_getReal(complex *z)
{
    return z->real;
}
    
float complex_getImg(complex *z)
{
    return z->img;
}

void complex_setReal(complex *z,float value)
{
    z->real = value;
    return;
}

void complex_setImg(complex *z,float value)
{
    z->img = value;
    return;
}

float complex_getMod(complex *z)
{
    return ( sqrt( (pow(z->real,2))+(pow(z->img,2)) ) );
}

float complex_getPhase(complex *z)
{
    return atan((z->img/z->real));
}

complex *complex_conj(complex *z)
{
    z->img *= -1;
    return z;
}

complex *complex_sum(complex *z1, complex *z2)
{
    complex *z = complex_init();
    z->real = (z1->real + z2->real);
    z->img = (z1->img + z2->img);
    return z;
}

complex *complex_subtract(complex *z1, complex *z2)
{
    complex *z = complex_init();
    z->real = (z1->real - z2->real);
    z->img = (z1->img - z2->img);
    return z;
}

complex *complex_product(complex *z1, complex *z2)
{
    complex *z = complex_init();
    z->real = ((z1->real*z2->real) - (z1->img*z2->img));
    z->img = ((z1->real*z2->img) + (z2->real*z1->img));
    return z;
}

complex *complex_div(complex *z1, complex *z2)
{
    complex *z = complex_init();
    z = (complex_product(z1,complex_conj(z2)));
    float den = pow(complex_getMod(z2),2);
    z->real /= den;
    z->img /= den;
    return z;
}

void complex_print(complex *z)
{
    printf("%f, %fj\n",complex_getReal(z),complex_getImg(z));
    return;
}