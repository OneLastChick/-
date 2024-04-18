//
// Created by Npc on 2024/4/17.
//

#ifndef C_SINGLELINKLIST_H
#define C_SINGLELINKLIST_H
#include "stdlib.h"
#include "stdio.h"
//������ADT
typedef struct Node{
    int data;
    struct Node *next;
}Node,*LinkedList;  //Node��ʾ��㣬LinkedList��ʾָ��Node������͵�ָ������
// Function prototypes


//������ĳ�ʼ��
LinkedList listinit()
{
    Node *L;
    L=(Node*) malloc(sizeof(Node));
    if(L==NULL){
        printf("�����ڴ�ռ�ʧ��");
        exit(0);
    }
    L->next=NULL;
    return L;
}
//������Ľ���1:ͷ�巨����������
LinkedList LinkedListCreatH(){
    Node *L;
    L=(Node *)malloc(sizeof(Node)); //����ͷ���
    L->next=NULL;  //��ʼ��һ��������
    //��listinit()
    int x;
    while(scanf("%d",&x)!=EOF){
        Node *p;
        p=(Node *)malloc(sizeof(Node));
        p->data=x;
        p->next=L->next;
        L->next=p;
    }
    return L;
}
//������Ľ���2:β�巨����������
LinkedList LinkedListCreatT(){
    Node *L;
    L=(Node*) malloc(sizeof(Node));
    L->next=NULL;
    Node *R;
    R=L;
    int x;
    while(scanf("%d",&x)!=EOF)
    {
        Node *p;
        p=(Node*) malloc(sizeof(Node));
        p->data=x;
        R->next=p;
        R=p;
    }
    R->next=NULL;
    return L;
}

//���������� ---��ӡ���޸�
void printList(LinkedList L)
{
    Node *p=L->next;
    int i=0;
    while(p)
    {
        printf("��%d��Ԫ�ص�ֵΪ:%d\n",++i,p->data);
        p=p->next;
    }
}
//�޸ĵ�����������������ֵΪx��Ԫ���޸�Ϊk
LinkedList LinkedListReplace(LinkedList L,int x,int k)
{
    Node *p=L->next;
    int i=0;
    while(p)
    {
        if(p->data==x)
        {
            p->data=k;
        }
        p=p->next;
    }
    return p;
}

//����������
/*
 * 1.���ҵ���i��λ��
 * 2.����λ�õ�nextָ���޸�Ϊָ�������²���Ľڵ�
 * 3.���²���Ľڵ�nextָ��ָ���i+1��λ��*/
LinkedList LinkedListInsert(LinkedList L,int i,int x)
{
    Node *pre; //pre��ǰ���ڵ�
    pre=L;
    int tempi=0;  //�����±�
    for(tempi=1;tempi<i;tempi++)
    {
        pre=pre->next;
    }
    Node *p; //p��Ҫ����Ľڵ�
    p=(Node *) malloc(sizeof (Node));
    p->data=x;
    p->next=pre->next;
    pre->next=p;

    return L;
}
//����ɾ������---ɾ��L������ֵΪx�Ľ��
/*1.����һ��ǰ�����ָ��pre��ָ��Ҫɾȥ�Ľڵ��ǰһ���ڵ�
 *2.pre��nextָ��ָ��ɾȥ�ڵ�ĺ�һ���ڵ�
 *3.free��ԭ�еĽڵ�*/
LinkedList LinkedListDelete(LinkedList L,int x)
{
    Node *pre=L;
    Node *p=L->next; //ָ��Ҫɾ���Ľڵ�
    while (p != NULL && p->data != x) {
        pre = p;
        p = p->next;
    }

    pre->next=p->next;
    free(p);
    return L;
}
#endif //C_SINGLELINKLIST_H
