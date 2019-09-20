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
static void s_releaseElementOfLinkedLst (linkedLst_t* linkedLst){
    free(linkedLst);
}

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

/*@Brief: release element from linked list
* @ para: linkedLst_t* linkedLst
* @ return: none
*/
void releaseElementOfLinkedLst (linkedLst_t** linkedLst){
    free(*linkedLst);
}

/*@Brief: release all element of linked list
* @ para: linkedLst_t* linkedLst
* @ return: none
*/
void releaseAllElementOfLinkedLst (linkedLst_t** linkedLst){
    linkedLst_t *buffNode = NULL;
    linkedLst_t *headNode = *linkedLst;
    linkedLst_t *previousNode = NULL;

    if (*linkedLst == NULL){
        return;
    }
    // lst just have one element
    if ((*linkedLst)->pNext ==NULL){
        free(*linkedLst);
        return;
    }

    while (*linkedLst != NULL){
        // normal element, that not the last element
        if ((*linkedLst)->pNext != NULL){
            buffNode = (*linkedLst)->pNext;
            free(*linkedLst);
            *linkedLst = buffNode;
        }
        else {
            // the last element in list
            free(*linkedLst);
            break;
        }
    }
    // *linkedLst = headNode;
}

/*@Brief: delete element from linked list using index
* @ para: linkedLst_t* linkedLst
* @ para: int index
* @ return: linkedLst affter remove element
*/
Enum_returnDelLstType deleteElementfromLinkedLstUsingIndex (linkedLst_t** linkedLst, int index){
    linkedLst_t *buffNode = NULL;
    linkedLst_t *previousNode = NULL;
    linkedLst_t *headNode = *linkedLst;
    int sizeOfLst = getSizeOfLinkedLst(*linkedLst);
    if (linkedLst == NULL){
        return NULL_LINKED_LST;
    }
    // remove the first element
    if (0 == index){
        buffNode = (*linkedLst)->pNext;
        s_releaseElementOfLinkedLst(*linkedLst);
        *linkedLst = buffNode;
        return SUCCESSFUL;
    }

    for (int i = 0; i <= index ; i++){

        if (i == index){
            if (i > sizeOfLst - 1 ){
                return ERROR_OUT_RANGE_INDEX;
            }
            // last element in Lst
            if ((*linkedLst)->pNext == NULL){
                // break link from previous to current Node
                previousNode ->pNext = NULL;
                s_releaseElementOfLinkedLst(*linkedLst);
                *linkedLst = headNode;
                return SUCCESSFUL;
            }
            else{
                // nomal Node of list, that is neither the first nor the last Node of List
                previousNode->pNext = (*linkedLst)->pNext;
                s_releaseElementOfLinkedLst(*linkedLst);
                *linkedLst = headNode;
                return SUCCESSFUL;
            }
        }
        else{
            if ((*linkedLst)->pNext == NULL){
                *linkedLst = headNode;
                return ERROR_OUT_RANGE_INDEX;
            }
        }
        previousNode = *linkedLst;
        *linkedLst = (*linkedLst)->pNext;
    }
    *linkedLst = headNode;
    return NOT_FOUND_IN_LST;
}


/*@Brief: delete element from linked list using compare data
* @ para: linkedLst_t* linkedLst
* @ para: int index
* @para:  bool (*callBackFunction)(void *, void* )
*           true: remove the first element have equal data.
            false: donot thing
* @ return: Enum_returnDelLstType
*/
Enum_returnDelLstType deleteElementfromLinkedLst (linkedLst_t** linkedLst, void* data, bool (*callBackFunction)(void *, void* )){
    linkedLst_t *buffNode = NULL;
    linkedLst_t *previousNode = NULL;
    linkedLst_t *headNode = *linkedLst;

    if (*linkedLst == NULL){
        return NULL_LINKED_LST;
    }

    while (*linkedLst != NULL){
        if (callBackFunction ((*linkedLst)->data, data) == true){
            // match element is a tail
            if ((*linkedLst)->pNext == NULL){
                if (headNode != *linkedLst){
                    previousNode->pNext = NULL;
                }
                s_releaseElementOfLinkedLst(*linkedLst);
                *linkedLst = headNode;
                return SUCCESSFUL;
            }
            else{
                if (headNode == *linkedLst){
                    previousNode = *linkedLst;
                    *linkedLst = (*linkedLst)->pNext;
                    s_releaseElementOfLinkedLst(previousNode);
                }
                else {
                    previousNode->pNext = (*linkedLst)->pNext;
                    s_releaseElementOfLinkedLst(*linkedLst);
                }
                *linkedLst = headNode;
                return SUCCESSFUL;
            }
        }
        previousNode = *linkedLst;
        *linkedLst = (*linkedLst)->pNext;
    }

    return SUCCESSFUL;
}

/*@Brief: get all number of element that linked list contain
* @ para: linkedLst_t* linkedLst
* @ return: size of list
*/
int getSizeOfLinkedLst (linkedLst_t* linkedLst){
    int result = 0;
    while (linkedLst != NULL){
        result++;
        linkedLst = linkedLst->pNext;
    }
    return result;
}


/*@Brief: swap element of linked list
* @ para: linkedLst_t* linkedLst
* @ para: int x
* @ para: int y
* @ return: none
*/
void swapElementOfLinkedLst (linkedLst_t** linkedLst, int x, int y){
    linkedLst_t *buffNode = NULL;
    linkedLst_t *previousNode = NULL;
    linkedLst_t *headNode = *linkedLst;

    if (x == y) {
        return;
    }
    if (*linkedLst == NULL){
        return;
    }

}