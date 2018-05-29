#include "linkedList.h"

void main (void)
{
    char a1[10] = "Node 1 \n";
    char a2[10] = "Node 2 \n";
    char a3[10] = "Node 3 \n";
    node_t *slist;
    append_node(a1);
    append_node(a2);
    append_node(a3);
    slist = HEAD;
    int i = 0;
    for (i = 0; i < 3; ++i)
    {
        /* code */
        printf("%s\n",  slist->data);
        slist = slist->next;
    }
}