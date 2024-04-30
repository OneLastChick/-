//
// Created by Npc on 2024/4/25.
//




/*1. ��С����������������СȨ����������
��������������е���������������һ����ɵ�����һ���㣩��
 ������·��֮����С��ͼ����С��������
 ��С����������һ�����νṹ�����νṹ��һ�������ͼ����
 ����˵��ֱ���ͽṹ����Ϊ��n����������
 ��·������̣���ô������������·һ����n-1����

�������òο�һ�����������С��������
 ��n����ׯ��ÿ����ׯ֮����벻ͬ��
 Ҫ���ׯ֮����·��ÿһ����ׯ����������һ����ׯ��ͨ��
 �����·��ʡǮ���޵���̣�*/

/*2. ����ķ�㷨����
��ķ(Prim)�㷨����С��������Ҳ�����ڰ���n���������ͨͼ�У�
 �ҳ�ֻ��(n-1)���߰�������n���������ͨ��ͼ��Ҳ������ν�ļ�С��ͨ��ͼ

����������£�

(1)��G=(V,E)����ͨ����T=(U,D)����С��������V,U�Ƕ��㼯�ϣ�E,D�Ǳߵļ���

(2)���Ӷ���u��ʼ������С����������Ӽ���V��ȡ������u���뼯��U�У�
 ��Ƕ���v��visited[u]=1

(3)������U�ж���ui�뼯��V-U�еĶ���vj֮����ڱߣ���Ѱ����Щ����Ȩֵ��С�ıߣ�
 �����ܹ��ɻ�·��������vj���뼯��U�У����ߣ�ui,vj��
 ���뼯��D�У����visited[vj]=1

(4)�ظ�����ڣ�ֱ��U��V��ȣ������ж��㶼�����Ϊ���ʹ�����ʱD����n-1����*/
#ifndef C_PRIM_H
#define C_PRIM_H
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#define n 5
#define Maxnum 10000
//�����ڽӾ�������
typedef int adjmatrix[n+1][n+1];
typedef struct {
    int fromvex,tovex;
    int weight;
}Edge;
typedef Edge *EdgeNode;

int arcnum; //�ߵĸ���

/*����ͼ���ڽӾ���*/
void createAdjMatrix(adjmatrix GA)
{
    int i,j,k,e;
    printf("====================================\n");
    printf("ͼ����%d������\n",n);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(i==j)
            {
                GA[i][j]==0;  //�ڽӾ���ĶԽ��߶���0
            }
            else{
                GA[i][j]=Maxnum;
            }
        }
    }

    printf("������ߵĸ���:\n");
    scanf("%d",&arcnum);
    printf("������ߵ���Ϣ����������յ��Ȩֵ����ʽ����:\n");
    //����ߵ���Ϣ
    for(k=1;k<=arcnum;k++)
    {
        scanf("%d,%d,%d",&i,&j,&e);
        GA[i][j]=e;
        GA[i][j]=e;
    }
}

//��ʼ��ͼ�ı߼�����
void InitEdge(EdgeNode GE,int m)
{
    int i;
    for(i=1;i<=m;i++)
    {
        GE[i].weight=0;
    }
}
//����ͼ���ڽӾ�������ͼ�ı߼�����
void GetEdgeSet(adjmatrix GA,EdgeNode GE)
{
    int i,j,k=1;
    for(i=1;i<=n;i++)
    {
        for(j=i+1;j<=n;j++)
        {
            if(GA[i][j]!=0&&GA[i][j]!=Maxnum)
            {
                GE[k].fromvex=i;
                GE[k].tovex=j;
                GE[k].weight=GA[i][j];
                k++;
            }
        }
    }
}

//����������ͼ�ı߼�����
void SortEdge(EdgeNode GE,int m)
{
    int i,j,min;
    Edge temp;
    //ѡ������
    for(i=1;i<m;i++)
    {
        min=i;
        for(j=i+1;j<=m;j++)
        {
            if(GE[min].weight>GE->weight)
            {
                min=j;
            }
        }
        if(min!=i)
        {
            temp=GE[i];
            GE[i]=GE[min];
            GE[min]=temp;
        }
    }
}

/*����Prim�㷨�ӳ�ʼ��v�������ڽӾ����ʾ��ͼ����С������
����������£�

(1)��G=(V,E)����ͨ����T=(U,D)����С��������V,U�Ƕ��㼯�ϣ�E,D�Ǳߵļ���

(2)���Ӷ���u��ʼ������С����������Ӽ���V��ȡ������u���뼯��U�У�
 ��Ƕ���v��visited[u]=1

(3)������U�ж���ui�뼯��V-U�еĶ���vj֮����ڱߣ���Ѱ����Щ����Ȩֵ��С�ıߣ�
 �����ܹ��ɻ�·��������vj���뼯��U�У����ߣ�ui,vj��
 ���뼯��D�У����visited[vj]=1

(4)�ظ�����ڣ�ֱ��U��V��ȣ������ж��㶼�����Ϊ���ʹ�����ʱD����n-1����*/
void Prim(adjmatrix GA,EdgeNode T)  //T�����ڴ洢��С�������ı߼���
{
    int i,j,k,min,u,m,w;
    Edge temp;
    /*��T����ֵ����ӦΪv1���ε����������ı�*/
    k=1;
    for(i=1;i<=n;i++)
    {
        if(i!=1)
        {
            T[k].fromvex=1;
            T[k].tovex=i;
            T[k].weight=GA[1][i];
            k++;
        }
    }
    //����n-1��ѭ����ÿ�������С�������еĵ�k����
    for(k=1;k<n;k++)
    {
        min=Maxnum;
        m=k; //m����СȨ�ߵ��±�
        for(j=k;j<n;j++)
        {
            if(T[j].weight<min)
            {
                min=T[j].weight;
                m=j;
            }
        }
        /*����̱߶Ե���k-1���±�λ��*/
        temp=T[k];
        T[k]=T[m];
        T[m]=temp;
        /*����������С������T�еĶ�������׸�j*/
        j=T[k].tovex;
        /*�Ķ��йرߣ�ʹT�е�T���ÿ�����㱣��һ��������Ϊֹ��̵ı�*/
        for(i=k+1;i<n;i++)
        {
            u=T[i].tovex;
            w=GA[j][u];
            if(w<T[k].weight){
                T[i].weight=w;
                T[i].fromvex=j;
            }
        }
    }
}

void OutEdge(EdgeNode GE,int e)
{
    int i;
    printf("������㣬�յ㡣Ȩֵ����ʽ�������С������Ϊ��\n");
    for(i=1;i<=e;i++)
    {
        printf("%d,%d,%d\n",GE[i].fromvex,GE[i].tovex,GE[i].weight);
    }
    printf("==========================================");
}
#endif //C_PRIM_H
