#define t_elem int
#include <stdlib.h>
#include <stdio.h>

#include "TDAs\vector.c"

typedef struct sll_node {
    t_elem value;
    struct sll_node* next;
} sll_node;

void sll_add_node(sll_node** head,t_elem elem);
sll_node* sll_new_node(t_elem elem);
void sll_remove_repeated(sll_node* head);
sll_node* sll_remove_elements(sll_node** head, t_elem element);
int sll_remove_element5(sll_node** head, t_elem element);
void sll_remove_repeated2(sll_node* head);
int cmp_int(void* a,void* b);
int vector_search(vector* ve, void* value, int cmp(void*,void*));

sll_node* sll_new_node(t_elem elem)
{
    sll_node* new_node = (sll_node*)malloc(sizeof(sll_node));
    if (new_node != NULL)
    {
        new_node->value = elem;
        new_node->next = NULL;
    }
    return new_node;
}

void sll_add(sll_node** head,t_elem elem)
{
    sll_node** aux = head;
    while(*aux != NULL)
    {
        aux = &(*aux)->next;
    }
    *aux = sll_new_node(elem);
}

void sll_print_node(sll_node* head)
{
    if (head != NULL)
    {
        printf("%d ",head->value);
        sll_print_node(head->next);
    }
    printf("\n");
}

sll_node* sll_remove_elements(sll_node** head, t_elem element) {
    sll_node* node_to_remove = NULL;
    sll_node** aux = head;

    while (*aux != NULL)
    {
        while (*aux != NULL && (*aux)->value != element) {
        aux = &(*aux)->next;
        }

        if (*aux != NULL) {
        node_to_remove = *aux;
        *aux = (*aux)->next;
        node_to_remove->next = NULL;
        }
    }
       
    return node_to_remove;
}

int sll_remove_element5(sll_node** head, t_elem element) {
    int result = 0;
    if (*head != NULL) {
        result += sll_remove_element5(&(*head)->next, element);
        if ((*head)->value == element) {
            sll_node* aux = *head;
            *head = (*head)->next;
            aux->next = NULL;
            free(aux);
            result++;
        }
    }
    return result;
}

int vector_search(vector* ve, void* value, int cmp(void*,void*))
{
    int i = 0;
    while (cmp(vector_get(ve,i),value) != 0){
        i++;
    }
    return i;

}

int cmp_int(void* a,void* b)
{
    int* x = (int*)a;
    int* y = (int*)b;
    return *x-*y;
}

void sll_remove_repeated(sll_node* head)
{
    if (head == NULL) return;
    sll_remove_element5(&(head->next),head->value);
    sll_remove_repeated(head->next);
}

void sll_remove_repeated2(sll_node* head)
{
    if (head == NULL) return;
    vector *unique = vector_new(6);
    int *aux;
    while (head->next != NULL) {
        sll_node* next = head->next;
        if (vector_search(unique,&(next->value),(void*)cmp_int)) {
            head->next = next->next;
            free(next);
        }
        else {
            *aux = head->value;
            vector_add(unique,aux);
            head = next;
            next = next->next;
        }
    }
    vector_free(unique);
}

void sll_remove_repeated_o(sll_node* head)
{
    if (head == NULL) return;
    while (head->next != NULL) {
        sll_node* next = head->next;
        if (head->value == next->value) {
            head->next = next->next;
            free(next);
        }
        else {
            head = next;
            next = next->next;
        }
    }
}

void main()
{
    sll_node* lista = sll_new_node(15);
    sll_add(&lista,3);
    sll_add(&lista,3);
    sll_add(&lista,3);
    sll_add(&lista,5);
    sll_add(&lista,6);
    sll_remove_repeated2(lista);
    sll_print_node(lista);
}