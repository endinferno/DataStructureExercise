#include <iostream>
using namespace std;
typedef int ElemType;
typedef struct ThreadNode
{
  public:
    ElemType data;
    struct ThreadNode *lchild, *rchild;
    int ltag, rtag;
} ThreadNode, *ThreadTree;

void CreateTree(ThreadTree &tree, ElemType elem)
{
    tree = new ThreadNode();
    tree->data = elem;
    tree->lchild = tree->rchild = NULL;
    tree->ltag = tree->rtag = 0;
}

void AddLeftChild(ThreadTree &tree, ElemType elem)
{
    ThreadTree tree_node = new ThreadNode();
    tree_node->data = elem;
    tree->lchild = tree_node;
    tree->ltag = tree->rtag = 0;
}

void AddRightChild(ThreadTree &tree, ElemType elem)
{
    ThreadTree tree_node = new ThreadNode();
    tree_node->data = elem;
    tree->rchild = tree_node;
    tree->ltag = tree->rtag = 0;
}

// when use this function, p should be tree root
void InThread(ThreadTree &p, ThreadTree &pre)
{
    if (p != NULL)
    {
        InThread(p->lchild, pre);
        if (p->lchild == NULL)
        {
            p->lchild = pre;
            p->ltag = 1;
        }
        if (pre != NULL && pre->rchild == NULL)
        {
            pre->rchild = p;
            pre->rtag = 1;
        }
        pre = p;
        InThread(p->rchild, pre);
    }
}

// Print Tree
// 一旦线索二叉树完成了构建
// 则不能用平时遍历二叉树的方式去进行遍历
// 因为很多节点的左右节点代表了不同的含义
// 并且可以使用线索二叉树的特性去进行遍历
void PrintTree(ThreadTree p)
{
    if (p != NULL)
    {
        if (p->ltag == 0)
            PrintTree(p->lchild);
        printf("data: %d, LTag: %d, RTag: %d\n", p->data, p->ltag, p->rtag);
        if (p->rtag == 0)
            PrintTree(p->rchild);
    }
}

ThreadTree FirstNode(ThreadTree p)
{
    while (p->ltag == 0)
        p = p->lchild;
    return p;
}

ThreadTree NextNode(ThreadTree p)
{
    if (p->rtag == 0)
        return FirstNode(p->rchild);
    else
        return p->rchild;
}

void CreateInThread(ThreadTree T)
{
    ThreadTree pre = NULL;
    if (T != NULL)
    {
        InThread(T, pre);
        pre->rchild = NULL;
        pre->rtag = 1;
    }
}

void PrintThreadTree(ThreadTree T)
{
    ThreadTree p = T;
    while (p->ltag == 0)
        p = p->lchild;
    for (; p != NULL;)
    {
        printf("data: %d\n", p->data);
        if (p->rtag == 0)
            p = FirstNode(p->rchild);
        else
            p = p->rchild;
    }
}
