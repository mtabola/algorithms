#include "bst/bst.h"

int main()
{
    session* ses = createSession();

    insertNode(ses, 10);
    insertNode(ses, 4);
    insertNode(ses, 14);
    insertNode(ses, 16);
    insertNode(ses, 8);
    insertNode(ses, 11);
    insertNode(ses, 18);
    insertNode(ses, 5);
    insertNode(ses, 12);
    insertNode(ses, 6);
    insertNode(ses, 15);
    insertNode(ses, 20);
    insertNode(ses, 2);
    insertNode(ses, 1);
    insertNode(ses, 3);


    node* pred = findPredecessorNode(ses->root->right);
    node* suc = findSuccessorNode(ses->root->right);

    printf("The predecessor of %i ([%p]) is a %i ([%p])\n", ses->root->right->key, ses->root->right, pred->key, pred);
    printf("The successor of %i ([%p]) is a %i ([%p])\n", ses->root->right->key, ses->root->right, suc->key, suc);

    node* uf = findNode(ses, 21);
    node* nuf = findNode(ses, 6);

    printf("Found node - %i ([%p])\n", nuf->key, nuf);

    node* max = findMaxNode(ses->root->left);
    node* min = findMinNode(ses->root->left);

    printf("Max element if %i ([%p]) is a head - %i ([%p])\n", ses->root->left->key, ses->root->left, max->key, max);
    printf("Min element if %i ([%p]) is a head - %i ([%p])\n", ses->root->left->key, ses->root->left, min->key, min);


    deleteNode(ses, 1);
    deleteNode(ses, 14);
    deleteNode(ses, 16);


    printSession(ses);


    deleteSession(ses);
    return 0;
}