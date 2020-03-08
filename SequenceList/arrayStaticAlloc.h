#include <iostream>
using namespace std;
#define MAXSIZE 50
typedef int ElemType;

typedef struct
{
    ElemType data[MAXSIZE];
    int length;
} SqList;

bool InitList(SqList &L);
int Length(SqList L);
bool ListInsert(SqList &L, int i, ElemType e);
bool ListDelete(SqList &L, int i, ElemType &e);
int LocateElem(SqList L, ElemType e);
ElemType GetElem(SqList L, int i);
void PrintList(SqList L);
bool Empty(SqList L);
bool DestroyList(SqList &L);
// Exercises
void ListDeleteLeast(SqList &L, ElemType &e);
void ListReverse(SqList &L);
void ListDeleteByValue(SqList &L, ElemType e);
void ListDeleteByRange(SqList &L, ElemType s, ElemType t);
void SequenceListDeleteDuplicate(SqList &L);
// need to delete the pointer by yourself
SqList *SequenceListCombineList(SqList L1, SqList L2);

void Reverse(ElemType arr[], int length);
void SwapListInArray(ElemType arr[], int m, int n);
void ListFindElement(SqList &L, ElemType e);

void ListCyclicMove(ElemType arr[], int length, int p);
ElemType FindTwoListsMiddle(ElemType arr1[], ElemType arr2[], int length);
