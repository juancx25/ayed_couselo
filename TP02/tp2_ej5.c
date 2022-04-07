
#include "tp2_ej2.c"
#include "stdio.h"

vector* vector_cpy(vector *orig);
vector* bubble_vector_sort(vector *ve,int cmp(void*,void*));
int fraction_cmp(fraction *fr1,fraction *fr2);

void main()
{

    vector *ve = vector_new(10);
    fraction_randomLoad(ve,10);

    fraction *fr;
    vector_print(ve,(void*)fraction_print);

    printf("--------------------------------------\n");
    vector *vresult = bubble_vector_sort(ve,(void*)fraction_cmp);
    vector_print(vresult,(void*)fraction_print);
    return;
}

vector* bubble_vector_sort(vector *ve,int cmp(void*,void*))
{
    vector *vout = vector_cpy(ve);
    int n = vector_size(vout);
    char swapped = 1;
    while ((swapped != 0) && (n > 0))
    {
        swapped = 0;
        for (int i=1;i<n;i++)
        {
            if ( cmp(vector_get(vout,i-1),vector_get(vout,i)) > 0 )
            {
                void* aux = vector_get(vout,i-1);
                vector_set(vout,i-1,vector_get(vout,i));
                vector_set(vout,i,aux);
                swapped = 1;
            }
        }    
        n--;
    }
    
    return vout;
}

vector* vector_cpy(vector *orig)
{
    int n = vector_size(orig);
    vector *dest = vector_new(n);
    for (int i=0;i<n;i++)
    {
        vector_add(dest,vector_get(orig,i));
    }
    return dest;
}

int fraction_cmp(fraction *fr1,fraction *fr2)
{
    float div1 = (float)fraction_getNum(fr1) / (float)fraction_getDen(fr1);
    float div2 = (float)fraction_getNum(fr2) / (float)fraction_getDen(fr2);
    if (div1<div2) return -1;
    if (div1==div2) return 0;
    if (div1>div2) return 1;
}