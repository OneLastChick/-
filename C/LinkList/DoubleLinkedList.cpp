//
// Created by Npc on 2024/4/17.
//

#include "DoubleLinkedList.h"
int main()
{
    line *head=NULL;
    printf("����˫�������\n");
    head=initLine(head);
    printLine(head);
    //CreateLine
    printf("�������\n");
    head= insertLine(head,3,2);
    printLine(head);
    //InsertLine
    printf("ɾ������\n");
    head= deleteLine(head,3);
    printLine(head);
    //DeleteLine
    system("pause");
    return 0;

}