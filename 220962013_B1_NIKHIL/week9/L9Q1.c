//Queue using singly linked list without header node
#include <stdio.h>
#include <stdlib.h>
typedef struct nd *nptr;
typedef struct nd {
    int val;
    nptr next;
} node;
// empty ll
nptr h1 = NULL;
void insert(nptr *head, int ele)
{
    nptr temp, ptr;
    temp = malloc(sizeof(node));
    temp->val = ele;
    temp->next = NULL;
    if (*head == NULL)
        *head = temp;
    else{
        ptr = *head;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = temp;
    }
}

int delete(nptr *head)
{
    nptr ptr = *head;
    if (ptr == NULL){
        printf("\nList is Empty:\n");
        return -1;
    }
    else{
        *head = (*head)->next;
        int x = ptr->val;
        free(ptr);
        return x;
    }
}

void display(nptr *head)
{
    nptr ptr;
    if (*head == NULL){
        printf("\nList is empty:\n");
        return;
    }
    else{
        ptr = *head;
        printf("\nList elements are:\t");
        while (ptr != NULL)
        {
            printf("%d ", ptr->val);
            ptr = ptr->next;
        }
        printf("\n");
    }
}
int main() {
    insert(&h1,2);
    insert(&h1,4);
    insert(&h1,6);
    display(&h1);
    delete(&h1);
    delete(&h1);
    display(&h1);
    return 0;
}
