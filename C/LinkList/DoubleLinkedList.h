//
// Created by Npc on 2024/4/17.
//

#ifndef C_DOUBLELINKEDLIST_H
#define C_DOUBLELINKEDLIST_H
#include "stdio.h"
#include "stdlib.h"
typedef struct line{
    int data;
    struct line *pre;
    struct line *next;
}line;


//˫����Ĵ���
/*����Ҫ��
 * 1.����ͷ���
 * 2.����һ���µĽ��
 * 3.��ͷ�����½���໥����
 * 4.�ٶȴ����½��
 * */
line* initLine(line *head){
    int number,pos=1,input_data;//�ֱ��������������ǰλ�ã���������
    printf("�����봴���ڵ�Ĵ�С\n");
    scanf("%d",&number);
    if(number<1)
    {
        return NULL;  //�����������
    }
    //����ͷ���
    head=(line *)malloc(sizeof(line));
    head->pre=NULL;
    head->next=NULL;
    printf("�����%d������\n",pos++);
    scanf("%d",&input_data);
    head->data=input_data;

    //����˫������
    line *list=head; //����һ��βָ��
    while(pos<=number)
    {
        line *body=(line *) malloc(sizeof(line));
        body->pre=NULL;
        body->next=NULL;
        printf("�����%d������\n",pos++);
        scanf("%d",&input_data);
        body->data=input_data;

        list->next=body;
        body->pre=list;
        list=list->next;
    }

    return head;
}


//����˫����
/* 1.���ȴ���һ���ڵ�
 * 2.ѡ������½ڵ�
 * 3.����preָ��ָ���������λ�õ�ǰһ���ڵ�
 * 4.����nextָ��ָ���������λ�õĺ�һ���ڵ�
 * 5.��ǰһ���ڵ��nextָ��ýڵ�
 * 6.����һ���ڵ��preָ��ýڵ�*/
line *insertLine(line *head,int pos,int data)//��������:pos:Ҫ�����λ�ã�������pos��ǰһ���ڵ� data��Ҫ�����ֵ
{
    line *temp=(line*) malloc(sizeof(line));
    temp->data=data;
    temp->pre=NULL;
    temp->next=NULL;

    //���Ҫ���뵽ͷ���֮ǰ(��ʵ�����ͷ������ó����������Ͳ��ÿ������������)
    if(pos==1)
    {
        temp->next=head;
        head->pre=temp;
        head=temp;
    }
    else{
        line *body=head;
        //Ҫ���ýڵ���뵽��pos�����ͽ���һ��ָ��ָ���pos-1��
        for(int i=1;i<pos-1;i++)
        {
            body=body->next;
        }
        //���뵽����β�����ҲҪ���⿼��
        if(body->next==NULL)
        {
            body->next=temp;
            temp->pre=body;
        }
        //���뵽�������β֮��
        else{
            temp->pre=body;
            temp->next=body->next;
            body->next->pre=temp;
            body->next=temp;
        }
    }
    return head;
}

//˫�������ɾ������
/* 1.ѡ����Ҫɾ���Ľڵ�
 * 2.ѡ������ڵ��ǰһ���ڵ�
 * 3.��ǰһ���ڵ��nextָ��ָ����Ҫɾ��������һ��
 * 4.����һ���ڵ��preָ��ָ��ýڵ��ǰһ��
 * 5.�ͷŵ��ýڵ���ڴ�*/
line *deleteLine(line *head,int data)//��������:data��Ҫɾ������ֵ
{
    line *list=head;
    //����˫�������ҵ�Ҫɾ���Ľڵ�
/*
    while((list->data!=data) && list)
    {
        list=list->next;
    }
    //ѡ������ڵ��ǰһ���ڵ�
    if(list!=NULL)
    {
        list->pre->next=list->next;
        list->next->pre=list->pre;
        free(list);
        printf("--ɾ���ɹ�--");

    }
    else{
        printf("Error:�ڵ㲻����!!!");
    }
    return head;
*/
     while (list) {
        //�ж��Ƿ����Ԫ�����
        //ɾ���õ㷽��Ϊ���ý��ǰһ����nextָ��ýڵ��һ���
        //ͬʱ���ý��ĺ�һ����preָ��ýڵ��ǰһ���
        if (list->data==data) {
            //���Ҫɾ��ͷ���
            if(list->pre==NULL)
            {
                head=list->next;
            }
            else{
            list->pre->next=list->next;
            }
            //���Ҫɾ��β�ڵ�
            if(list->next==NULL)
            {list->pre->next==NULL;}
            else{
                list->next->pre=list->pre;
            }

            free(list);
            printf("--ɾ���ɹ�--\n");
            return head;
        }
        list=list->next;
    }
    printf("Error:û���ҵ���Ԫ�أ�û�в���ɾ��\n");
    return head;
}

//˫������ı���
/* 1.����nextָ�����������*/
void printLine(line *head)
{
    line *list=head;
    int pos=1;
    while(list){
        printf("��%d��λ�õ�ֵ��%d\n",pos++,list->data);
        list=list->next;
    }
}
#endif //C_DOUBLELINKEDLIST_H
