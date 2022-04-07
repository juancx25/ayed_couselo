
#include "..\TDAs\fraction.c"
#include "..\TDAs\vector.c"
#include "stdio.h"
int cmp_int(void* a,void* b);
void vector_sort_insertion(vector *ve, int n, int cmp(void*,void*));
void print_int(int value);

void main()
{
    vector *ve = vector_new(5);
    int *aux;
    aux = (int*)malloc(sizeof(int));
    for (int i = 0;i<5;i++)
    {
        *aux = (rand() % 10);
        vector_add(ve,aux);
    }
    int n = vector_size(ve);
    vector_sort_insertion(ve,vector_size(ve),(void*)cmp_int);
    vector_print(ve,(void*)print_int);
    return;
}

void vector_sort_insertion(vector *ve, int n, int cmp(void*,void*))
{
    if (n<=1) return;
    vector_sort_insertion(ve,n-1,(void*)cmp);
    int j = n-2;
    while ((j >= 0) && (cmp(vector_get(ve,j),vector_get(ve,n-1)) > 0)) {
        vector_set(ve,j+1,vector_get(ve,j));
        j--;
    }
    vector_set(ve,j+1,vector_get(ve,n-1));
    return;
}

int cmp_int(void* a,void* b)
{
    return a-b;
}

void print_int(int value)
{
    printf("%d\n",value);
}