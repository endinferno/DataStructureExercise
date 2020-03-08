#include "arrayStaticAlloc.h"

int main()
{
	ElemType arr1[] = {13,15,17,19};
	ElemType arr2[] = {4,6,8,20};
	ElemType temp = FindTwoListsMiddle(arr1, arr2, 4);
	cout << temp << endl;
    return 0;
}
