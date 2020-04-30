#include "stack/stack.h"

extern const size_t STACKSIZE;

int main()
{
    session_t* ses = createSession();
    if (stackIsEmpty(ses))
    {
        for (int i = 2; i < 512; i *= 2)
            insertNode(ses, i);

        printf("Stack after \"insert\" loop: \n\tnodeQty - %lu \nstack top - [%p]\n", getNodesQty(ses), getTop(ses));
        
        for (int i = 0; i < 3; i++)
            deleteNode(ses);
        printf("Stack after \"delete\" loop: \n\tnodeQty - %i \n\tstack top - [%p]\n", getNodesQty(ses), getTop(ses));


        for (int i = 0; i < STACKSIZE; i++)
            insertNode(ses, i);
        printf("Stack after second wrong \"insert\" loop: \n\tnodeQty - %i \n\tstack top - [%p]\n", getNodesQty(ses), getTop(ses));

        printSession(ses);

        clearStack(ses);
        deleteNode(ses);
    }

    deleteSession(ses);

    return 0;
}