#include <iostream>
using namespace std;
typedef int ElemType;

typedef struct LNode {
	ElemType data;
	struct LNode *next;
}LNode, *LinkList;

void InitList(LinkList &L);
void List_HeadInsert(LinkList &L, ElemType value);
void List_TailInsert(LinkList &tailNode, ElemType value);
LNode *ListGetTailNode(LinkList &L);
LNode *GetElem(LinkList L, int i);
void PrintList(LinkList L);
void DestroyList(LinkList &L);
