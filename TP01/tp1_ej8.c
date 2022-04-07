#include "..\TDAs\fraction.c"

int main()
{
    fraction *f1 = fraction_init();
    fraction_setNum(f1,4);
    fraction_setDen(f1,2);
    printf("fraccion = %d / %d\n",fraction_getNum(f1),fraction_getDen(f1));

    fraction_simplify(f1);
    printf("fraccion reducida = %d / %d\n",fraction_getNum(f1),fraction_getDen(f1));


    return 0;
}