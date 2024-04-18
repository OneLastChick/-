//
// Created by Npc on 2024/4/18.
//

#ifndef C_LINKEDSTACK_H
#define C_LINKEDSTACK_H

#include "stdio.h"
#include "stdlib.h"
/*ջ��Ϊ����ջ������ջ��������������ջʹ��������й��ܵ�ģ�⣬
 * ʵ�ֽ�Ϊ���ٺͱ�����������ջʹ�������˼·ȥ��ƣ�ʵ�ֽ�Ϊ�鷳���������ȶ����׳���������ջ���ַ�Ϊ��̬����ջ�Ͷ�̬����ջ����̬����ջ����ջ�Ŀռ��С��
 * ���������洢�����������ݴ�С��Ԫ�أ�����̬ջʹ�õ����Զ������ռ�ķ������д�����
 * ֻҪ���ϻ�����Ӳ��Ҫ���Լ��������Ŀ��ƣ����������Ǽ���ġ�*/
//ջ������
/*����data��ʾ���ݣ�������Ǽ򵥵�����
 * ����int,double�ȵȣ���
 * Ҳ�����Ǹ��ӵĽṹ�壨struct���ͣ���*/
typedef struct node {
    int data;
    struct node *next;
} node;
/*�����Ե���ƣ��������һ���ṹ�壬�������һ����Զָ��ջͷ��ָ��top��һ��������count��¼Ԫ�ظ�����
 * ��Ҳ������Ƴ�һ��ָ��top��һ��ָ��bottom�ֱ�ָ��ջͷ��ջβ��
 * ����Ҫ��Ч�����趨�������Ԫ�ص�ָ���Լ�ȷ��ջ��ʱΪ��*/
typedef struct Stack {
    node *top;
    int count;
} LinkStack;

//����ջ
LinkStack *CreateStack() {
    LinkStack *p;
    p = (LinkStack *) malloc(sizeof(LinkStack));
    if (p == NULL) {
        printf("����ʧ��");
        exit(0);
    }
    p->count = 0;
    p->top = NULL;
    return p;
}

//��ջ����
LinkStack *PushStack(LinkStack *p, int elem) {
    //����ջû���ٳɹ����������
    if (p == NULL) {
        return NULL;
    }
    node *temp;
    temp = (node *) malloc(sizeof(node));
    temp->data = elem;
    temp->next = p->top;
    p->top = temp;
    p->count++;
    return p;
}

//��ջ����
LinkStack *PopStack(LinkStack *p) {
    node *temp;
    temp = p->top;
    if (p->top == NULL) {
        printf("����ջΪ��");
    } else {
        p->top = p->top->next;
        free(temp);
        //delete temp
        p->count--;
        return p;
    }
}

//ջ�ı���:���ջ������Ԫ��
int show_stack(LinkStack *p) {
    node *temp;
    temp = p->top;
    if (p->top == NULL) {
        printf("����ջΪ��");
        return 0;
    }
    while (temp != NULL) {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
    printf("\n");
    return 0;
}

#endif //C_LINKEDSTACK_H
