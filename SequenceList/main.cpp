#include "arrayStaticAlloc.h"

int main()
{
    SqList L;
    InitList(L);
    ListInsert(L, 1, 6);
    ListInsert(L, 1, 3);
    ListInsert(L, 1, 2);
    ListInsert(L, 1, 1);
    PrintList(L);
    cout << endl;
    ListFindElement(L, 4);
    cout << endl;
    PrintList(L);
    DestroyList(L);
    return 0;
}
