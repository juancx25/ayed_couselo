#include "stdlib.h"
#include "stdio.h"

typedef struct
{
    int num;
    int den;
} fractionset_t;

fractionset_t* fsetInit()
{
    fractionset_t *fset = (fractionset_t *)calloc(1,sizeof(fractionset_t));
    return fset;
}

fractionset_t* fsetFree(fractionset_t* fset)
{
    free(fset);
}

void fsetLoadNum(fractionset_t *fset, int value)
{
    fset->num = value;
    return;
}

void fsetLoadDen(fractionset_t *fset, int value)
{
    fset->den = value;
    return;
}

int fsetGetNum(fractionset_t *fset)
{
    int num = fset->num;
    return num;
}

int fsetGetDen(fractionset_t *fset)
{
    int den = fset->den;
    return den;
}

int fsetGetMCD(fractionset_t *fset)
{
    int resto;
    while (fset->den != 0)
    {
        resto = fset->num % fset->den;
        fset->num = fset->den;
        fset->den = resto;
    }
    return fset->num;
}

void fsetSimplify(fractionset_t fset)
{

}

