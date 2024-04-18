//
// Created by Npc on 2024/4/18.
//

#ifndef C_ARRAYSTACK_H
#define C_ARRAYSTACK_H

#include "stdlib.h"
#include "stdio.h"
#include "string.h"

#define maxn 1000
typedef struct stack {
    int data[maxn];
    int top;
} stack;

//ջ�ĳ�ʼ��
stack *init() {
    stack *s = (stack *) malloc(sizeof(stack));
    if (s == NULL) {
        printf("����ջ�ռ�ʧ��!");
        exit(0);
    }
    memset(s->data, 0, sizeof(s->data));
    //memset���������ڿ��ļ�string.h�����ʾ�������ռ���г�ʼ��
    s->top = 0;
    //ע��topָ��ָ��ջ��Ԫ�ص���һ��
    return s;
}

//��ջpush
void push(stack *s, int data) {
    s->data[s->top] = data;
    s->top++;
}

//��ջpop
void pop(stack *s) {
    if (s->top != 0) {
        s->top--;
        s->data[s->top] = 0;
    }
}

//����ջ��Ԫ�ز���ӡ
void print_stack(stack *s) {
    for (int n = s->top - 1; n >= 0; n--) {
        printf("%d\t", s->data[n]);
    }
    printf("\n");
}

#endif //C_ARRAYSTACK_H
