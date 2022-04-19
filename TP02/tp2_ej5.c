
#include "tp2_ej2.c"
#include "stdio.h"

vector* vector_cpy(vector *orig);
void vector_sort_bubble(vector *ve, int n, int cmp(void*,void*));
int fraction_cmp(fraction *fr1,fraction *fr2);
void swap(vector *ve,int pos1,int pos2);

void main()
{

    vector *ve = vector_new(10);
    fraction_randomLoad(ve,10);

    fraction *fr;
    vector_print(ve,(void*)fraction_print);

    printf("--------------------------------------\n");
    vector *vc = vector_cpy(ve);
    vector_sort_bubble(vc,vector_size(vc),(void*)fraction_cmp);
    vector_print(vc,(void*)fraction_print);
    return;
}

void vector_sort_bubble(vector *ve, int n, int cmp(void*,void*))
{
    int i;
    if (n<2) return;
    
    for (i=0;i<n-1;i++)
    {
        if (cmp(vector_get(ve,i),vector_get(ve,i+1)) > 0)
        {
            swap(ve,i,(i+1));
        }
    }
    vector_sort_bubble(ve,n-1,(void*)cmp);    
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

void swap(vector *ve,int pos1,int pos2)
{
    //Recibe las posiciones de un vector e intercambia sus miembros
    void *aux;
    aux = vector_get(ve,pos1);
    vector_set(ve,pos1,vector_get(ve,pos2));
    vector_set(ve,pos2,aux);
}