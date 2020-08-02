#include "ThreadTree.hpp"
#include <time.h>

int main()
{
    ThreadTree tree;
    CreateTree(tree, 1);
    AddLeftChild(tree, 2);
    AddRightChild(tree, 3);
    AddRightChild(tree->lchild, 4);
    AddLeftChild(tree->rchild, 5);
	CreateInThread(tree);
    clock_t startTime, endTime;
	startTime = clock();
    PrintThreadTree(tree);
	endTime = clock();
	cout << (double)(endTime - startTime) / CLOCKS_PER_SEC * 1000 << endl;
	startTime = clock();
	PrintTree(tree);
	endTime = clock();
	cout << (double)(endTime - startTime) / CLOCKS_PER_SEC * 1000 << endl;

    return 0;
}
