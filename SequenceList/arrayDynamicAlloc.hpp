#include <iostream>
using namespace std;
#define InitSize 100
typedef int ElemType;

typedef struct
{
    ElemType *data;
    int MAXSIZE, length;
} SqList;

void InitList(SqList &sqlist);
void PrintList(SqList sqlist);
