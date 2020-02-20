#include "doublelinkedlist.h"

session* createSession()
{
    session* ses = malloc(sizeof(session));
    if (ses == NULL)
    {
        printf("[!!!] Session didn't created\n\n");
        abort();
    }

    ses->firstElem = ses->lastElem = NULL;
    ses->size = 0;

    printf("[+] Session is created\n\n");
    return ses;
}


void addOnFirstPlace(i32 data, session* ses)
{
    node* newNode = malloc(sizeof(node));
    
    newNode->data = data;
    newNode->isFree = NOTFREE;
    newNode->next = ses->firstElem;
    newNode->prev = NULL;

    if(ses->firstElem != NULL)
        ses->firstElem->prev = newNode;
    
    ses->firstElem = newNode;
    
    if (ses->lastElem == NULL)
        ses->lastElem = ses->firstElem;

    ses->size++;
}


void addOnLastPlace(i32 data, session* ses)
{
    node* newNode = malloc(sizeof(node));

    newNode->data = data;
    newNode->isFree = NOTFREE;
    newNode->next = NULL;
    newNode->prev = ses->lastElem;

    if (ses->lastElem != NULL)
        ses->lastElem->next = newNode;

    if (ses->firstElem == NULL)
        ses->firstElem = ses->lastElem;

    ses->lastElem = newNode;
    ses->size++;
}


void addInSession(i32 data, session* ses)
{
    node* tmp = ses->firstElem;

    while (tmp != NULL)
    {
        if (tmp->isFree == FREE)
        {
            tmp->data = data;
            tmp->isFree = NOTFREE;
            ses->size++;
            return;
        }
        tmp = tmp->next;
    }
    if (tmp == NULL)
    {
        addOnLastPlace(data, ses);
    }
}


node* findNode(i32 data, session* ses)
{
    node* tmp = ses->firstElem;
    while (tmp != NULL)
    { 
        if (tmp->data == data && tmp->isFree == NOTFREE)
            return tmp;

        tmp = tmp->next;
    }

    if (tmp == NULL)
    {
        printf("[!] Node didn't found.\nPlease add node with this number - %d.\n\n", data);
        abort();
    }

}


void deleteNode(i32 data, session* ses)
{
    node* deleted = findNode(data, ses);

    if (deleted == NULL)
    {
        printf("[!!!] Node didn't found.\nRemove is impossible.\n\n");
        abort();
    }

    deleted->isFree = FREE;
    ses->size--;

}


int sessionSize(session* ses)
{
    return ses->size;
}


void printSession(const session* ses)
{
    node* tmp = ses->firstElem;
    size_t i = 1;

    printf("\n\nTotal session has %d elements. First element address - [%p], Last element address[%p].\n\n", ses->size, ses->firstElem, ses->lastElem);

    while (tmp != NULL)
    {
        if(tmp->isFree == NOTFREE)
        {
            printf("%d element is - %d. Address [%p], previous element [%p], next element[%p]\n", i, tmp->data, tmp, tmp->prev, tmp->next);
            i++;
        }
        tmp = tmp->next;
    }
}


void clearSession(session* ses)
{
    node* deleted = ses->firstElem;
    node* next = deleted->next;
    while (deleted != NULL)
    {
        free(deleted);
        deleted = next;

        if(next != NULL)
            next = next->next;
    }

    ses->size = 0;
    
    printf("[+] Session is cleared\n\n");
}


bool sessionIsEmpty(session* ses)
{
    return ses->size == 0;
}


void deleteSession(session* ses)
{
    if(ses->size != 0)
        clearSession(ses);
    free(ses);
    printf("[+]Session is deleted\n\n");
}


void deleteMarked(session* ses)
{
    node* deleted = ses->firstElem;
    node* next = deleted->next;
    node* tmp = NULL;

    while (deleted != NULL)
    {
        if (deleted->isFree == FREE)
        {
            if (deleted == ses->firstElem)
                ses->firstElem = deleted->next;
            else if (deleted == ses->lastElem)
                ses->lastElem = deleted->prev;

            tmp = deleted->prev;

            if (tmp != NULL)
                tmp->next = deleted->next;

            tmp = deleted->next;
            if (tmp != NULL)
                tmp->prev = deleted->prev;

            free(deleted);
        }  
        deleted = next;

        if (next != NULL)
            next = next->next;
    }
}