//
// Created by Npc on 2024/4/18.
//

#ifndef C_SEQUENTIALQUEUE_H
#define C_SEQUENTIALQUEUE_H
#include "stdio.h"
#include "stdlib.h"

/*������һ���Ƚ��ȳ������ݽṹ*/
 /*���еĽ����ƣ����ǿ�����Ƴ������ṹ�壬һ���ṹ��Node��ʾ��㣬���а�����һ��data���nextָ��*/
 typedef struct node{
     int data;
     node *next;
 }node;

//�������
typedef struct queue{
    node *front; //ͷָ��
    node *rear; //βָ��
};

//��ʼ���ڵ�
node *initNode()
{
    node *n=(node *)malloc(sizeof (node));
    if(n==NULL)
    {
        exit(0);//����ڵ㿪��ʧ��
    }
    return n;
}

//��ʼ������
queue *initQueue()
{
    queue *q=(queue*) malloc(sizeof (queue));
    if(q==NULL)
    {
        exit(0);//������п���ʧ��
    }
    //ͷβָ�����ֵNULL
    q->front=NULL;
    q->rear=NULL;
    return q;
}

//�ж϶����Ƿ�Ϊ��
int empty(queue *q)
{
    if(q->front==NULL)
    {
        return 1; //1-�����棬����Ϊ��
    }
    else{
        return 0;
    }
    //����ֱ��ʹ��return q->front==NULL
}

//��Ӳ���
/* 1.������Ҫ����һ�¶����Ƿ�Ϊ��
 * 2.�������Ϊ�գ���Ҫ��ͷָ���βָ��ͬʱָ���һ���ڵ�
 * 3.������в�Ϊ�գ�ֻ��Ҫ��β�ڵ�����ƶ���ͨ�������ƶ�nextָ��ָ���µĽڵ�*/
void push(queue *q,int data)
{
    node *n=initNode();
    n->data=data;
    n->next=NULL;
    //����β�
    if(empty(q))
    {
        q->front=n;
        q->rear=n;
    }
    else{
        q->rear->next=n;
        q->rear=n;
    }
}

//���Ӳ���
/* 1.ǰ�������Ƕ��в�Ϊ�գ����Ҫ��һ���ж�
 * 2.���������ֻ��һ��Ԫ��,���Ӻ���Ҫ��ͷβָ���ÿգ���free������ڵ�
 * 3.������������������ϵ�Ԫ�أ���ͷָ��ָ��ͷָ�����һ��Ԫ�أ���free����ǰԪ��*/
void pop(queue *q)
{
    node *n=q->front;
    if(empty(q))
    {
        printf("����Ϊ�գ��޷�����");
        return;
    }
    //���ֻ��һ��Ԫ��
    if(q->front==q->rear)
    {
        q->front=NULL;
        q->rear=NULL;
        free(n);
    }
    else//����������������ϵ�Ԫ��
    {
        q->front=q->front->next;
        free(n);
    }
}

//��������-��ӡԪ��
void print_queue(queue *q)
{
    node *n=initNode();
    n=q->front;
    if(empty(q))
    {
        return;
    }
    while(n!=NULL)
    {
        printf("%d\t",n->data);
        n=n->next;
    }
    printf("\n");
}
#endif //C_SEQUENTIALQUEUE_H
