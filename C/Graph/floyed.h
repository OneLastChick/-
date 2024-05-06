//
// Created by Npc on 2024/5/6.
//

#ifndef C_FLOYED_H
#define C_FLOYED_H
#include "stdio.h"
#include "stdlib.h"
#include "iostream"
#include "string"
#include "limits.h"
using namespace std;

class Graph_DG{
private:
    int vexnum;//ͼ�Ķ������
    int edge;//ͼ�ı���
    int **arc;//�ڽӾ���
    int **dis;//��¼�����������·������Ϣ
    int **path;//��¼�������·������Ϣ
public:
    //���캯��
    Graph_DG(int vexnum,int edge);
    //��������
    ~Graph_DG();
    //�ж���������ıߵ���Ϣ�Ƿ�Ϸ�
    //�����1��ʼ���
    bool check_edge_value(int start,int end,int weight);
    //����ͼ
    void createGraph(int);
    //��ӡ�ڽӾ���
    void printAdjMatrix();
    //�����·��
    void Floyd();
    //��ӡ���·��
    void printPath();
};
Graph_DG::Graph_DG(int vexnum, int edge) {
    //��ʼ���������ͱ���
    this->vexnum=vexnum;
    this->edge=edge;
    //Ϊ�ڽӾ��󿪱ٿռ�͸���ֵ
    arc=new int*[this->vexnum];
    dis=new int*[this->vexnum];
    path=new int*[this->vexnum];
    for(int i=0;i<this->vexnum;i++)
    {
        arc[i]=new int[this->vexnum];
        dis[i]=new int[this->vexnum];
        path[i]=new int[this->vexnum];
        //��ʼ���ڽӾ���
        for(int k=0;k<this->vexnum;k++)
        {
            //�ڽӾ����ʼ��Ϊ�����
            arc[i][k]=INT_MAX;
        }
    }
}

//��������
Graph_DG::~Graph_DG() {
    //�ͷ��ڴ�
    for(int i=0;i<this->vexnum;i++)
    {
        delete this->arc[i];
        delete this->dis[i];
        delete this->path[i];
    }
    delete dis;
    delete arc;
    delete path;
}

//�ж�����ÿ�ε������Ƿ�Ϸ�
//�����1��ʼ���
bool Graph_DG::check_edge_value(int start, int end, int weight) {
    if(start<1||end<1||start>vexnum||end>vexnum||weight<0)
    {
        return false;
    }
    return true;
}


void Graph_DG::createGraph(int kind) {
    cout<<"������ÿ���ߵ������յ㣨�����Ŵ�1��ʼ)�Լ�Ȩ��"<<endl;
    int start;
    int end;
    int weight;
    int count=0;
    while(count!=this->edge)
    {
        cin>>start>>end>>weight;
        //�����жϱߵ���Ϣ�Ƿ�Ϸ�
        while(!this->check_edge_value(start,end,weight))
        {
            cout<<"����ıߵ���Ϣ���Ϸ�������������"<<endl;
            cin>>start>>end>>weight;
        }
        //���ڽӾ����Ӧ�ϵĵ㸳ֵ
        arc[start-1][end-1]=weight;
         //���������ͼ
         if(kind==2)
            arc[end-1][start-1]=weight;
         ++count;
    }
}

void Graph_DG::printAdjMatrix() {
    cout<<"ͼ���ڽӾ���Ϊ:"<<endl;
    int count_row=0;//��ӡ�еı�ǩ
    int count_col=0;//��ӡ�еı�ǩ

    //��ʼ��ӡ
    while(count_row!=this->vexnum){
        count_col=0;
        while (count_col!= this->vexnum)
        {
            if(arc[count_row][count_col]==INT_MAX)
            {
                cout<<"��"<<" ";
            }
            else{
                cout<<arc[count_row][count_col]<<" ";
            }
            ++count_col;
        }
        cout<<endl;
        ++count_row;
    }
}

//���·���㷨Floyd
void Graph_DG::Floyd() {
    int row=0;
    int col=0;

    //�Ѿ���dis��ʼ��Ϊ�ڽӾ����ֵ
    for(row=0;row<this->vexnum;row++)
    {
        for(col=0;col<this->vexnum;col++)
        {
            this->dis[row][col]=this->arc[row][col];
            //����P�ĳ�ֵ��Ϊÿ���ߵ��յ㶥����±�
            this->path[row][col]=col;
        }
    }

    //��̬�滮��˼�룬����ÿ���м����ÿ����Ե����·��
    int temp=0;
    int select=0;
    for(temp=0;temp<this->vexnum;temp++)
    {
        for(row=0;row<this->vexnum;row++)
        {
            for(col=0;col<this->vexnum;col++)
            {
                //Ϊ�˷�ֹ���������һ��selectֵ
                select=(dis[row][temp]==INT_MAX||dis[temp][col]==INT_MAX)?INT_MAX:(dis[row][temp]+dis[temp][col]);
                if(this->dis[row][col]>select)
                {
                    //����D����
                    this->dis[row][col]=select;
                    //����P����
                    this->path[row][col]=this->path[row][temp];
                }

            }

        }
    }
}

void Graph_DG::printPath() {
    cout<<"��������Ե����·��:"<<endl;
    int row=0;
    int col=0;
    int temp=0;
    for(row=0;row<this->vexnum;row++)
    {
        for(col=row+1;col<this->vexnum;col++)
        {
            cout<<"v"<<to_string(row+1)<<"---"<<"v"<<to_string(col+1)<<"weight:"<<
            this->dis[row][col]<<"path:"<<"v"<<to_string(row+1);
            //ѭ�����;����ÿ��·��
            temp=path[row][col];

            while(temp!=col)
            {
                cout<<"-->"<<"v"<<to_string(temp+1);
                temp=path[temp][col];
            }

            cout<<"-->"<<"v"<<to_string(col+1)<<endl;

        }
        cout<<endl;
    }
}
#endif //C_FLOYED_H
