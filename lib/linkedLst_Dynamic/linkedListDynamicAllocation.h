/* this is lib for linked List, that using dynamic allocation to create new element
*
* @author: Huynh Vu Tien
* @email: mrtienhuynh@gmail.com
* @phone: (+84)946000894
* Toolchain: gcc.exe (tdm64-1) 4.9.2 - Copyright (C) 2014 Free Software Foundation, Inc.
* that is GCC intergrated in Dev-C 4.9.2
*/
#ifndef LINKED_LIST_DYNAMIC_ALLOCATION_H
#define LINKED_LIST_DYNAMIC_ALLOCATION_H

/******INCLUDE******/
#include <stdio.h>
#include <stdlib.h>


/******DEFINITION******/
typedef struct linkedLst {
    struct linkedLst *pNext;
    void *data;
} linkedLst_t;

typedef enum returnDelLstType{
    NULL_LINKED_LST,
    ERROR_OUT_RANGE_INDEX,
    ERROR_OTHER,
    SUCCESSFUL
} Enum_returnDelLstType
/******GLOBAL VARIABLE******/



/******STATIC FUNCITON******/



/******LIBRARY API******/

/*@Brief: create linked list
* @ para: void* data: initial data for the first element of list
* @ return: linkedLst that allready hold initial node
*/
linkedLst_t* createLinkedLst (void* data);

/*@Brief: append new element to linked list
* @ para: void* data: data for new element
* @ para: linkedLst_t* linkedLst
* @ return: linkedLst that allready hold previous linked list and new element
*/
linkedLst_t* appendElement2LinkedLst (linkedLst_t* linkedLst, void* data);

/*@Brief: release element of linked list
* @ para: linkedLst_t* linkedLst
* @ return: none
*/
void releaseElementOfLinkedLst (linkedLst_t* linkedLst);

/*@Brief: release all element of linked list
* @ para: linkedLst_t* linkedLst
* @ return: none
*/
void releaseAllElementOfLinkedLst (linkedLst_t* linkedLst);

/*@Brief: delete element from linked list using index
* @ para: linkedLst_t* linkedLst
* @ para: int index
* @ return: Enum_returnDelLstType
*/
Enum_returnDelLstType deleteElementfromLinkedLstUsingIndex (linkedLst_t* linkedLst, int index);


#endif
