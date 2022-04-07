
#include "..\TDAs\complex.c"
#include "..\TDAs\vector.c"

void complex_randomLoad(vector *ve,int maxSize);

void main()
{
    vector *ve = vector_new(10);
    
    complex_randomLoad(ve,10);
    complex *z;
    for (int i=0;i<10;i++)
    {
        z = vector_get(ve,i);
        printf("%0.3f, %0.3fj\n",complex_getReal(z),complex_getImg(z));
        complex_free(z);
    }
    return;
}

void complex_randomLoad(vector *ve,int maxSize)
{
    complex *z = NULL;
    for (int i=0;i<maxSize;i++)
    {
        z = complex_init();
        complex_setReal(z,(rand() % 10)-5);
        complex_setImg(z,(rand() % 10)-5);
        vector_add(ve,z);
    }
    return;
}