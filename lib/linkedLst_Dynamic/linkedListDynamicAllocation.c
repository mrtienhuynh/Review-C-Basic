/* this is lib for linked List, that using dynamic allocation to create new element
*
* @author: Huynh Vu Tien
* @email: mrtienhuynh@gmail.com
* @phone: (+84)946000894
* Toolchain: gcc.exe (tdm64-1) 4.9.2 - Copyright (C) 2014 Free Software Foundation, Inc.
* that is GCC intergrated in Dev-C 4.9.2
*/

/******INCLUDE******/
#include <linkedListDynamicAllocation.h>


/******DEFINITION******/


/******GLOBAL VARIABLE******/


/******STATIC FUNCITON******/


/******FUNCTION DEFINITION******/

/*@Brief: create linked list
* @ para: void* data: initial data for the first element of list
* @ return: linkedLst that allready hold initial node
*/
linkedLst_t *createLinkedLst (void* data){
    linkedLst_t *resultLst = (linkedLst_t*) malloc(sizeof(linkedLst_t));

    resultLst->pNext = NULL;
    resultLst->data = data;

    return resultLst;
}

/*@Brief: append new element to linked list
* @ para: void* data: data for new element
* @ return: linkedLst that allready hold previous linked list and new element
*/
linkedLst_t* appendElement2LinkedLst (linkedLst_t* linkedLst, void* data){
    linkedLst_t *newElement = createLinkedLst(data);

    if (linkedLst == NULL){
        linkedLst = newElement;
        return linkedLst;
    }
    while (linkedLst->pNext != NULL){
        linkedLst = linkedLst->pNext;
    }
    linkedLst->pNext = newElement;

    return linkedLst;
}

/*@Brief: release new element to linked list
* @ para: linkedLst_t* linkedLst
* @ return: none
*/
void releaseElementOfLinkedLst (linkedLst_t* linkedLst){
    free(linkedLst);
}

/*@Brief: release all element of linked list
* @ para: linkedLst_t* linkedLst
* @ return: none
*/
void releaseAllElementOfLinkedLst (linkedLst_t* linkedLst){
    linkedLst_t *buffNode = NULL;
    if (linkedLst == NULL){
        return;
    }
    if (linkedLst->pNext ==NULL){
        free(linkedLst);
        return;
    }
    while (linkedLst->pNext != NULL){
        buffNode = linkedLst->pNext;
        free(linkedLst);
        linkedLst = buffNode;
    }
}

/*@Brief: delete element from linked list using index
* @ para: linkedLst_t* linkedLst
* @ para: int index
* @ return: linkedLst affter remove element
*/
Enum_returnDelLstType deleteElementfromLinkedLstUsingIndex (linkedLst_t* linkedLst, int index){
    linkedLst_t *buffNode = NULL;
    linkedLst_t *previousNode = NULL;
    linkedLst_t *headNode = linkedLst;

    if (linkedLst == NULL){
        return NULL_LINKED_LST;
    }
    // remove the first element
    if (0 == index){
        buffNode = linkedLst->pNext;
        releaseElementOfLinkedLst(linkedLst);
        linkedLst = buffNode;
        return SUCCESSFUL;
    }

    for (int i = 0; i <= index ; i++){

        if (i == index){
            // last element in Lst
            if (linkedLst->pNext == NULL){
                // break link from previous to current Node
                previousNode ->pNext = NULL;
                releaseElementOfLinkedLst(linkedLst);
                return SUCCESSFUL;
            }
            else{
                // nomal Node of list, that is neither the first nor the last Node of List
                previousNode->pNext = linkedLst->pNext;
                releaseElementOfLinkedLst(linkedLst);
                return SUCCESSFUL;
            }
        }
        else{
            if (linkedLst->pNext == NULL){
                return ERROR_OUT_RANGE_INDEX;
            }
        }
        previousNode = linkedLst;
        linkedLst = linkedLst->pNext;
    }
}
