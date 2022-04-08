
#include "..\TDAs\fraction.c"
#include "..\TDAs\vector.c"
#include <stdio.h>
int cmp_int(void* a,void* b);
void vector_sort_insertion(vector *ve, int n, int cmp(void*,void*));
void print_int(int* value);
vector* vector_random(vector *ve,int n);

int main()
{
    vector *ve = vector_new(5);
    ve = vector_random(ve,5);
    vector_print(ve,(void*)print_int);
    printf("///////////////////////\n");
    int n = vector_size(ve);
    vector_sort_insertion(ve,vector_size(ve),(void*)cmp_int);
    vector_print(ve,(void*)print_int);
    return 0;
}

void vector_sort_insertion(vector *ve, int n, int cmp(void*,void*))
{
    if (n<=1) return;
    vector_sort_insertion(ve,n-1,(void*)cmp);
    void* last = vector_get(ve,n-1);
    int j = n-2;
    while ((j >= 0) && (cmp(vector_get(ve,j),last) > 0)) {
        vector_set(ve,j+1,vector_get(ve,j));
        j--;
    }
    vector_set(ve,j+1,last);
    return;
}

int cmp_int(void* a,void* b)
{
    int* x = (int*)a;
    int* y = (int*)b;
    return *x-*y;
}

void print_int(int* value)
{
    printf("%d\n",*value);
}

vector* vector_random(vector *ve,int n)
{
    int *aux;
    for (int i = 0;i<n;i++)
    {
        aux = (int*)malloc(sizeof(int));
        *aux = (rand() % 100);
        vector_add(ve,aux);
    }
    return ve;
}
