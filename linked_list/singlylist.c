// creating a singly linkedlist
#include <stdio.h>
#include <stdlib.h>
struct Node   // structure of a node of the list.
{
    int data;   // contains the info given by the user.
    struct Node *next;   // pointer that points to the address of the next connected node.
} *head = NULL;  

void create(int num)  // creates the list as per the length given by the user, also taking the data of each node from the user.
{
    struct Node *temp;
    struct Node *p;
    int i;
    for (i = 1; i <= num; i++)
    {
        temp = (struct Node *)malloc(sizeof(struct Node));   // creates each node in the heap memory.
        temp->next = NULL;
        printf("Enter Node data: ");
        scanf("%d", &(temp->data));
        if (head == NULL)
        {
            head = temp;
            p = temp;
        }
        else
        {
            p->next = temp;
            p = p->next;
        }
    }
}

void traverse()
{
    struct Node *p = head;
    if (head == NULL)   // means no node is currently present.
    {
        printf("List is empty\n");
        return;
    }
    else 
    {   
        printf("Current List is: \n");
        while (p->next != NULL)
        {
            printf("%d\t", p->data);
            p = p->next;
        }
        printf("%d\n", p->data);
    }
}

void insert(int data, int pos){
    struct Node* p = head;
    struct Node* temp;
    int i = 1;
    temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data=data;
    temp->next=NULL;
    if(head==NULL){  // if head is NULL, make the new node the 1st node.
        head = temp;
    }else if(pos==1){   // position the new node at the beginning of the current list.
        temp->next=p;
        head=temp;
    }else{
        while((p->next!=NULL)&&(i<pos-1)){   // position the new node anywhere in the current list.
            p=p->next;
            i++;
        }
            temp->next=p->next;
            p->next=temp;
        }
    }

int main(int argc, char **argv)
{
    int data, pos;
    int num, choice;
    while (1)
    {
        printf("==== Singly LinkedList ====\n");
        printf("1) Creating a new list\n");
        printf("2) Traversing the whole list\n");
        printf("3) Insert a new node anywhere in the list\n");
        printf("10) Exit the program\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
        case 1:
            printf("Enter the length of the list: ");
            scanf("%d", &num);
            create(num);
            break;
        case 2:
            traverse();
            break;
        case 3:
            printf("Enter the new node data: ");
            scanf("%d", &data);
            printf("Enter the position at which the node is to be inserted: ");
            scanf("%d", &pos);
            insert(data,pos);
            break;
        case 10: 
            exit(0);
            break;
        default:
            printf("Invalid choice\n");
            break;
        }
    }
}
