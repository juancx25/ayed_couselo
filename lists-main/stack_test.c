#include <stdlib.h>
#include "stack_dynamic.c"
void stack_print_i(stack *s);
void stack_print_r(stack *s);

void main(){
    stack* s = stack_new(5);
    push(s,5);
    push(s,2);
    push(s,3);
    push(s,1);
    push(s,4);
    stack_print_r(s);
}

void stack_print_r(stack *s){
    int value;
    printf("%d ",value);
}

void stack_print_i(stack *s){
    int value;
    int i = 0;
    int size = stack_getsize(s);
    stack *aux = stack_new(size);
    while (i<size){
        value = pop(s);
        push(aux,value); 
        i++;
    }
    while (i>0){
        value = pop(aux);
        push(s,value);
        printf("%d ",value);
        i--;
    }

    printf("\n");
    //stack_free(aux);
}