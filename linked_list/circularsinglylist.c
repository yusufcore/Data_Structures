#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
}*head=NULL;

void create(int num){
    int i;
    struct Node* temp;
    struct Node* p;
    for(i=1; i<=num; i++){
        temp=(struct Node* )malloc(sizeof(struct Node));
        temp->next=NULL;
        printf("Enter the node data: ");
        scanf("%d", &(temp->data));
        if(head==NULL){
            head=temp;
            temp->next=head;
        }else{
            p=head;
            while(p->next!=head){
                p=p->next;
            }
            p->next=temp;
            p=p->next;
            p->next=head;
        }
    }
}

int traverse(){
    struct Node* p = head;
    while(p->next!=head){
        printf("%d\t", p->data);
        p=p->next;
    }
    printf("%d\n", p->data);
    if(p->next==head){
        printf("Circular linkedlist successfully created!\n");
        printf("Last node is: %d\n", p->data);
        printf("Head node is: %d\n", p->next->data);
    }else{
        printf("Not a circular linkedlist!\n");
        return 0;
    }
}


int main(int argc, char **argv)
{
    int data, pos;
    int num, choice;
    while (1)
    {
        printf("==== Circular Singly LinkedList ====\n");
        printf("1) Creating a new list\n");
        printf("2) Traversing the whole list\n");
        printf("3) Insert a new node anywhere in the list\n");
        printf("4) To delete any node in the list\n");
        // printf("5) To seacrh an element\n");
        printf("10) Exit the program\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the length of the list: ");
            scanf("%d", &num);
            create(num);
            break;
        case 2:
            traverse();
            break;
        // case 3:
        //     printf("Enter the new node data: ");
        //     scanf("%d", &data);
        //     printf("Enter the position at which the node is to be inserted: ");
        //     scanf("%d", &pos);
        //     insert(data, pos);
        //     break;
        // case 4:
        //     printf("Enter the position of node to be deleted: ");
        //     scanf("%d", &pos);
        //     delete(pos);
        //     break;
        // case 5: 
        //     printf("Enter the element to be searched: ");
        //     scanf("%d", &data);
        //     int found = search(data);
        //     printf("Element was found successfully: %d\n", found);
        //     break;
        case 10:
            exit(0);
            break;
        default:
            printf("Invalid choice\n");
            break;
        }
    }
}