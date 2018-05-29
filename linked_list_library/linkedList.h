#ifndef _LINKER_LIST_
#define _LINKER_LIST_

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

// struct define for all note on linked list
typedef struct node {
    void *data;
    struct node * next;
} node_t;

node_t *HEAD; // hold head node and tail node

/*
*  @Brif:  create new node with input data
*  @Param:  data is input
*  @Param: 
*
*
*  @return: return address of new node
*/
statis node_t* create_node (void *data);

/*
*  @Brif:  create new node with input data
*  @Param:  data is input
*  @Param:
*
*
*  @return: return address of new node
*/
void append_node (void *data);

/*
*  @Brif:  print data of node
*  @Param:  node that we want to show data
*  @Param:
*
*
*  @return: none
*/
void print_node (node_t *node) ;

/*
*  @Brif:  print data of node
*  @Param:  node that we want to show data
*  @Param:
*
*
*  @return: none
*/
void remove_node (node_t *node) ;

#endif /*_LINKER_LIST_*/