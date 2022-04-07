#ifndef COMPLEX_H_  

typedef struct
{
    float real;
    float img;
} complex;

complex* complex_init();

void complex_free(complex *cmp);

float complex_getReal(complex *cmp);

float complex_getImg(complex *cmp);

void complex_setReal(complex *cmp,float value);

void complex_setImg(complex *cmp,float value);


float complex_getMod(complex *cmp);

float complex_getPhase(complex *cmp);


complex *complex_conj(complex *z);

complex *complex_sum(complex *cmp1, complex *cmp2);

complex *complex_subtract(complex *z1, complex *z2);

complex *complex_product(complex *z1, complex *z2);

#endif // COMPLEX_H_