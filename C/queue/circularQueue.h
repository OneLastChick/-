//
// Created by Npc on 2024/4/18.
//

#ifndef C_CIRCULARQUEUE_H
#define C_CIRCULARQUEUE_H
#include "stdio.h"
#include "stdlib.h"
/*��Ϊ���ǵ���Ӻͳ��Ӳ�������ֱ�����������н������Ӻ�ɾ����
 * ��������ʹ�ÿռ䲻������ӵ���һ��ƫ�ƣ����������
 * ͨ��ʹ��ѭ�����оͿ��Ա�������������*/
#define maxsize 10
typedef struct cir_queue{
    int data[maxsize];
    int rear;
    int front;
}cir_queue;

//��ʼ��
cir_queue *init()
{
    cir_queue *q=(cir_queue*) malloc(sizeof (cir_queue));
    if(q==NULL)
    {
        exit(0);
    }
    q->front=0;
    q->rear=0;
    return q;
}

//ѭ��������Ӳ���
/*�ӽ�rear����ƶ����ɣ�����Ҫע���жϣ�
 * ���rear�ﵽ�˶��еĿռ����ߣ�
 * ��Ҫ��ͷ������ʼ�ƶ���
 * �����Ƽ�ʹ��������*/
void push(cir_queue *q,int data)
{
    if((q->rear+1)%maxsize==q->front)
    {
        printf("������޷����\n");
        return;
    }else{
        q->rear=(q->rear+1)%maxsize;
        q->data[q->rear]=data;
    }
}

void pop(cir_queue *q)
{
    //�ж�ջ��
    if(q->rear==q->front)
    {
        printf("�����ѿգ��޷�����\n");
        return;
    }else{
        q->data[q->front]=0;
        q->front=(q->front+1)%maxsize;
    }
}

//ѭ�����б�������
void printCirQueue(cir_queue *q)
{
    int i=q->front;
    while(i!=q->rear)
    {
        i=(i+1)%maxsize;
        printf("%d\t",q->data[i]);
    }
    printf("\n");
}
#endif //C_CIRCULARQUEUE_H
