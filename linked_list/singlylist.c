// creating a singly linkedlist
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
} *head = NULL;

void create(int num)
{
    struct Node *temp;
    struct Node *p;
    int i;
    for (i = 1; i <= num; i++)
    {
        temp = (struct Node *)malloc(sizeof(struct Node));
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
    if (head == NULL)
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

int main(int argc, char **argv)
{
    int data, pos;
    int num, choice;
    while (1)
    {
        printf("==== Singly LinkedList ====\n");
        printf("1) Creating a new list\n");
        printf("2) Traversing the whole list\n");
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
        default:
            printf("Invalid choice\n");
            break;
        }
    }
}
