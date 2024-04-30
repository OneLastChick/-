//
// Created by Npc on 2024/4/28.
//

#ifndef C_KRUSKAL_H
#define C_KRUSKAL_H
/*1. ��³˹�����㷨���
��³˹������Kruskal���㷨��һ������Ѱ����С���������㷨���������Ȩ��ͨͼ����С���������㷨������ʣ�µ�����δѡȡ�ı��У�����С�ߣ��������ѡȡ�ı߹��ɻ�·���������ѡȡ��С�ߡ�

������Ĳ�������Ϊ��

a) ��ͼ������������ȥ����ֻʣ����

b) ��ͼ�ı߼��������ҵ�Ȩֵ��С�ıߣ����ߵ�����������������

c)  ����Ѱ��Ȩֵ��С�ıߣ�����������֮���������������ѡ��ı�ʹ����С�����������˻�·��������ñߣ�ѡ��Ȩֵ��С�ı�

d) ֱ�����еĶ��㶼��������һ����û�л�·����С�������������ˡ�*/
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#define MAXEDGE 100
#define MAXVERTEX 100
typedef struct Edge{
    int begin; //�ߵ����
    int end; //�ߵ��յ�
    int weight; //�ߵ�Ȩֵ
}Edge;

typedef struct Graph{
    char vertex[MAXVERTEX];
    Edge edges[MAXEDGE];
    int numvertex,numedges;
}MGraph;

void CreateGraph(MGraph *G)
{
    printf("�����붥��ͱߵĸ���:\n");
    scanf("%d %d",&G->numvertex,&G->numedges);
    printf("�����붥�㣺\n");
    getchar();//���øú������������
    for(int i=0;i<G->numvertex;i++)
    {
        scanf("%c",&G->vertex[i]);
    }
    printf("��Ȩֵ��С���������(vi,vj)��Ӧ�������յ���±꣬begin,end,�Լ�Ȩֵweight��\n");
    for(int k=0;k<G->numedges;k++)
    {
        Edge e;
        scanf("%d%d%d",&e.begin,&e.end,&e.weight);
        G->edges[k]=e;
    }
}

int Find(int *parent,int f)
{
    while(parent[f]>0)
    {
        f=parent[f];
    }
    return f;
}

//��С������,��³˹�����㷨
void Kruskal(MGraph *G)
{
    int parent[MAXVERTEX]; //�����С�������Ķ���
    for(int i=0;i<G->numvertex;i++)
    {
        parent[i]=0;
    }
    int m,n;
    for(int i=0;i<G->numvertex;i++)
    {
        n= Find(parent,G->edges[i].begin);
        m= Find(parent,G->edges[i].end);
        if(n!=m)//n=m˵���л�
        {
            parent[n]=m;
            printf("(%d,%d) %d\t",G->edges[i].begin,G->edges[i].end,G->edges[i].weight);
            //��ӡ�ߺ�Ȩֵ

        }
    }
}
#endif //C_KRUSKAL_H
