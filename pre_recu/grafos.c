#include "..\TP07\graph_m.c"
#include "..\lists-main\stack_dynamic.c"
#include "..\lists-main\queue_dynamic.c"
#include <stdio.h>

/*  Consigna: Dado un grafo, dirigido o no,
    encontrar todos los posibles caminos simples
    entre un nodo origen y un nodo destino.     */

void vector_intPrint(void* value){
    int aux = *((int*)value);
    printf("%d  ",aux);
}

int int_cmp(void*a,void*b){
    int* v1 = (int*)a;
    int* v2 = (int*)b;
    int r = *v1-*v2;
    return r;
}

int vector_find(vector* v,void* value,int cmp(void*,void*)){
    int found = -1;
    int n = vector_size(v);
    int i=0;
    while ((found == -1) && (i<n)){
        if (cmp(vector_get(v,i),value) == 0) found = i;
        i++;
    }
    return found;
}

void graph_printDFT(graph* g, int o_id){
    stack* s = stack_new(g->v_count);
    vector* visited = vector_new(g->v_count);
    push(s,o_id);
    while (!stack_isempty(s)){
        int id = pop(s);
        for (int i=0;i<g->v_count;i++){
            if ((matrix_get(g->m_adj,id,i) > 0) &&
            (vector_find(visited,(void*)&i,int_cmp) < 0)) {
                int* aux = (int*)malloc(sizeof(int));
                *aux = i;
                vector_add(visited,(void*)aux);
                push(s,i); 
            }
        }
        printf("%d ",id);
    }
    stack_free(s);
    vector_free(visited);
}

void graph_printAllPaths_util(graph* g, int id, int d_id,vector* visited, vector* path){
    int* aux = (int*)malloc(sizeof(int));
    *aux = id;
    vector_add(visited,(void*)aux);
    vector_add(path,(void*)aux);

    if (id == d_id){
        vector_print(path,(void*)vector_intPrint);
    }
    else{
        for (int i=0;i<g->v_count;i++){
            if ((matrix_get(g->m_adj,id,i) > 0) && (vector_find(visited,(void*)&i,int_cmp) < 0)) {
                graph_printAllPaths_util(g,i,d_id,visited,path);
            }
        }
    }
    vector_remove(path,id);
    vector_remove(visited,id);
    free(aux);
}

void graph_printAllPaths(graph* g, int o_id, int d_id){
    vector* visited = vector_new(g->v_count);
    vector* path = vector_new(g->v_count);
    graph_printAllPaths_util(g,o_id,d_id,visited,path);
}

void main(){
    graph* g = graph_new(9);
    graph_add_vertex(g,'0');
    graph_add_vertex(g,'1');
    graph_add_vertex(g,'2');
    graph_add_vertex(g,'3');
    graph_add_vertex(g,'4');
    graph_add_vertex(g,'5');
    graph_add_vertex(g,'6');
    graph_add_vertex(g,'7');
    graph_add_vertex(g,'8');

    graph_add_edge(g,0,1,1);
    graph_add_edge(g,0,2,1);

    graph_add_edge(g,1,3,1);
    graph_add_edge(g,1,5,1);

    graph_add_edge(g,2,3,1);
    graph_add_edge(g,2,4,1);
    graph_add_edge(g,2,6,1);
    graph_add_edge(g,2,7,1);

    graph_add_edge(g,3,0,1);
    graph_add_edge(g,3,4,1);
    graph_add_edge(g,3,8,1);

    graph_add_edge(g,5,3,1);
    graph_add_edge(g,5,4,1);

    graph_add_edge(g,7,6,1);
    
    graph_printAllPaths(g,0,4);

}