#include <iostream>
using namespace std;
typedef int ElemType;
typedef struct BiTNode
{
  public:
    ElemType data;
    struct BiTNode *lchild, *rchild;
    BiTNode(ElemType elem = 0)
        : data(elem), lchild(nullptr), rchild(nullptr) {}
} BiTNode, *BiTree;

void CreateTree(BiTree& tree)
{
	tree = new BiTNode();
	tree->data = 0;
	tree->lchild = nullptr;
	tree->rchild = nullptr;
}

void AddLeftChild(BiTree& tree, ElemType elem)
{
	BiTree tree_node = new BiTNode(elem);
	tree->lchild = tree_node;
}

void AddRightChild(BiTree& tree, ElemType elem)
{
	BiTree tree_node = new BiTNode(elem);
	tree->rchild = tree_node;
}

