#include "linkedList.h"


node_t* create_node (void *data)
{
    node_t *newNode = malloc(sizeof(node_t));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void append_node (void *data)
{
    node_t *newNode = create_node(data);
    if ( HEAD == NULL)   // empty list
    {
        HEAD = newNode;
    }
    else
    {
        newNode->next = HEAD;
        HEAD = newNode;
    }
}

