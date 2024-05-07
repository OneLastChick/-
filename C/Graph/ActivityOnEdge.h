//
// Created by Npc on 2024/5/7.
//

#ifndef C_ACTIVITYONEDGE_H
#define C_ACTIVITYONEDGE_H


//AOEͼ��ǰ���Ǹ�ͼΪ�����޻�ͼ
/*AOEͼ��ؼ�·�������ǿ��԰�������һ�����̣�
 * �����Ĺ�����Ҫǰ��Ĺ������̵棬
 * �ȵ�ǰ������й���������֮��ſ��Կ�չ�����Ĺ�����
 * ����Ȩͼ�Ϳ�����������ı�ʾ������㵽�յ��·����ֻ��һ����
 * ������Ҫ·����ȫ���Ļ����ɺ�
 * �������̲��������
 * ��ˣ��������������������ʱ��ȡ���ڴ���㵽�յ���·�����ȣ�
 * ������·�������л����ʱ��֮�͡�
/*���ָ���
 �ؼ�·������AOE���У���ʼ�㵽�յ�������·������
 ����·���ϵĸ������������ʱ��֮�ͣ���·����Ϊ�ؼ�·����
 �ؼ�����ؼ�·���ϵĻ��Ϊ�ؼ����*/
/*�ؼ�·�������緢���¼����������¼���һ����
 * �¼���������ʱ��ve[k]����ʵ�Ͽ��Ա�ʾΪ����㵽k������·��,��Ϊ��������Ķ��壬����Ҫ������·���������¼������꣬���ܸ�k
 * �¼���������ʱ��vl[k],ͨ���յ㷢���������¼������ǿ��Եõ��������̵���ʱ��Ҳ��v[l],���ʱ���ǹ�����ʱ-k�ڵ㵽�յ���·��*/


#include "iostream"
#include "queue"
using namespace std;
const int MaxSize=20;
const int INF=INT_MAX;
int ve[MaxSize];
int vl[MaxSize];
int e[MaxSize];
int l[MaxSize];

typedef struct Edge
{
    int from;
    int to;
    int e;
    int l;
} Edge;

class Graph{
    int arcNum;//�ߵ�����
    int vertexNum;//�ڵ�����
    int arc[MaxSize][MaxSize];//����һ���ڽӾ���
    Edge edge[MaxSize]; //�߼�

public:
    //���캯��,��ʼ���ڽӾ���,
    Graph(int n,int e)//n�ǵ��������e�ıߵ�����
    {
        arcNum=e;
        vertexNum=n;
        for(int i=1;i<=vertexNum;++i)
        {
            for(int j=1;j<=vertexNum;++j)
            {
                if(i==j)
                {
                    arc[i][j]=0;
                }else{
                    arc[i][j]=INF;
                }
            }
        }
        //�������ݹ����ڽӾ���
        cout<<"������ ��� �ص� Ȩ��"<< endl;
        for(int i=1;i<=arcNum;++i)
        {
            int from,to,weight;
            cin>>from>>to>>weight;
            arc[from][to]=weight;
            edge[i].from=from;
            edge[i].to=to;
        }
    }

    //������ʱ��
    void setve()
    {
        int visited[MaxSize];
        queue<int>q;
        q.push(1);
        //��ʼ��
        for(int i=1;i<=vertexNum;++i)
        {
            ve[i]=0;
            visited[i]=0;
        }

        visited[1]=1;
        while (!q.empty())
        {
            int k=q.front();
            q.pop();
            for(int i=1;i<=vertexNum;++i)
            {
                if(arc[k][i]!=INF&&ve[k]+arc[k][i]>ve[i])
                {
                    ve[i]=ve[k]+arc[k][i];
                    if(visited[i]==0)
                    {
                        q.push(i);
                    }
                    visited[i]=1;
                }
            }
        }
    }


    void setvl()
    {
        queue<int>q;
        int visited[MaxSize];
        q.push(vertexNum);
        for(int i=1;i<=vertexNum;++i)
        {
            vl[i]=ve[vertexNum];
            visited[i]=0;
        }

        while (!q.empty())
        {
            int k=q.front();
            q.pop();
            for(int i=0;i<vertexNum;i++)
            {
                if(arc[i][k]!=INF&&vl[k]-arc[i][k]<vl[i])
                {
                    vl[i]=vl[k]-arc[i][k];
                    if(!visited[i])
                    {
                        q.push(i);
                    }
                    visited[i]=1;
                }
            }
        }
    }

    void sete()
    {
        for(int i=1;i<=arcNum;i++)
        {
            edge[i].e=ve[edge[i].from];
        }
    }

    void setl()
    {
        for(int i=1;i<=arcNum;i++)
        {
            edge[i].l=vl[edge[i].to]-arc[edge[i].from][edge[i].to];
        }
    }

    void getPoint()
    {
        int count=0;
        for(int i=1;i<=arcNum;++i)
        {
            if(edge[i].e==edge[i].l)
            {
                cout<<"v"<<edge[i].from<<" ";
                count=i;
            }
        }
        cout<<"v"<<edge[count].to;
    }
};
#endif //C_ACTIVITYONEDGE_H
