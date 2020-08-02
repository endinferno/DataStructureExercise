#include <iostream>
using namespace std;

typedef int ElemType;
typedef struct BiSTNode
{
    ElemType data;
    BiSTNode *lchild, *rchild;
} BiSTNode, *BiSTree;

int InsertBST(BiSTree &, ElemType);
void FreeBST(BiSTree &);

void CreateBSTRoot(BiSTree &tree, ElemType elem)
{
    tree->data = elem;
    tree->lchild = NULL;
    tree->rchild = NULL;
}

void CreateBST(BiSTree &tree, ElemType arr[], int size)
{
    tree = NULL;
    if (size <= 0)
        return;
    int i = 0;
    while (i < size)
    {
        InsertBST(tree, arr[i]);
        i++;
    }
}

void PrintBST(BiSTree tree)
{
    if (tree != NULL)
    {
        PrintBST(tree->lchild);
        printf("data: %d\n", tree->data);
        PrintBST(tree->rchild);
    }
}

BiSTree SearchBST(BiSTree T, ElemType elem)
{
    while (T != NULL && elem != T->data)
    {
        if (elem < T->data)
            T = T->lchild;
        else
            T = T->rchild;
    }
    return T;
}

int InsertBST(BiSTree &T, ElemType elem)
{
    if (T == NULL)
    {
        T = new BiSTNode();
        T->data = elem;
        T->lchild = NULL;
        T->rchild = NULL;
        return 1;
    }
    else if (T->data == elem)
    {
        return 0;
    }
    else if (T->data > elem)
    {
        return InsertBST(T->lchild, elem);
    }
    else
        return InsertBST(T->rchild, elem);
}

void Sort(ElemType arr[], int size)
{
    if (size <= 0)
        return;
    BiSTree tree = NULL;
    CreateBST(tree, arr, size);
    PrintBST(tree);
    FreeBST(tree);
}

void FreeBST(BiSTree &tree)
{
    if (tree == NULL)
        return;
    FreeBST(tree->lchild);
    FreeBST(tree->rchild);
    free(tree);
    tree = NULL;
}
