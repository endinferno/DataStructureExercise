#include "arrayDynamicAlloc.hpp"

void InitList(SqList &sqlist)
{
    sqlist.MAXSIZE = 200;
    sqlist.length = 0;
    sqlist.data = new ElemType[InitSize];
    for (int i = 0; i < 10; ++i)
        sqlist.data[i] = i;
}

void PrintList(SqList sqlist)
{
    for (int i = 0; i < sqlist.length; ++i)
        cout << sqlist.data[i] << " ";
    cout << endl;
}
