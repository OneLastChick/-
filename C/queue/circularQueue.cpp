//
// Created by Npc on 2024/4/18.
//

#include "circularQueue.h"
int main()
{
    cir_queue *q=init();
    /*********��Ӳ���***********/
    for(int i=0;i<=6;i++)
    {
        push(q,i);
    }
    printCirQueue(q);
    /*********���Ӳ���***********/
    for(int i=0;i<=6;i++)
    {
        pop(q);
        printCirQueue(q);
    }
    system("pause");
    return 0;

}