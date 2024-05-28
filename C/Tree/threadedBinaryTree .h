//
// Created by Npc on 2024/5/8.
//

#ifndef C_THREADEDBINARYTREE_H
#define C_THREADEDBINARYTREE_H
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
/*������ѧ�����ڣ�������������⣺

��n�����Ķ������У��ض���n+1��������Ҷ�ӽ������������ռ��˷��ˣ�
�������ı����������ǵݹ黹�Ƿǵݹ��㷨��Ч�ʶ�����ߡ�*/
#define ElemType int
typedef struct TBTNode{
    ElemType data; //����Ԫ��
    TBTNode*lchild,*rchild;//���Һ���ָ��
    int ltag;//Ĭ��tagֵΪ0�������ӣ�1��ʾǰ��
    int rtag;//Ĭ��tagֵΪ0�����к��ӣ�1��ʾ���
}TBTNode;

// �����½ڵ�
TBTNode* createNode(ElemType data) {
    TBTNode* newNode = (TBTNode*)malloc(sizeof(TBTNode));
    if (!newNode) {
        printf("Memory error\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->lchild = NULL;
    newNode->rchild = NULL;
    newNode->ltag = 0;
    newNode->rtag = 0;
    return newNode;
}

// ����������
void InThread(TBTNode* p, TBTNode*& pre) {
    if (p) {
        InThread(p->lchild, pre);
        if (!p->lchild) {
            p->ltag = 1;
            p->lchild = pre;
        }
        if (pre && !pre->rchild) {
            pre->rtag = 1;
            pre->rchild = p;
        }
        pre = p;
        InThread(p->rchild, pre);
    }
}

// �����������������
void InOrder(TBTNode* root) {
    TBTNode* p = root;
    while (p) {
        while (p->ltag == 0)
            p = p->lchild;
        printf("%d ", p->data);
        while (p->rtag == 1 && p->rchild) {
            p = p->rchild;
            printf("%d ", p->data);
        }
        p = p->rchild;
    }
}

// ����������
void PreThread(TBTNode* p, TBTNode*& pre) {
    if (p) {
        if (!p->lchild) {
            p->ltag = 1;
            p->lchild = pre;
        }
        if (pre && !pre->rchild) {
            pre->rtag = 1;
            pre->rchild = p;
        }
        pre = p;
        if (p->ltag == 0)
            PreThread(p->lchild, pre);
        if (p->rtag == 0)
            PreThread(p->rchild, pre);
    }
}

// �����������������
void PreOrder(TBTNode* root) {
    TBTNode* p = root;
    while (p) {
        printf("%d ", p->data);
        while (p->ltag == 0) {
            p = p->lchild;
            printf("%d ", p->data);
        }
        while (p->rtag == 1 && p->rchild)
            p = p->rchild;
        p = p->rchild;
    }
}

/// ����������
void PostThread(TBTNode* p, TBTNode*& pre) {
    if (p) {
        PostThread(p->lchild, pre);
        PostThread(p->rchild, pre);
        if (!p->lchild) {
            p->ltag = 1;
            p->lchild = pre;
        }
        if (pre && !pre->rchild) {
            pre->rtag = 1;
            pre->rchild = p;
        }
        pre = p;
    }
}

// �����������������
void PostOrder(TBTNode* root) {
    if (!root) return;

    TBTNode* p = root;
    TBTNode* pre = NULL;

    while (p != NULL && p->ltag == 0) {
        p = p->lchild;
    }

    while (p) {
        if (p->rtag == 0 && p->rchild != pre) {
            p = p->rchild;
            while (p != NULL && p->ltag == 0) {
                p = p->lchild;
            }
        } else {
            printf("%d ", p->data);
            pre = p;
            p = p->rchild;
        }
    }
}









/*
void InThread(TBTNode*p,TBTNode* &pre);
*/
/*ͨ���������������*//*

void createInThread(TBTNode *root)
{
    TBTNode *pre=NULL;//ǰ���ڵ�ָ��
    if(root!=NULL)
    {
        InThread(root,pre);
        //������������һ���ڵ�
        pre->rchid=NULL;
        pre->rtag=1;
    }
}

void InThread(TBTNode*p,TBTNode* &pre)
{
    if(p!=NULL)
    {
        InThread(p->lchid,pre);//�ݹ�������������
        if(p->lchid==NULL)
        {
            //���������ӵ�ǰ������
            p->lchid=pre;
            p->ltag=1;
        }
        if(pre!=NULL&&pre->rchid==NULL)
        {
            //����ǰ���ڵ�ĺ������
            pre->rchid=p;
            pre->rtag=1;
        }
        pre=p;//��ǵ�ǰ�ڵ㣬ʹ��ɸոշ��ʵĽڵ�
        InThread(p->rchid,pre);
    }
}


*/
/*ͨ���������������*//*

void preThread(TBTNode *p,TBTNode *&pre)
{
    if(p!=NULL)
    {
        if(p->lchid==NULL)
        {
            p->lchid=pre;
            p->lchid=1;
        }
        if(pre!=NULL&&pre->rchid==NULL)
        {
            pre->rchid=p;
            pre->rtag=1;
        }
    }
    pre=p;
    if(p->ltag==0)
    {
        preThread(p->lchid,pre);
    }
    if(p->rtag==0)
    {
        preThread(p->rchid,pre);
    }
    */
/*Ϊ�����Ҫ�����ж����if(p->ltag == 0)�� if(p->rtag == 0)��

��Ϊ�˱����ظ�����ͬһ����㡣������ж����Һ����Ƿ�Ϊ��������ô������п��ܰ�����Ҳ�������Һ��������ʣ��Ӷ������ظ�����ͬһ�����(��ȦȦ~)�����յ���ջ�����*//*

}
*/

#endif //C_THREADEDBINARYTREE_H
