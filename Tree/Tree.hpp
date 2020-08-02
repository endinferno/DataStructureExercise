#include <iostream>
using namespace std;
#define MAX_TREE_SIZE 100
typedef int ElemType;
typedef struct
{
    ElemType data;
    int parent;
} PTNode;
typedef struct
{
    PTNode nodes[MAX_TREE_SIZE];
    int n;
} PTree;

typedef struct CSNode
{
    ElemType data;
    struct CSNode *firstChild, *nextSibling;
} CSNode, *CSTree;
