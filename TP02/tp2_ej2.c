#include "vector.c"
#include "fractionset.c"
void randomLoadAll(vector *ve);
void printFraction();
int main()
{
    vector *ve = vector_new(100);
    
    randomLoadAll(ve);
    printf("LLEGUE HASTA ACA JEJE\n");
    fractionset_t *fr;
    for (int i=0;i<100;i++)
    {
        fr = vector_get(ve,i);
        printf("%d/%d\n",fsetGetNum(fr),fsetGetDen(fr));
    }
    
    //vector_print(ve,printFraction(printFraction(*fr)));
    printf("OTRA VEZ LLEGUE HASTA ACA JEJE\n");
    return 0;
}

void randomLoadAll(vector *ve)
{
    fractionset_t *fr = fsetInit();
    for (int i=0;i<vector_size(ve);i++)
    {
        fsetLoadNum(fr,rand() % 100);
        fsetLoadDen(fr,rand() % 100);
        vector_add(ve,fr);
    }
    fsetFree(fr);
}

void printFraction(fractionset_t fr)
{
    //printf("%u/%u",fsetGetNum(fr),fsetGetDen(fr));
}