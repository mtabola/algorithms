#include "rbt.h"

session* createSession()
{
    session* ses = calloc(1, sizeof(session));

    if (ses == NULL)
    {
        puts("[!!!] Session was not created.");
        return NULL;
    }

    ses->saveNull = calloc(1, sizeof(node));

    if (ses->saveNull == NULL)
    {
        puts("[!!!] SaveNull was not created.");
        return NULL;
    }

    ses->saveNull->color = BLACK;
    ses->saveNull->parent = ses->saveNull->right = ses->saveNull->left = NULL;
    ses->saveNull->key = 0;

    ses->root = ses->saveNull;
    ses->nodeQty = 0;

    return ses;
}

void deleteSession(session* ses)
{

    if (ses == NULL)
    {
        puts("[!!!] Session didn't delete. NULL argument.\n");
        abort();
    }

    deleteBranch(ses, ses->root);


    free(ses->saveNull);
    free(ses);
    puts("[+] Session is deleted.\n");

}

void deleteBranch(session* ses, node* head)
{
    if (ses == NULL)
    {
        puts("[!!!]Session is not available.");
        return;
    }

    if (head != ses->saveNull)
    {
        deleteBranch(ses, head->left);
        deleteBranch(ses, head->right);
        free(head);
    }
}



node* findNode(const session* const ses, const int key)
{
    if (ses == NULL)
    {
        puts("[!!!]Session is not available.");
        return NULL;
    }

    node* currNode = ses->root;
    while ((currNode->key != key) && (currNode != ses->saveNull))
    {
        if (key > currNode->key)
            currNode = currNode->right;
        else
            currNode = currNode->left;
    }

    if (currNode == ses->saveNull)
        printf("[!] Element %i haven't found. Return NULL.\n", key);

    return currNode;
}



node* findMinNode(const session* const ses, node* head)
{
    if (ses == NULL)
    {
        puts("[!!!]Session is not available.");
        return NULL;
    }

    while (head->left != ses->saveNull)
        head = head->left;
    return head;
}

node* findMaxNode(const session* const ses, node* head)
{
    if (ses == NULL)
    {
        puts("[!!!]Session is not available.");
        return NULL;
    }

    while (head->right != ses->saveNull)
        head = head->right;
    return head;
}


void leftRotation(session* ses, node* x)
{
    if (ses == NULL)
    {
        puts("[!!!]Session is not available.");
        return;
    }

    node* y = x->right;
    x->right = y->left;

    if (y->left != ses->saveNull)
        y->left->parent = x;
    y->parent = x->parent;

    if (x->parent == ses->saveNull)
        ses->root = y;
    else if (x == x->parent->left)
        x->parent->left = y;
    else
        x->parent->right = y;
    y->left = x;
    x->parent = y;
}

void rightRotation(session* ses, node* y)
{
    if (ses == NULL)
    {
        puts("[!!!]Session is not available.");
        return;
    }

    node* x = y->left;
    y->left = x->right;

    if (x->right != ses->saveNull)
        x->right->parent = y;
    x->parent = y->parent;

    if (y->parent == ses->saveNull)
        ses->root = x;
    else if (y == y->parent->left)
        y->parent->left = x;
    else
        y->parent->right = x;
    x->right = y;
    y->parent = x;
}


void insertNode(session* ses, const int key)
{
    if (ses == NULL)
    {
        puts("[!!!]Session is not available.");
        return;
    }

    node* currNode = ses->saveNull;
    node* nextNode = ses->root;
    node* newNode = (node*)calloc(1, sizeof(node));

    if (newNode == NULL)
    {
        puts("[!!!]Node didn't created.");
        return;
    }


    newNode->key = key;

    while (nextNode != ses->saveNull)
    {
        currNode = nextNode;
        if (nextNode->key > key)
            nextNode = nextNode->left;
        else
            nextNode = nextNode->right;
    }

    if (currNode == ses->saveNull)
        ses->root = newNode;

    else if (currNode->key > key)
        currNode->left = newNode;

    else
        currNode->right = newNode;

    newNode->parent = currNode;
    newNode->color = RED;
    newNode->left = newNode->right = ses->saveNull;

    ses->nodeQty++;

    insertFixup(ses, newNode);
}

void insertFixup(session* ses, node* z)
{
    if (ses == NULL)
    {
        puts("[!!!]Session is not available.");
        return;
    }
    while (z->parent->color == RED)
    {
        if (z->parent == z->parent->parent->left)
        {
            node* uncle = z->parent->parent->right;

            if (uncle->color == RED)
            {
                z->parent->color = BLACK;
                uncle->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            }
            else
            {
                if (z == z->parent->right)
                {
                    z = z->parent;
                    leftRotation(ses, z);
                }

                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                rightRotation(ses, z->parent->parent);
            }
        }
        else
        {
            node* uncle = z->parent->parent->left;

            if (uncle->color == RED)
            {
                z->parent->color = BLACK;
                uncle->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            }
            else
            {
                if (z == z->parent->left)
                {
                    z = z->parent;
                    rightRotation(ses, z);
                }

                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                leftRotation(ses, z->parent->parent);
            }
        }
    }

    ses->root->color = BLACK;
}


void transplant(session* ses, node* u, node* v)
{
    if (ses == NULL)
    {
        puts("[!!!]Session is not available.");
        return;
    }
    if (u->parent == ses->saveNull)
        ses->root = u;

    else if (u == u->parent->left)
        u->parent->left = v;

    else
        u->parent->right = v;
    v->parent = u->parent;
}

void deleteNode(session* ses, const int key)
{
    if (ses == NULL)
    {
        puts("[!!!]Session is not available.");
        return;
    }

    node* z = findNode(ses, key);

    if (z == ses->saveNull)
    {
        puts("[!!!]Node didn't found. Removing is not possible.");
        return;
    }

    node* y = z;
    node* x = ses->saveNull;
    colors yOrigColor = y->color;

    if (z->left == ses->saveNull)
    {
        x = z->right;
        transplant(ses, z, z->right);
    }
    else if (z->right == ses->saveNull)
    {
        x = z->left;
        transplant(ses, z, z->left);
    }
    else
    {
        y = findMinNode(ses, z->right);
        yOrigColor = y->color;
        x = y->right;
        if (y->parent == z)
        {
            x->parent = y;
        }
        else
        {
            transplant(ses, y, y->right);
            y->right = z->right;
            y->right->parent = y;
        }
        transplant(ses, z, y);
        y->left = z->left;
        y->left->parent = y;
        y->color = z->color;
    }
    if (yOrigColor == BLACK)
        deleteFixup(ses, x);
    ses->nodeQty--;
}

void deleteFixup(session* ses, node* x)
{
    if (ses == NULL)
    {
        puts("[!!!]Session is not available.");
        return;
    }

    node* bro = NULL;

    while (x != ses->root && x->color == BLACK)
    {
        if (x == x->parent->left)
        {
            bro = x->parent->right;
            if (bro->color == RED)
            {
                bro->color = BLACK;
                x->parent->color = RED;
                leftRotation(ses, x->parent);
                bro = x->parent->right;
            }
            if ((bro->left->color == BLACK) && (bro->right->color == BLACK))
            {
                bro->color = RED;
                x = x->parent;
            }
            else if (bro->right->color == BLACK)
            {
                bro->left->color = BLACK;
                bro->color = RED;
                rightRotation(ses, bro);
                bro = x->parent->right;

            }
            bro->color = x->parent->color;
            x->parent->color = BLACK;
            bro->right->color = BLACK;
            leftRotation(ses, x->parent);
            x = ses->root;
        }
        else
        {
            bro = x->parent->left;
            if (bro->color == RED)
            {
                bro->color = BLACK;
                x->parent->color = RED;
                rightRotation(ses, x->parent);
                bro = x->parent->left;
            }
            if ((bro->left->color == BLACK) && (bro->right->color == BLACK))
            {
                bro->color = RED;
                x = x->parent;
            }
            else if (bro->left->color == BLACK)
            {
                bro->right->color = BLACK;
                bro->color = RED;
                leftRotation(ses, bro);
                bro = x->parent->left;

            }
            bro->color = x->parent->color;
            x->parent->color = BLACK;
            bro->left->color = BLACK;
            rightRotation(ses, x->parent);
            x = ses->root;
        }
    }
    x->color = BLACK;
}

void printSession(session* ses)
{
    char* names[8]  = {"BLACK", "RED"};

    if (ses->root == ses->saveNull)
    {
        puts("[!] Nothing to print!");
        return;
    }

    printf("Total nodes in BST - %i.\n", ses->nodeQty);
    printBranch(ses->root, 0, names);
}

void printBranch(node* root, int level, char** namesArr)
{

    if (root == NULL)
    {
        padding('\t', level);
        puts("~");
    }
    else
    {
        printBranch(root->right, level + 1, namesArr);
        padding('\t', level);

        printf("%i - %s\n", root->key, namesArr[root->color]);
        printBranch(root->left, level + 1, namesArr);
    }
}

void padding(char ch, int tabs) {
    for (int i = 0; i < tabs; i++)
        putchar(ch);
}