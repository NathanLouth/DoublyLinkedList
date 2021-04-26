///////////////////////////////////
//Doubly linked list written in C//
///////////////////////////////////

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* last;
};

void WriteL(struct Node* list) {
    while (list != NULL){
        printf(" %p ", list->last);
        printf(" %d ", list->data);
        printf(" %p ", list);
        printf(" %p ", list->next);
		list = list->next;
        printf("\n");
    }
};

void AddF(struct Node** list,int data){
    struct Node* newnode = (struct Node*) malloc(sizeof(struct Node));
    newnode->data = data;
    newnode->next = (*list);
    newnode->last = NULL;
    (*list)->last = newnode;
	(*list) = newnode;   
};

void AddE(struct Node** list,int data){
    struct Node * newnode = (struct Node *) malloc(sizeof(struct Node));   
    struct Node * lastnode = *list;
    newnode->data = data;
    newnode->next = NULL;
    while (lastnode->next != NULL){
        lastnode = lastnode->next;
    }
    lastnode->next = newnode;
    newnode->last = lastnode;
};

int main(){

    struct Node* list;
	list = (struct Node*)malloc(sizeof(struct Node));
    list->data = 5;

    AddF(&list,4);
    AddE(&list,6);
    AddF(&list,3);
    AddE(&list,7);
    AddF(&list,2);
    AddE(&list,8);
    AddF(&list,1);
    AddE(&list,9);
    AddF(&list,0);
    AddE(&list,10);

    WriteL(list);

    return 0;
}
