#include "withoutHeadNode.hpp"

void InitList(LinkList &L)
{
    L = nullptr;
}

void List_HeadInsert(LinkList &L, ElemType value)
{
    LNode *next = new LNode();
    next->data = value;
    if (L == nullptr)
        next->next = nullptr;
    else
        next->next = L;
    L = next;
}

void List_TailInsert(LinkList &tailNode, ElemType value)
{
    LNode *next = new LNode();
    next->data = value;
    next->next = nullptr;
    if (tailNode == nullptr)
        tailNode = next;
    else
        tailNode->next = next;
}

LNode *ListGetTailNode(LinkList &L)
{
	if (L == nullptr)
		return L;
	LNode *tempNode = L;
	while (tempNode->next != nullptr)
		tempNode = tempNode->next;
	return tempNode;
}

LNode *GetElem(LinkList L, int i)
{
	int cnt = 1;
	if (L == nullptr)
		return nullptr;
	while (L != nullptr)
	{
		if (cnt == i)
			return L;
		L = L->next;
		cnt++;
	}
	return L;
}

void PrintList(LinkList L)
{
    LinkList tempNode = L;
    while (tempNode != nullptr)
    {
        cout << tempNode->data << " ";
        tempNode = tempNode->next;
    }
    cout << endl;
}

void DestroyList(LinkList &L)
{
	if (L == nullptr)
		return;
	LNode *tempNode = L->next;
	while (tempNode != nullptr)
	{
		delete L;
		L = nullptr;
		L = tempNode;
		tempNode = tempNode->next;
	}
	tempNode = nullptr;
	L = nullptr;
}
