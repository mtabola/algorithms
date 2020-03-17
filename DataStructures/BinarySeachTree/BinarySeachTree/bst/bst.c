#include "bst.h"

session* createSession()
{
    session* ses = malloc(sizeof(session));
    if (ses == NULL)
    {
        printf("[!!!] Session didn't created\n\n");
        abort();
    }

    ses->root = NULL;
    ses->totalNodes = 0;

    printf("[+] Session is created\n\n");
    return ses;
}

void deleteSession(session* ses)
{
    if (ses == NULL)
    {
        printf("[!!!] Session didn't delete. NULL argument.\n\n");
        abort();
    }

    deleteBranch(ses->root);
    free(ses);
    printf("[+] Session is deleted.\n\n");
}

void deleteBranch(node* head)
{
    if (head != NULL)
    {
        deleteBranch(head->left);
        deleteBranch(head->right);
        free(head);
    }
}



node* findNode(session* ses, int key)
{
    node* elem = ses->root;
    while ((elem != NULL) && (elem->key != key))
    {
        if (key < elem->key)
            elem = elem->left;
        else
            elem = elem->right;
    }

    if (elem == NULL)
        printf("[!] Element %i haven't found. Return NULL.\n", key);

    return elem;
}



node* findMinNode(node* head)
{
    while (head->left != NULL)
        head = head->left;
    return head;
}

node* findMaxNode(node* head)
{
    while (head->right != NULL)
        head = head->right;
    return head;
}



node* findSuccessorNode(node* head)
{
    if (head->right != NULL)
        return findMinNode(head->right);
    
    node* forPrint = head;
    node* scsr = head->parent;
    
    while (scsr != NULL && head == scsr->right)
    {
        head = scsr;
        scsr = scsr->parent;
    }
    if (scsr == NULL)
        printf("[!] Node %i - [%p] is a large node in BST. Successor undefined.\n", forPrint->key, forPrint);

    return scsr;
}

node* findPredecessorNode(node* head)
{
    if (head->left != NULL)
        return findMaxNode(head->left);

    node* forPrint = head;
    node* scsr = head->parent;

    while (scsr != NULL && head == scsr->left)
    {
        head = scsr;
        scsr = scsr->parent;
    }
    if (scsr == NULL)
        printf("[!] Node %i - [%p] is a large node in BST. Successor undefined.\n", forPrint->key, forPrint);

    return scsr;
}



void insertNode(session* ses, int key)
{
    node* currentNode = NULL;
    node* nextNode = ses->root;

    node* elem = malloc(sizeof(node));
    elem->key = key;
    elem->left = elem->parent = elem->right = NULL;

    while (nextNode != NULL)
    {
        currentNode = nextNode;

        if (key < nextNode->key)
            nextNode = nextNode->left;
        else
            nextNode = nextNode->right;
    }
    
    elem->parent = currentNode;

    if (currentNode == NULL)
        ses->root = elem;
    else if (elem->key < currentNode->key)
        currentNode->left = elem;
    else
        currentNode->right = elem;
    ses->totalNodes++;
}

void transplant(session* ses, node* cur, node* next)
{
    if (cur->parent == NULL)
        ses->root = next;
    else if (cur == cur->parent->left)
        cur->parent->left = next;
    else
        cur->parent->right = next;

    if (next != NULL)
        next->parent = cur->parent;
}

void deleteNode(session* ses, int key)
{
    node* delNode = findNode(ses, key);

    if (delNode == NULL)
    {
        printf("[!] Node undefined. Nothing to delete.\n\n");
        return;
    }

    if (delNode->left == NULL)
        transplant(ses, delNode, delNode->right);
    else if (delNode->right == NULL)
        transplant(ses, delNode, delNode->left);
    else
    {
        node* y = findMinNode(delNode->right);
        if (y->parent != delNode)
        {
            transplant(ses, y, y->right);
            y->right = delNode->right;
            y->right->parent = y;
        }
        transplant(ses, delNode, y);
        y->left = delNode->left;
        y->left->parent = y;
    }

    free(delNode);
    ses->totalNodes--; 
}



void printSession(session* ses)
{
    if (ses->root == NULL)
    {
        puts("[!] Nothing to print!");
        return;
    }
        
    printf("Total nodes in BST - %i.\n", ses->totalNodes);
    printBranch(ses->root, 0);
}

void printBranch(node* root, int level)
{
    if (root == NULL)
    {
        padding('\t', level);
        puts("~");
    }
    else
    {
        printBranch(root->right, level + 1);
        padding('\t', level);
        printf("%i\n", root->key);
        printBranch(root->left, level + 1);
    }
}

void padding(char ch, int tabs) {
    for (int i = 0; i < tabs; i++)
        putchar(ch);
}