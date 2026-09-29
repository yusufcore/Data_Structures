#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
}*first=NULL;   // first is a pointer for implementing linkedlist.

void create(int A[], int n){
    int i;
    struct Node *t, *last;
    first=(struct Node*)malloc(sizeof(struct Node));
    first->data=A[0];
    first->next=NULL;
    last=first;

    for(i=1; i<n; i++){
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}
void display(struct Node *p){
    while(p!=NULL){
        printf("%d ", p->data);
        p=p->next;
    }
    printf("\n");
}
void recurseDisplay(struct Node *p){   // recursive function to display elements of linkedlist.
    if(p!=NULL){
        printf("%d ", p->data);
        recurseDisplay(p->next);
    }
}
void recurseReverseDisplay(struct Node *p){   // recursive function to display elements of linkedlist in reverse order.
    if(p!=NULL){
        recurseDisplay(p->next);
        printf("%d", p->data);
        printf("\n");
    }
}
int main(){
    int A[] ={3,5,7,10,15};
    create(A,5);
    // display(first);
    recurseDisplay(first);
    recurseReverseDisplay(first);
    return 0;
}