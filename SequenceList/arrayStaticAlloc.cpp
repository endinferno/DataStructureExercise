#include "arrayStaticAlloc.h"

bool InitList(SqList &L)
{
    L.length = 0;
    return true;
}

int Length(SqList L)
{
    return L.length;
}

bool ListInsert(SqList &L, int i, ElemType e)
{
    if (i < 1 || i > L.length + 1)
        return false;
    if (L.length >= MAXSIZE)
        return false;
    for (int j = L.length; j >= i; j--)
        L.data[j] = L.data[j - 1];
    L.data[i - 1] = e;
    L.length++;
    return true;
}

bool ListDelete(SqList &L, int i, ElemType &e)
{
    if (i < 1 || i > L.length)
        return false;
    e = L.data[i - 1];
    for (int j = i; j < L.length; j++)
        L.data[j - 1] = L.data[j];
    L.length--;
    return true;
}

int LocateElem(SqList L, ElemType e)
{
    int i;
    for (i = 0; i < L.length; i++)
        if (L.data[i] == e)
            return i + 1;
    return 0;
}

ElemType GetElem(SqList L, int i)
{
    if (i < 1 || i > L.length)
        return (-1);
    return L.data[i];
}

void PrintList(SqList L)
{
    if (L.length == 0)
    {
        cout << "The list is empty" << endl;
        return;
    }

    for (int i = 0; i < L.length; ++i)
        printf("%d ", L.data[i]);
    printf("\n");
}

bool Empty(SqList L)
{
    return L.length == 0;
}

bool DestroyList(SqList &L)
{
    L.length = 0;
    return true;
}

// Exercises
void ListDeleteLeast(SqList &L, ElemType &e)
{
    if (L.length == 0)
    {
        cout << "Error: The list is empty" << endl;
        exit(1);
    }
    int minOrd = -1;
    e = 999999;

    for (int i = 0; i < L.length; ++i)
    {
        if (L.data[i] < e)
        {
            e = L.data[i];
            minOrd = i;
        }
    }
    L.length--;
    L.data[minOrd] = L.data[L.length];
}

void ListReverse(SqList &L)
{
    ElemType temp;
    for (int i = 0; i < L.length / 2; ++i)
    {
        temp = L.data[i];
        L.data[i] = L.data[L.length - i - 1];
        L.data[L.length - i - 1] = temp;
    }
}

void ListDeleteByValue(SqList &L, ElemType e)
{
    int moveStep = 0;
    for (int i = 0; i < L.length; ++i)
    {
        if (L.data[i] == e)
        {
            moveStep++;
            continue;
        }

        L.data[i - moveStep] = L.data[i];
    }
    L.length -= moveStep;
}

void ListDeleteByRange(SqList &L, ElemType s, ElemType t)
{
    if (s >= t)
    {
        cout << "Error: s should bigger than t." << endl;
        exit(1);
    }
    if (L.length == 0)
    {
        cout << "Error: SqList L should not be empty" << endl;
        exit(1);
    }
    int moveStep = 0;
    for (int i = 0; i < L.length; ++i)
    {
        if (L.data[i] >= s && L.data[i] <= t)
        {
            moveStep++;
            continue;
        }
        else
            L.data[i - moveStep] = L.data[i];
    }
    L.length -= moveStep;
}

void ListDeleteDuplicate(SqList &L)
{
    int j = 0;
    for (int i = 1; i < L.length; ++i)
    {
        if (L.data[i] != L.data[j])
            L.data[++j] = L.data[i];
    }
    L.length = j + 1;
}

SqList *SequenceListCombineList(SqList L1, SqList L2)
{
    if (L1.length + L2.length >= MAXSIZE)
    {
        cout << "Out of Limit" << endl;
        exit(1);
    }
    SqList *sqlist = new SqList();
    InitList(*sqlist);
    int i = 0, j = 0;
    while (i < L1.length && j < L2.length)
    {
        if (L1.data[i] < L2.data[j])
            ListInsert(*sqlist, sqlist->length + 1, L1.data[i++]);
        else
            ListInsert(*sqlist, sqlist->length + 1, L2.data[j++]);
    }
    if (i == L1.length)
    {
        while (j < L2.length)
            ListInsert(*sqlist, sqlist->length + 1, L2.data[j++]);
    }
    else
    {
        while (i < L1.length)
            ListInsert(*sqlist, sqlist->length + 1, L1.data[i++]);
    }
    return sqlist;
}

void Reverse(ElemType arr[], int length)
{
    ElemType temp;
    for (int i = 0; i < length / 2; ++i)
    {
        temp = arr[i];
        arr[i] = arr[length - i - 1];
        arr[length - i - 1] = temp;
    }
}

void SwapListInArray(ElemType arr[], int m, int n)
{
    Reverse(arr, m);
    Reverse(arr + m, n);
    Reverse(arr, m + n);
}

void ListFindElement(SqList &L, ElemType e)
{
    int left = 0, right = L.length;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (L.data[mid] == e)
        {
            if (mid == L.length - 1)
                return;
            ElemType temp = L.data[mid];
            L.data[mid] = L.data[mid + 1];
            L.data[mid + 1] = temp;
            return;
        }
        else if (L.data[mid] < e)
            left = mid + 1;
        else if (L.data[mid] > e)
            right = mid - 1;
    }
    ListInsert(L, left + 1, e);
}

void ListCyclicMove(ElemType arr[], int length, int p)
{
    Reverse(arr, length);
    Reverse(arr, length - p);
    Reverse(arr + length - p, p);
}

ElemType FindTwoListsMiddle(ElemType arr1[], ElemType arr2[],
                            int length)
{
    int midOrd = length;
    int i = 0, j = 0, cnt = 0;
    while (i < length && j < length)
    {
        cnt++;
        if (arr1[i] < arr2[j])
        {
            if (cnt == midOrd)
                return arr1[i];
            i++;
        }
        else
        {
            if (cnt == midOrd)
                return arr2[j];
            j++;
        }
    }
	if (i == length)
		return arr2[j];
	else
		return arr1[i];
}
