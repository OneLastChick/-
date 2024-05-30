/*
//
// Created by Npc on 2024/5/30.
//
#include "stdlib.h"
#include "stdio.h"
typedef int KeyType;//����ؼ�������
typedef struct {
    KeyType key;
}ElemType; //����Ԫ������

typedef struct BiTNode{
    ElemType data;
    BiTNode *lchid,*rchid;
}BiTNode,*BiTree;

int i; //ÿ��ѡȡ�ĸ��ڵ���±�
int min;
int dw;

//�ݹ鴴�����Ų�����,R����Ϊ���ұ�sw����Ϊ�洢�ĸ��ؼ��ֵĸ���,low��high��ʾsw�����е�Ȩֵ��Χ
void SecondOptimal(BiTree *T,ElemType R[],float sw[],int low,int high)
{
    if(low>high)
    {
        *T=NULL;
        return;
    }
    //�������R[low...high]�����ۼ�Ȩֵ��sw(sw[0]=0)���ݹ鹹����Ų�����
    i=low;
    min=abs(sw[high]-sw[low]);//��ʼ��һ����ǰȨֵ����
    dw=sw[high]+sw[low-1];
    //ѡ����С�ġ�Piֵ
    for(int j=low+1;j<=high;j++)//
    {
        int DPj=abs(dw-sw[j]-sw[j-1]);
        if(DPj<min)
        {
            i=j;
            min=DPj;
        }
    }

    //��ʼ����
    *T=(BiTree) malloc(sizeof(BiTNode));
    (*T)->data=R[i];//���ɽڵ㣬��һ�����ɸ�

    SecondOptimal(&(*T)->lchid,R,sw,low,i-1);//����������
    SecondOptimal(&(*T)->rchid,R,sw,i+1,high);//����������
}
//���������ӡ���ڵ�
void InOrderTraversal(BiTree T)
{
    if(T!=NULL)
    {
        InOrderTraversal(T->lchid);
        printf("%d ",T->data.key);
        InOrderTraversal(T->rchid);
    }
}
int main() {
    // ��������
    ElemType R[] = { {0}, {1}, {2}, {3}, {4}, {5} }; // ������5���ؼ��֣���1��5
    float sw[] = { 0, 2, 4, 6, 8, 10, 12 }; // ��Ӧ��Ȩֵ

    int n = sizeof(R) / sizeof(R[0]) - 1; // �ؼ�������

    BiTree T;
    SecondOptimal(&T, R, sw, 1, n); // �������Ų�����

    printf("InOrder traversal of the constructed SOST: ");
    InOrderTraversal(T);
    printf("\n");
    system("pause");
    return 0;
}*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef int KeyType; // ����ؼ�������

typedef struct {
    KeyType key;
} ElemType; // ����Ԫ������

typedef struct BiTNode {
    ElemType data;
    struct BiTNode* lchild, * rchild;
} BiTNode, * BiTree;

// �������Ų�����
void SecondOptimal(BiTree* T, ElemType R[], float sw[], int low, int high) {
    if (low > high) {
        *T = NULL;
        return;
    }

    int i = low;
    int min = abs((int)(sw[high] - sw[low]));
    int dw = (int)(sw[high] + sw[low - 1]);

    // ѡ����С�ġ�Piֵ
    for (int j = low + 1; j <= high; j++) {
        int diff = abs(dw - (int)(sw[j] + sw[j - 1]));
        if (diff < min) {
            i = j;
            min = diff;
        }
    }

    *T = (BiTree)malloc(sizeof(BiTNode));
    (*T)->data = R[i]; // ���ɽ�㣨��һ�����ɸ���
    (*T)->lchild = NULL;
    (*T)->rchild = NULL;

    // ȷ��������������ȷ����
    SecondOptimal(&((*T)->lchild), R, sw, low, i - 1); // ����������
    SecondOptimal(&((*T)->rchild), R, sw, i + 1, high); // ����������
}

// ���������ӡ���ڵ�
void InOrderTraversal(BiTree T) {
    if (T != NULL) {
        InOrderTraversal(T->lchild);
        printf("%d ", T->data.key);
        InOrderTraversal(T->rchild);
    }
}

int main() {
    // ��������
    ElemType R[] = { {0}, {1}, {2}, {3}, {4}, {5} }; // ������5���ؼ��֣���1��5
    float sw[] = { 0, 2, 4, 6, 8, 10, 12 }; // ��Ӧ��Ȩֵ

    int n = sizeof(R) / sizeof(R[0]) - 1; // �ؼ�������

    BiTree T;
    SecondOptimal(&T, R, sw, 1, n); // �������Ų�����

    printf("InOrder traversal of the constructed SOST: ");
    InOrderTraversal(T);
    printf("\n");
    system("pause");
    return 0;
}


