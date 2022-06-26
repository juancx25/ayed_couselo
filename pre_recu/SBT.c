#include "..\TP06\btree_base.c"

/* Dado un árbol binario de búsqueda, crear funciones para obtener su predecesor y sucesor */

void btn_intToStr(btn* node, char* str) {
    if (!node) return;
    sprintf(str, "(%03d)", node->value);
}

int _sbt_predecessor(btn* node,int value, int* prev){
    int found = 0;
    if (node){
        found = _sbt_predecessor(node->left,value,prev);
        if ((found == 0) && (node->value != value)){
            *prev = node->value;
            found = _sbt_predecessor(node->right,value,prev);
        }
        else found = 1;
    }
    return found;
}

int sbt_predecessor(btn* root,int value){
    int pred = -1;
    int found = _sbt_predecessor(root,value,&pred);
    if (found == 0) pred = -1;
    return pred;
}

int _sbt_successor(btn* node,int value, int* upcoming){
    int found = 0;
    if (node){
        found = _sbt_successor(node->right,value,upcoming);
        if ((found == 0) && (node->value != value)){
            *upcoming = node->value;
            found = _sbt_successor(node->left,value,upcoming);
        }
        else found = 1;
    }
    return found;
}

int sbt_successor(btn* root,int value){
    int upcoming = -1;
    int found = _sbt_successor(root,value,&upcoming);
    if (found == 0) upcoming = -1;
    return upcoming;    
}

void main(){
    btn* root = btn_new(8);
    btn_insert_value(&root,3);
    btn_insert_value(&root,20);
    btn_insert_value(&root,1);
    btn_insert_value(&root,12);
    btn_insert_value(&root,5);
    btn_insert_value(&root,21);
    btn_print(root,btn_intToStr);

    int value = 5;
    int r;
    r = sbt_predecessor(root,value);
    printf("Predecesor de %d: %d\n",value,r);
    r = sbt_successor(root,value);
    printf("Sucesor de %d: %d\n",value,r);
}