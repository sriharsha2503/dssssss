//Add two long positive integers represented using circular doubly linked list with header node.
#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void makeCirc(Node ** list) {
    Node * temp = (Node *) malloc (sizeof(Node));
    temp = (*list)->rnode;
    while (temp -> rnode != NULL)   
        temp = temp->rnode;
    temp->rnode = *list;
    (*list)->lnode = temp;
}

void displayCirc(Node **node) {
    Node * temp = (Node *) malloc (sizeof(Node));
    temp = (*node)->rnode;
    printf("The list is: ");
    while(temp != *node) {
        printf("%d ",temp->val);
        temp = temp->rnode;
    }
    printf("\n");
}

void insertFrontCDLL(Node ** list, int x) {
    Node * temp = (Node *) malloc(sizeof(Node));
    temp->val = x;
    temp->lnode = *list;
    if ((*list)->rnode != NULL) {
        temp->rnode = (*list)->rnode;
        ((*list)->rnode)->lnode = temp;
    }
    else {
        temp->rnode = *list;
    }
    (*list)->rnode = temp;
}
void add(Node ** list1, Node ** list2, Node ** list3) {
    Node * list1Rev = (Node *) malloc (sizeof(Node));
    Node * list2Rev = (Node *) malloc (sizeof(Node));
    Node * temp = (Node *) malloc (sizeof(Node));
    temp = (*list1)->rnode;
    while (temp->rnode != *list1)
        temp = temp->rnode;
    list1Rev = temp;
    temp = (*list2)->rnode;
    while (temp->rnode != *list2)
        temp = temp->rnode;
    list2Rev = temp;
    Node * head3 = (Node *) malloc(sizeof(Node));
    *list3 = head3;
    head3->rnode = NULL;

    int carry = 0;
    while ((list1Rev != *list1) || (list2Rev != *list2)) {
        // int val1 = list1Rev->val;
        // if (list1Rev == NULL)
        //     val1 = 0;
        // int val2 = list2Rev->val;
        // if (list2Rev == NULL)
        //     val2 = 0;
        int val1 = list1Rev->val;
        int val2 = list2Rev->val;

        int x = val1 + val2 + carry;
        if (x > 10) {
            carry = 1;
            x = x % 10;
        }
        else
            carry = 0;
        insertFrontCDLL(list3,x);
        list1Rev = list1Rev -> lnode;
        list2Rev = list2Rev -> lnode;
    }

    if (carry == 1) 
        insertFrontCDLL(list3,1);
}

int main() {
    int n1,n2;
    printf("Enter length of first number ");
    scanf("%d",&n1);
    printf("Enter length of second number ");
    scanf("%d",&n2);

    Node * list1 = (Node *) malloc (sizeof(Node));
    Node * list2 = (Node *) malloc (sizeof(Node));
    Node * list3 = (Node *) malloc (sizeof(Node));
    list3 = NULL;
    Node * head1 = (Node *) malloc (sizeof(Node));
    Node * head2 = (Node *) malloc (sizeof(Node));


    printf("Enter first number\n");
    input(list1,n1);
    head1->rnode = list1;
    list1 = head1;
    makeCirc(&list1);
    (list1->rnode)->lnode = list1;
    displayCirc(&list1);
    printf("Enter second number\n");
    input(list2,n2);
    head2->rnode = list2;
    list2 = head2;
    makeCirc(&list2);
    (list2->rnode)->lnode = list2;
    displayCirc(&list2);

    add(&list1,&list2,&list3);
    printf("Result of addition: ");
    displayCirc(&list3);

}