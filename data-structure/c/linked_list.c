#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

// function prototype
void printLinkedList(struct node *p);


int main(void) {
    // initialize struct
    struct node *head;
    struct node *one = NULL;
    struct node *two = NULL;
    struct node *three = NULL;

    // allocate memory
    one = malloc(sizeof(struct node));
    two = malloc(sizeof(struct node));
    three = malloc(sizeof(struct node));

    // assign data value
    one->data = 1;
    two->data = 2;
    three->data = 3;

    // connect nodes
    one->next = two;
    two->next = three;
    three->next = NULL;

    // save address of first node in head
    head = one;
    printLinkedList(head);

    return 0;
}

void printLinkedList(struct node *p) {
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
}
