#include "BiSortTree.hpp"

int main()
{
    ElemType arr[] = {10, 5, 3, 1, 7, 9, 8};
    BiSTree tree = NULL;
    CreateBST(tree, arr, sizeof(arr) / sizeof(ElemType));
    PrintBST(tree);

    DeleteBSTNode(tree, 3);
    cout << endl;
    PrintBST(tree);
    InsertBST(tree, 3);

    DeleteBSTNode(tree, 9);
    cout << endl;
    PrintBST(tree);
    InsertBST(tree, 9);

    DeleteBSTNode(tree, 1);
    cout << endl;
    PrintBST(tree);
    InsertBST(tree, 1);

    DeleteBSTNode(tree, 10);
    cout << endl;
    PrintBST(tree);
    InsertBST(tree, 10);

    FreeBST(tree);
    return 0;
}
