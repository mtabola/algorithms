#include <stdio.h>
#include <stdlib.h>

#define STEP 10

typedef struct _NODE
{
    int key;
    struct _NODE* parent;
    struct _NODE* left;
    struct _NODE* right;
} node;

typedef struct _SESSION
{
    struct _NODE* root;
    size_t totalNodes;
}session;


session* createSession();
void deleteSession(session* ses);
void deleteBranch(node* head);

node* findNode(session* ses, int key);

node* findMinNode(node* head);
node* findMaxNode(node* head);

node* findSuccessorNode(node* head);
node* findPredecessorNode(node* head);

void insertNode(session* ses, int key);
void transplant(session* ses, node* cur, node* next);
void deleteNode(session* ses, int key);

void printSession(session* ses);
void printBranch(node* root, int level);
void padding(char ch, int tabs);