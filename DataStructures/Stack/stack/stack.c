#include "stack.h"

const size_t STACKSIZE = 16;

session_t* createSession()
{
    session_t* ses = calloc(1, sizeof(session_t));
    if (ses == NULL)
    {
        puts("[!!!]Session didn't was created. Problem with heap.");
        return NULL;
    }

    ses->nodeQty = 0;
    ses->top = NULL;

    puts("[+] Session has been created.");

    return ses;
}

void deleteSession(session_t* ses)
{
    if (ses == NULL)
    {
        puts("[!!!] NULL is not session. Please give stack session.");
        return;
    }
    clearStack(ses);
    free(ses);
    puts("[+] Session has been deleted.");

}



void insertNode(session_t* ses, const int key)
{
    if (ses == NULL)
    {
        puts("[!!!] NULL is not session. Please give stack session.");
        return;
    }

    if (ses->nodeQty < STACKSIZE)
    {
        node_t* newNode = calloc(1, sizeof(node_t));
        if (newNode == NULL)
        {
            puts("[!!!] Node didn't was created. Problem with heap.");
            return;
        }

        newNode->value = key;
        newNode->next = ses->top;
        ses->top = newNode;
        ses->nodeQty++;
    }
    else
        puts("[!!!] Node didn't was added. Stack overflow.");
}

void deleteNode(session_t* ses)
{
    if (ses == NULL)
    {
        puts("[!!!] NULL is not session. Please give stack session.");
        return;
    }


    if (!(ses->nodeQty <= 0))
    {
        node_t* delNode = ses->top;
        
        ses->top = delNode->next;
        ses->nodeQty--;

        free(delNode);
    }
    else
        puts("[!!!] Node wasn't deleted. Stack underflow.");
}

void clearStack(session_t* ses)
{
    if (ses == NULL)
    {
        puts("[!!!] NULL is not session. Please give stack session.");
        return;
    }

    while (ses->top != NULL)
    {
        deleteNode(ses);
    }
    puts("[+] Stack was cleared.");
}



node_t* getTop(const session_t* const ses)
{
    return ses->top;
}

size_t getNodesQty(const session_t* const ses)
{
    return ses->nodeQty;
}

bool stackIsEmpty(const session_t* const ses)
{
    return (ses->top == NULL && ses->nodeQty == 0);
}


void printSession(const session_t* const ses)
{
    if (ses == NULL)
    {
        puts("[!!!] NULL is not session. Please give stack session.");
        return;
    }



    if (ses->top != NULL)
    {
        node_t* currNode = ses->top->next;
        puts("\n------------------- STACK INFORMATION -------------------------");
        printf("\t%i <------- STACK TOP\n", ses->top->value);

        while (currNode != NULL)
        {
            printf("\t%i\n", currNode->value);
            currNode = currNode->next;
        }
        printf("\n");
    }
    else
        puts("\tSTACK TOP == NULL\n");
    
    printf("\t%i nodes in this session\n", ses->nodeQty);
    puts("---------------------------------------------------------------\n");
}
