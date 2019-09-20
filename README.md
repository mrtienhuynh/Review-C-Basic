# Review-C-Basic
This repository involves some basic example for C such as linker list, queue, stack.

20/09/2019 add Linked List + demo for linkedList using dynamic allocation
    Detail:
        file: linkedListDynamicAllocation.h and linkedListDynamicAllocation.c
        list funciton:
                            /******LIBRARY API******/
                linkedLst_t* createLinkedLst (void* data);
                linkedLst_t* appendElement2LinkedLst (linkedLst_t* linkedLst, void* data);
                void releaseElementOfLinkedLst (linkedLst_t* linkedLst);
                void releaseAllElementOfLinkedLst (linkedLst_t* linkedLst);
                Enum_returnDelLstType deleteElementfromLinkedLstUsingIndex (linkedLst_t* linkedLst, int index);
        demo: main.c