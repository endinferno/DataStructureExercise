#include "withoutHeadNode.hpp"

int main()
{
	LinkList L = nullptr;
	InitList(L);
	List_HeadInsert(L, 1);
	List_HeadInsert(L, 1);
	List_HeadInsert(L, 1);
	List_HeadInsert(L, 1);
	PrintList(L);
	DestroyList(L);
    return 0;
}
