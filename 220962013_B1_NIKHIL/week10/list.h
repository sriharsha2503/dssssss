//list functions for DLL

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node *rnode;
    struct node *lnode;
} node ;

typedef struct node Node;

void insertNode(Node * prev,int x) {
    Node * new = (Node *) malloc(sizeof(Node));
    new->val = x;
    new->rnode = prev->rnode;
    new->lnode = prev;
    prev->rnode = new;
}

void insertEnd(Node ** list, int x) {
    Node * temp = (Node *) malloc(sizeof(Node));
    Node * new = (Node *) malloc(sizeof(Node));
    temp = *list;
    while (temp->rnode != NULL) 
        temp = temp->rnode;
    new->val = x;
    new->lnode = temp;
    temp->rnode = new;
    new->rnode = NULL;
}

void insertFront(Node ** list, int x) {
    Node * temp = (Node *) malloc(sizeof(Node));
    temp->val = x;
    temp->lnode = NULL;
    if (*list != NULL) {
        temp->rnode = *list;
        (*list)->lnode = temp;
    }
    *list = temp;
}

void display(Node *node) {
    printf("The list is: ");
    while(node != NULL) {
        printf("%d ",node->val);
        node = node->rnode;
    }
    printf("\n");
}

void input(Node *node,int n) {
    int i,temp;
    for (i=0;i<n;i++) {
        printf("Enter value to add ");
        scanf("%d",&temp);
        if (i == 0) {
            node->val = temp;
            node->rnode = NULL;
            node->lnode = NULL;
            continue;
        }
        insertNode(node,temp);
        node = node->rnode;
    }
}

void deleteNode(Node ** list, Node * del) {
    if (*list == del) {
        *list = (*list)->rnode;
        (*list)->lnode = NULL;
    }
    else {
        Node * temp = (Node *) malloc(sizeof(Node));
        temp = *list;
        while (temp->rnode != NULL) {
            if (temp->rnode == del) {
                temp->rnode = del->rnode;
                del->lnode = temp;
                break;
            }
            temp = temp->rnode;
        }
    }
    printf("Value deleted: %d",del->val);
    free(del);
}
