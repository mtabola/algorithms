#include "mainFunctions/queue.h"

extern const QUEUESIZE;

int main()
{
    session_t* ses = createSession();

    if (queueIsEmpty(ses))
    {
        for (size_t i = 1; i <= 128; i*= 2)
            enqueue(ses, i);

        printf("Queue after \"enqueue\" loop: \n\tnodeQty - %lu \n\tQueue first node - [%p]\n\tQueue last node - [%p]\n", getNodesQty(ses), getFront(ses), getBack(ses));

        for (size_t i = 0; i < 5; i++)
            dequeue(ses);

        printf("Queue after \"dequeue\" loop: \n\tnodeQty - %lu \n\tQueue first node - [%p]\n\tQueue last node - [%p]\n", getNodesQty(ses), getFront(ses), getBack(ses));

        for (size_t i = 0; i < QUEUESIZE; i++)
            enqueue(ses, i);

        printf("Queue after \"wrong enqueue\" loop: \n\tnodeQty - %lu \n\tQueue first node - [%p]\n\tQueue last node - [%p]\n", getNodesQty(ses), getFront(ses), getBack(ses));



        printSession(ses);
        deleteSession(ses);

    }

    
    return 0;
}