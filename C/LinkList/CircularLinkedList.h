//
// Created by Npc on 2024/4/18.
//

#ifndef C_CIRCULARLINKEDLIST_H
#define C_CIRCULARLINKEDLIST_H
//�������ͷ�����ʵ��
#include "stdlib.h"
#include "stdio.h"
typedef struct list{
    int data;
    struct list *next;
}list;

/*//ѭ��������ĳ�ʼ��
list *initlist()
{
    //����һ����ͷ��㣬����û���κ�����
    list *head=(list *)malloc(sizeof (list));
    if(head==NULL)
    {
        printf("����ʧ��/n");
        exit(0);
    }
    else{
        head->next==head;
        return head;
    }
}

//ѭ������Ĳ������-������β����������
*//* 1.����һ��temp�ڵ�
 * 2.ԭ�����β�ڵ��nextָ��ָ��temp�ڵ�
 * 3.temp�ڵ��nextָ��ָ��head->next*//*
int insert_list(list *head)
{
    int data; //�������ݵ�ֵ
    scanf("%d",&data);

    list *temp=(list *) malloc(sizeof(list));
    temp->data=data;
    list *curr=head->next;
    while(curr->next!=head->next)
    {
        curr=curr->next;
    }
    curr->next=temp;
    temp->next=head->next;
}

//����Ԫ��
list *insertList(list *head,int pos,int data)
{
    list *p=head->next;
    for(int i=1;i<pos;i++)
    {
        p=p->next;
    }
    list *temp= (list *) malloc(sizeof(list));
    temp->data=data;
    temp->next=p->next;
    p->next=temp;
    return p;
}

int delete_list(list *head)
{
    list *temp=head->next;
    int del;
    printf("������Ҫɾ����ֵ");
    scanf("%d",&del);
    while(temp)
    {

    }

}*/
 //��ʼ���
list *initlist(){
    list *head=(list*)malloc(sizeof(list));
    if(head==NULL){
        printf("����ʧ�ܣ��˳�����");
        exit(0);
    }else{
        head->next=NULL;
        return head;
    }
}

//����--��������
int create_list(list *head){
    int data;   //�������������
    printf("������Ҫ�����Ԫ�أ�");
    scanf("%d",&data);

    list *node=initlist();
    node->data=data;
    //��ʼ��һ���µĽ�㣬׼����������

    if(head!=NULL){
        list *p=head;
        //�ҵ����һ������
        while(p->next!=head){
            p=p->next;
        }
        p->next=node;
        node->next=head;
        return 1;
    }else{
        printf("ͷ�������Ԫ��\n");
        return 0;
    }

}

//����Ԫ��
list *insert_list(list *head,int pos,int data){
    //���������ֱ�������λ�ã�����
    list *node=initlist();  //�½����
    list *p=head;       //p��ʾ�µ�����
    list *t;
    t=p;
    node->data=data;
    if(head!=NULL){
        for(int i=1;i<=pos;i++){
            t=t->next;
        }
        node->next=t->next;
        t->next=node;
        return p;
    }
    return p;
}

//ɾ��Ԫ��
int delete_list(list *head) {
    if(head == NULL) {
        printf("����Ϊ�գ�\n");
        return 0;
    }
    //������ʱ���洢ͷ�����Ϣ��Ŀ��Ϊ���ҵ��˳��㣩
    //�������ô�����Ļ���Ҫʹ��һ�����ݽ��м�����ǣ������ﵽ������ʱ�Զ��˳�
    //ѭ�������ҵ����һ��Ԫ�ص�ʱ����Զ�ָ��ͷԪ�أ��������ǲ�������������
    list *temp = head;
    list *ptr = head->next;

    int del;
    printf("��������Ҫɾ����Ԫ�أ�");
    scanf("%d",&del);

    while(ptr != head) {
        if(ptr->data == del) {
            if(ptr->next == head) { //ѭ����������������ptr->next == head
                temp->next = head;
                free(ptr);
                return 1;
            }
            temp->next = ptr->next;
            free(ptr);
            //printf("Ԫ��ɾ���ɹ���\n");
            return 1;
        }
        temp = temp->next;
        ptr = ptr->next;
    }
    printf("û���ҵ�Ҫɾ����Ԫ��\n");
    return 0;
}


//����Ԫ��
int display(list *head) {
    if(head != NULL) {
        list *p  = head;
        //����ͷ�ڵ㵽�����һ������
        while(p->next != head ) {
            printf("%d  ",p->next->data);
            p = p->next;
        }
        printf("\n");   //ϰ���Ի���
        //�����һ���ڵ㸳�µĽڵ��ȥ
        return 1;
    } else {
        printf("ͷ���Ϊ��!\n");
        return 0;
    }
}
#endif //C_CIRCULARLINKEDLIST_H
