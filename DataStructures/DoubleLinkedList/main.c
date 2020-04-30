#include <stdio.h>
#include <stdlib.h>

#include "mainFunctions/doublelinkedlist.h"


int main()
{
    session* ses = createSession();
    addOnFirstPlace(1, ses);
    addOnFirstPlace(2, ses);
    addOnFirstPlace(3, ses);

    addOnLastPlace(4, ses);
    addOnLastPlace(5, ses);
    addInSession(10, ses);
    deleteNode(3, ses);

    addInSession(6, ses);

    deleteNode(6, ses);
    deleteNode(4, ses);
    deleteNode(10, ses);

    printSession(ses);

    deleteMarked(ses);

    printSession(ses);

    deleteSession(ses);


    return 0;
}