#include "..\TDAs\fraction.c"
#include "..\TDAs\vector.c"


void fraction_randomLoad(vector *ve,int maxSize);

void fraction_randomLoad(vector *ve,int maxSize)
{
    fraction *fr = NULL;
    int den;
    for (int i=0;i<maxSize;i++)
    {
        fr = fraction_init();
        fraction_setNum(fr,rand() % 100);
        den = 0;
        while (den == 0)
        {
            den = rand() % 100;
        }
        fraction_setDen(fr,den);
        vector_add(ve,fr);
    }
}

/*int main()
{
    vector *ve = vector_new(10);
    
    fraction_randomLoad(ve,10);
    fraction *fr;
    for (int i=0;i<10;i++)
    {
        fr = vector_get(ve,i);
        printf("%d/%d\n",fraction_getNum(fr),fraction_getDen(fr));
        fraction_free(fr);
    }
    return 0;
}*/
