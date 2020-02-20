#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <assert.h>

//#include "../../../../addCustFunc/addCustFunc.h"

#define FREE true
#define NOTFREE false
#define i32 int32_t

typedef struct _NODE
{
    i32 data;
    struct _NODE* next;
    struct _NODE* prev;
    bool isFree;
}node;

typedef struct _SESSION
{
    node* firstElem;
    node* lastElem;
    size_t size;
}session;



session* createSession();
void addOnFirstPlace(i32 data, session* ses);
void addOnLastPlace(i32 data, session* ses);
void addInSession(i32 data, session* ses);
node* findNode(i32 data, session* ses);
void deleteNode(i32 data, session* ses);
int sessionSize(session* ses);
void printSession(const session* ses);
void clearSession(session* ses);
bool sessionIsEmpty(session* ses);
void deleteSession(session* ses);
void deleteMarked(session* ses);