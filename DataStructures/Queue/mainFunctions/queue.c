#include "queue.h"

const size_t QUEUESIZE = 32;

session_t* createSession()
{
    session_t* ses = calloc(1, sizeof(session_t));
    if (ses == NULL)
    {
        puts("[!!!]Session didn't was created. Problem with heap.");
        return NULL;
    }

    ses->first = ses->last = NULL;
    ses->nodeQty = 0;

    return ses;
}

void deleteSession(session_t* ses)
{
    if (ses == NULL)
    {
        puts("[!!!] NULL is not session. Please give queue session.");
        return;
    }
    clearQueue(ses);
    free(ses);

    puts("[+] Session has been deleted.");
}



void enqueue(session_t* ses, const int value)
{
    if (ses == NULL)
    {
        puts("[!!!] NULL is not session. Please give queue session.");
        return;
    }

    if (ses->nodeQty < QUEUESIZE) 
    {
        node_t* newNode = calloc(1, sizeof(node_t));
        if (newNode == NULL)
        {
            puts("[!!!] Node didn't was created. Problem with heap.");
            return;
        }

        newNode->value = value;
        newNode->next = newNode->prev = NULL;

        if (ses->first == NULL && ses->last == NULL)
        {
            ses->first = ses->last = newNode;
        }
        
        else
        {
            ses->last->next = newNode;
            newNode->prev = ses->last;
            ses->last = newNode;
        }
        ses->nodeQty++;
    }
    else
        puts("[!!!] Node didn't was added. Queue overflow.");
}

void dequeue(session_t* ses)
{
    if (ses == NULL)
    {
        puts("[!!!] NULL is not session. Please give queue session.");
        return;
    }


    node_t* delNode = ses->first;
    
    if (!(ses->nodeQty <= 0))
    {
        ses->first = delNode->next;

        free(delNode);
        ses->nodeQty--;
    }
    else
        puts("[!!!] Node wasn't deleted. Queue underflow.");
}

void clearQueue(session_t* const ses)
{
    if (ses == NULL)
    {
        puts("[!!!] NULL is not session. Please give queue session.");
        return;
    }


    while (ses->nodeQty != 0)
        dequeue(ses);
    puts("[+] Queue was cleared.");

}



node_t* getFront(const session_t* const ses)
{
    return ses->first;
}

node_t* getBack(const session_t* const ses)
{
    return ses->last;
}

bool queueIsEmpty(const session_t* const ses)
{
    return ((ses->nodeQty == 0) && (ses->first == NULL && ses->last == NULL));
}

size_t getNodesQty(const session_t* const ses)
{
    return ses->nodeQty;
}



void printSession(const session_t* const ses)
{
    if (ses == NULL)
    {
        puts("[!!!] NULL is not session. Please give queue session.");
        return;
    }


    node_t* currNode = ses->first;
    size_t i = 1;

    puts("\n-------------------------- QUEUE SESSION PRINT --------------------------");

    while (currNode != NULL)
    {
        printf("%i node (Value {%i} Address [%p])\n", i, currNode->value, currNode);
        currNode = currNode->next;
        i++;

    }

    puts("-------------------------------------------------------------------------\n");

}
