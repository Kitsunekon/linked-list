#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// create struct "node".
typedef struct node
{
    int x;
    struct node *next;
}
node;

node *create (int value); // create an value with an integer of value.
bool search (node *head, int target); // linear search inside a linked list, and returns true when found target.
void insert(node *pointer, int value); // function to append a new node.

int main(void)
{
    node *y = create(2);
    printf("%i\n", y->x); // test 1

    // insert i, until specified value.
    for (int i = 3; i < 7; i++)
    {
        insert(y, i);
    }

    // search for a certain value 'i' within the linked list, until specified value.
    for (int i = 0; i < 7; i++)
    {
        if(search(y, i))
        {
            printf ("Found %i\n", i);
        }
        else
        {
            printf ("Cannot find %i\n", i);
        }
    }

    // print all values.
    printf ("list of values in the linked list: ");
    for (node* temp = y; temp != NULL; temp = temp->next)
    {
        printf("%i ", temp->x);
    }
    printf("\n");

    // free all nodes.
    while (y != NULL)
    {
        node *tmp = y->next;
        free(y);
        y = tmp;
    }
}

// function to initialize linked list.
node *create (int value)
{
    node *n = malloc(sizeof(node));
    if (n == NULL)
    {
        return 0;
    }
    n->x = value;
    return n;
    free(n);
}

// function to search value 'target'.
bool search (node *head, int target)
{
    for(node *tmp = head; tmp != NULL; tmp = tmp->next)
    {
        if (tmp->x == target)
        {
            return true;
        }
    }
    return false;
}

// function to append node.
void insert(node *pointer, int value)
{
    node *new_node = malloc(sizeof(node));
    if (new_node == NULL)
    {
        while (pointer != NULL)
        {
            node *tmp = pointer->next;
            free(pointer);
            pointer = tmp;
        }
        return;
    }

    new_node->x = value;
    new_node->next = pointer->next;
    pointer->next = new_node;
}
