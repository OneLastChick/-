//
// Created by Npc on 2024/4/17.
//

/*
�����ļ�
 */


/*
#include "SingleLinkList.h"
#include "stdio.h"
int main()
{
    printf("HelloWorld");
    //�����������
    LinkedList list;
    printf("please input the data\n");
    list=LinkedListCreateT();
    printList(list);

    //����
    int i;
    int x;
    printf("������������ݵ�λ��");
    scanf("%d",&i);
    printf("����������λ�õ�ֵ:");
    scanf("%d",&x);
    LinkedListInsert(list,i,x);
    printList(list);

    //�޸�
    printf("�������޸����ݵ�λ��:");
    scanf("%d",&i);
    printf("�������޸ĸ�λ�õ�ֵ:");
    scanf("%d",&x);
    LinkedListReplace(list,i,x);
    printList(list);

    //ɾ��
    printf("������Ҫɾ�����ݵ�ֵ");
    scanf("%d",&x);
    LinkedListDelete(list,x);
    printList(list);


    return 0;

}*/
#include "SingleLinkList.h"

int main() {
    //����3

    LinkedList list;
    printf("�����뵥��������ݣ���EOF��β\n");
    list = LinkedListCreatT();
    //list=LinkedListCreatT();
    printList(list);

    //����
    int i;
    int x;
    printf("������������ݵ�λ�ã�");
    scanf("%d",&i);
    printf("������������ݵ�ֵ��");
    scanf("%d",&x);

    LinkedListInsert(list,i,x);
    printList(list);

    //�޸�
    printf("�������޸ĵ����ݣ�");
    scanf("%d",&i);
    printf("�������޸ĺ��ֵ��");
    scanf("%d",&x);
    LinkedListReplace(list,i,x);
    printList(list);

    //ɾ��
    printf("������Ҫɾ����Ԫ�ص�ֵ��");
    scanf("%d",&x);
    LinkedListDelete(list,x);
    printList(list);

    return 0;
}