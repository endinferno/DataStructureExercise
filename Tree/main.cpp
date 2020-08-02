#include "BiTree.hpp"

int main(int argc, char *argv[])
{
	BiTree tree = nullptr;
	CreateTree(tree);
	tree->data = 123;
	cout << tree->data << endl;

	return 0;
}
