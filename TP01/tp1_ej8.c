#include "fractionset.c"

int main()
{
    fractionset_t f1;
    fsetLoadNum(&f1,4);
    fsetLoadDen(&f1,2);
    printf("fraccion = %d / %d\n",fsetGetNum(f1),fsetGetDen(f1));

    int mcd = fsetGetMCD(f1);
    fsetLoadNum(&f1,(fsetGetNum(f1)/mcd));
    fsetLoadDen(&f1,((fsetGetDen(f1))/(mcd)));
    printf("fraccion reducida = %d / %d\n",fsetGetNum(f1),fsetGetDen(f1));


    return 0;
}