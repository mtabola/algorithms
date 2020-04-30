#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


extern const size_t STACKSIZE;

typedef struct _NODETYPE
{
    int value;
    struct _NODETYPE* next;
}node_t;

typedef struct _SESSIONTYPE
{
    struct _NODETYPE* top;
    size_t nodeQty;
}session_t;

session_t* createSession();
void deleteSession(session_t*);

void insertNode(session_t*, const int);
void deleteNode(session_t* );
void clearStack(session_t*);

node_t* getTop(const session_t* const);
size_t getNodesQty(const session_t* const);
bool stackIsEmpty(const session_t* const);

void printSession(const session_t* const);