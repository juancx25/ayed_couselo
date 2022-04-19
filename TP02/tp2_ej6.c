
#include "..\TDAs\fraction.c"
#include "..\TDAs\vector.c"
#include <stdio.h>
int cmp_int(void* a,void* b);
void vector_sort_bubble(vector *ve, int n, int cmp(void*,void*));
void vector_sort_insertion(vector *ve, int n, int cmp(void*,void*));
void vector_sort_selection(vector *ve, int n, int cmp(void*,void*));
void print_int(int* value);
vector* vector_random(vector *ve,int n);
void swap(vector *ve,int pos1,int pos2);

int main()
{
    vector *ve = vector_new(5);
    ve = vector_random(ve,5);
    vector_print(ve,(void*)print_int);

    printf("\n----------------------\n");
    int* aux;
    *aux= vector_size(ve);
    vector_sort_bubble(ve,*aux,(void*)cmp_int);
    //vector_sort_insertion(ve,vector_size(ve),(void*)cmp_int);
    //vector_sort_selection(ve,vector_size(ve),(void*)cmp_int);
    vector_print(ve,(void*)print_int);

    return 0;
}
//Igual a la del ej5, al no funcionar los include copié y pegué todas las funciones (no me maten)
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

void vector_sort_selection(vector *ve, int n, int cmp(void*,void*))
{
    int i;
    int max_pos = 0;
    if (n<2) return;
    for (i=0;i<(n-1);i++)
    {
        if (cmp(vector_get(ve,i+1),vector_get(ve,max_pos)) > 0)
        {
            max_pos = (i+1);
        }
    }

    swap(ve,(n-1),max_pos);

    vector_sort_selection(ve,n-1,(void*)cmp);
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

void swap(vector *ve,int pos1,int pos2)
{
    //Recibe las posiciones de un vector e intercambia sus miembros
    void *aux;
    aux = vector_get(ve,pos1);
    vector_set(ve,pos1,vector_get(ve,pos2));
    vector_set(ve,pos2,aux);
}

int cmp_int(void* a,void* b)
{
    int* x = (int*)a;
    int* y = (int*)b;
    return *x-*y;
}

void print_int(int* value)
{
    printf("%d ",*value);
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
