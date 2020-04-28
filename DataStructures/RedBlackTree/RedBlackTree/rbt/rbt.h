#pragma once
#include <stdio.h>
#include <stdlib.h>


typedef enum _COLORS { BLACK, RED }colors;


typedef struct _NODE
{
    int key;
    struct _NODE* left;
    struct _NODE* right;
    struct _NODE* parent;
    colors color;
}node;



typedef struct _SESSION
{
    struct _NODE* root;
    size_t nodeQty;
    struct _NODE* saveNull;
}session;

session* createSession();
void deleteSession(session*);
void deleteBranch(session*, node*);

node* findNode(const session* const, const int );

node* findMinNode(const session* const, node*);
node* findMaxNode(const session* const, node*);

void leftRotation(session*, node*);
void rightRotation(session*, node*);

void insertNode(session*, const int);
void insertFixup(session*, node*);

void transplant(session*, node*, node*);
void deleteNode(session*, const int );
void deleteFixup(session*, node*);

void printSession(const session* const);
void printBranch(node* root, int level, char** namesArr);
void padding(char ch, int tabs);