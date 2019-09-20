#include <stdio.h>
#include <linkedListDynamicAllocation.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int arr[10] = {1,3,2,5,4,6,7,8,9,11};


void bulble_sort(void);

int main(int argc, char** argv) {

	int a = 4;
	int b =5;
	int c =6;
	int d =7;

	linkedLst_t *lst = createLinkedLst((void*)&a);
	appendElement2LinkedLst(lst, (void*)&b);
	appendElement2LinkedLst(lst, (void*)&c);
	appendElement2LinkedLst(lst, (void*)&d);
	printf("gia tri data cua initial node = %d \n", *((int*)lst->data));
	printf("gia tri data cua initial node = %d \n", *((int*)lst->pNext->data));
	printf("gia tri data cua initial node = %d \n", *((int*)lst->pNext->pNext->data));
	printf("gia tri data cua initial node = %d \n", *((int*)lst->pNext->pNext->pNext->data));
	deleteElementfromLinkedLstUsingIndex(lst, 2); // set parameter index of deleteElementfromLinkedLstUsingIndex() equal 2, that make this met segmentation fall
	printf("gia tri data cua initial node = %d", *((int*)lst->data));
	printf("gia tri data cua initial node = %d", *((int*)lst->pNext->data));
	printf("gia tri data cua initial node = %d \n", *((int*)lst->pNext->pNext->data));
	printf("gia tri data cua initial node = %d \n", *((int*)lst->pNext->pNext->pNext->data));
	return 0;
}

