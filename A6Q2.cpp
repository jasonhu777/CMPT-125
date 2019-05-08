#include <stdio.h>
#include <stdlib.h>


typedef struct _dllnode  {
    int data;
    struct _dllnode * next;
    struct _dllnode * prev;
} DLLnode_t;


typedef struct {
    DLLnode_t * head;
} DLL_t;


DLL_t * DLLCreate() {
    DLL_t * ret = malloc(sizeof(DLL_t));
    ret->head = NULL;
    return ret;
}


void DLLAppend(DLL_t * intlist, int x) {

    DLLnode_t * newNode = malloc(sizeof(DLLnode_t));
    newNode->data = x;
    newNode->prev = NULL;
    newNode->next = NULL;


    if(intlist->head == NULL) {
        intlist->head = newNode;
        return;
    }

    DLLnode_t * temp =intlist->head;
    while(temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
}


void DLLPrint(DLL_t * intlist) {
    DLLnode_t * temp = intlist->head;
    while(temp != NULL) {
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}


void DLLReverse(DLL_t * intlist){
    DLLnode_t* current = intlist->head;

    DLLnode_t* temp;
    if (current == NULL){

    }
    else{
        while ( current != NULL ){

            temp = current->prev;
            current->prev = current->next;
            current->next = temp;
            current = current->prev;
        }
        if (temp != NULL){
            intlist->head = temp->prev;
        }
    }
}

void DLLRemove(DLL_t * intlist, int ind){

    DLLnode_t* current = intlist->head;
    for (int i = 0; (i < ind && current != NULL); i++) {
        current = current->next;
    }
    if (current != NULL){

        if (current == intlist->head){
            intlist->head = current->next;
        }

        if (current -> next != NULL){

            current->next->prev = current->prev;
        }

        if (current->prev != NULL){

            current->prev->next = current->next;
        }

        free(current);

    }
}

int main(){

    DLL_t * intlist = DLLCreate();
    DLLAppend(intlist, 6);
    DLLAppend(intlist, 7);
    DLLAppend(intlist, 8);
    DLLAppend(intlist, 9);
    DLLAppend(intlist, 10);
    printf("Printing before Reversing: ");
    DLLPrint(intlist);
    printf("\n");
    DLLReverse(intlist);
    printf("Printing after Reversing: ");
    DLLPrint(intlist);

    int indexremoval;
    printf("\n \n \nWhat index do you want to remove? ");
    scanf("%d", &indexremoval);
    printf("\n");
    printf("Printing before removal of index %d:  ", indexremoval);
    DLLPrint(intlist);
    DLLRemove(intlist, indexremoval);
    printf("\nPrinting after removal of index %d:  ", indexremoval);
    DLLPrint(intlist);
    printf("\n");
    return 0;
}
