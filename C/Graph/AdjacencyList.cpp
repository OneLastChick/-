//
// Created by Npc on 2024/4/24.
//

/*�ڽӱ�Adjacency List������˼�壬����ͨ�����������������ģ������ķ�ʽ��ͼ�������ӹ�ϵ��ʾ��һ�ַ�����
 * �洢���������ĺ�������ʾ�������ƣ���һ��˳��������ʽ�������ϵĴ洢�ṹ��
 * �������ͷ�������Ӧ�Ķ���������ڶ��㣬
 * ������ڶ������δ���ڱ�ͷ�����ָ��ĵ��������С�*/
#include "stdio.h"
#include "iostream"
#include "malloc.h"
#define maxSize 1000
using namespace std;
typedef struct ArcNode{
    int adjvex;
    struct ArcNode *nextarc;
}ArcNode;

typedef struct{
    int data;
    ArcNode *firstarc;
}Vnode;


typedef struct {
    Vnode adjlist[maxSize];
    int n,e;
}AGraph;//�������ýṹ������ṹ��Ҳ������

AGraph *graph;


//��������β��
void insertNode(ArcNode *node,ArcNode *newNode)
{
    ArcNode *p=node;
    while(p->nextarc!=NULL)
    {
        p=p->nextarc;
    }
    p->nextarc=newNode;
}

void create() {
    graph = (AGraph *) malloc(sizeof(AGraph));
    cout << "���붥�����Ŀ:" << endl;
    cin >> graph->n;
    cout << "����ͼ�бߵ���Ŀ��" << endl;
    cin >> graph->e;
    int u = -1, v = -1;
    //��ʼ���м�����
    for (int i = 0; i < graph->n; i++) {
        graph->adjlist[i].firstarc = NULL;
    }

    ArcNode *node;
    for (int i = 0; i < graph->e; i++) {
        cout << "��������ͨ��A��B" << endl;
        cin >> u >> v;
        node = (ArcNode *) malloc(sizeof(ArcNode));
        node->adjvex = v;
        node->nextarc = NULL;
        graph->adjlist[u].data = u;
        if (graph->adjlist[u].firstarc == NULL) {
            //��
            graph->adjlist[u].firstarc = node;
        } else {
            //�����
            insertNode(graph->adjlist[u].firstarc, node);
        }
    }
}


void traverseTree()
{
    for(int i=0;i<graph->n;i++)
    {
        if(graph->adjlist[i].firstarc!=NULL)
        {
            cout<<"��"<<i<<"���ӵĵ���:";
            ArcNode *p=graph->adjlist[i].firstarc;
            while(p!=NULL)
            {
                cout<<p->adjvex<<" ";
                p=p->nextarc;
            }
        }
    }
}


int main()
{
    create();
    traverseTree();
    cout<<endl;
    system("pause");
    return 0;
}