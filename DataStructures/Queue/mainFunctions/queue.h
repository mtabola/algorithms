#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


extern const size_t QUEUESIZE;

typedef struct _NODESTRUCT
{
    struct _NODESTRUCT* prev;
    struct _NODESTRUCT* next;
    int value;
}node_t;

typedef struct _SESSIONTYPE
{
    struct _NODESTRUCT* first;
    struct _NODESTRUCT* last;
    size_t nodeQty;
}session_t;


session_t* createSession();
void deleteSession(session_t*);

void enqueue(session_t*, const int);
void dequeue(session_t*);

node_t* getFront(const session_t* const);
node_t* getBack(const session_t* const);
void clearQueue(session_t* const);

bool queueIsEmpty(const session_t* const);
size_t getNodesQty(const session_t* const);

void printSession(const session_t* const);

