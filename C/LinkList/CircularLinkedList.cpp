//
// Created by Npc on 2024/4/18.
//

#include "CircularLinkedList.h"
int main(){
    //////////��ʼ��ͷ���//////////////
    list *head=initlist();
    head->next=head;
    ////////ͨ������Ԫ����������/////////
    for(int i=0;i<5;i++){   //ֻ����ʾʹ�ã��������ṩ����
        create_list(head);
    }
    display(head);
    ////////////����Ԫ��////////////////
    head=insert_list(head,1,10);
    display(head);
    ////////////ɾ��Ԫ��////////////////
    delete_list(head);
    display(head);
    system("pause");
    return 0;
}