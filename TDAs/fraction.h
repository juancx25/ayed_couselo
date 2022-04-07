#ifndef FRACTION_H_

#include <stdlib.h>
#include <stdio.h>

typedef struct
{
    int num;
    int den;
} fraction;

fraction* fraction_init();

fraction* fraction_free(fraction* fset);


void fraction_setNum(fraction *fset, int value);

void fraction_setDen(fraction *fset, int value);

int fraction_getNum(fraction *fset);

int fraction_getDen(fraction *fset);

int fraction_getMCD(fraction *fset);


void fraction_simplify(fraction *fset);

void fraction_print(fraction *fr);


#endif // FRACTION_H_