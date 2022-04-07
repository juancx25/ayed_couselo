#include "fraction.h"

fraction* fraction_init()
{
    fraction *fset = (fraction *)calloc(1,sizeof(fraction));
    return fset;
}

fraction* fraction_free(fraction* fset)
{
    free(fset);
}

void fraction_setNum(fraction *fset, int value)
{
    fset->num = value;
    return;
}

void fraction_setDen(fraction *fset, int value)
{
    fset->den = value;
    return;
}

int fraction_getNum(fraction *fset)
{
    int num = fset->num;
    return num;
}

int fraction_getDen(fraction *fset)
{
    int den = fset->den;
    return den;
}

int fraction_getMCD(fraction *fset)
{
    int a = fset->num;
    int b = fset->den;
    int aux;
    while (b != 0) {
        aux = b;
        b = a % b;
        a = aux;
    }
    return a;
}

void fraction_simplify(fraction *fr)
{
    int mcd = fraction_getMCD(fr);
    fraction_setNum(fr,(fraction_getNum(fr)/mcd));
    fraction_setDen(fr,((fraction_getDen(fr))/(mcd)));
}

void fraction_print(fraction *fr)
{
    printf("%d / %d\n",fraction_getNum(fr),fraction_getDen(fr));
    return;
}