#include "rbt/rbt.h"

int main()
{
    session* ses = createSession();

    insertNode(ses, 20);
    insertNode(ses, 15);
    insertNode(ses, 10);
    insertNode(ses, 29);


    printSession(ses);
    deleteSession(ses);


    system("pause");

    return 0;
}