#include "..\TDAs\fraction.c"
#include "..\TDAs\complex.c"
#include "..\TDAs\vector.c"
#include "stdio.h"
void fraction_print(fraction *fr);

int main()
{
    fraction *fr = fraction_init();
    fraction_setNum(fr,24);
    fraction_setDen(fr,5);

    vector *ve1 = vector_new(1);
    vector_add(ve1,fr);
    void (*print_ptr)(fraction*) = fraction_print;
    vector_print(ve1,(void*)print_ptr);


    complex *z = complex_init();
    complex_setReal(z,4);
    complex_setImg(z,3.5);


    vector *ve2 = vector_new(1);
    vector_add(ve2,z);
    void (*print_ptr2)(complex*) = complex_print;
    vector_print(ve2,(void*)print_ptr2);
    return 0;
}