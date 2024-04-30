//
// Created by Npc on 2024/4/30.
//

#ifndef C_DIJKSTRA_H
#define C_DIJKSTRA_H
/*���·��������ͼ���о��е�һ�������㷨���⣬ּ��Ѱ��ͼ���ɽ���·����ɵģ��������֮������·�������¿��Է�Ϊ���¼������⣬��������η������⣬�䱾��˼�뻹�ǲ���ģ���������������̾��롣

a) ȷ���������·������ - ����֪��ʼ��㣬�����·�������⡣

b) ȷ���յ�����·������ - ��ȷ�����������෴������������֪�ս��㣬�����·�������⡣������ͼ�и�������ȷ������������ȫ��ͬ��������ͼ�и������ͬ�ڰ�����·������ת��ȷ���������⡣

c) ȷ������յ�����·������ - ����֪�����յ㣬�������֮������·����

d) ȫ�����·������ - ��ͼ�����е����·����*/


/*dijkstra�㷨�ĺ���˼·�ǣ�

1) ָ��һ���ڵ㣬��������Ҫ���� 'A' �������ڵ�����·��

2) �����������ϣ�S��U����
 S���ϰ�������������·���ĵ㣨�Լ���Ӧ����̳��ȣ���
 U���ϰ���δ������·���ĵ㣨�Լ�A���õ��·����
 ע�� ����ͼ��ʾ��A->C����û��ֱ������ ��ʼʱΪ�ޣ�

3) ��ʼ���������ϣ�S���ϳ�ʼʱ ֻ�е�ǰҪ����Ľڵ㣬A->A = 0��

4) U���ϳ�ʼʱΪ A->B = 4, A->C = ��, A->D = 2, A->E = ��

5) ��U�������ҳ�·����̵ĵ㣬����S���ϣ����� A->D = 2

6) ����U����·����if ( 'D �� B,C,E �ľ���' + 'AD ����' < 'A �� B,C,E �ľ���' ) �����U

7) ѭ��ִ�� 4��5 �����裬ֱ�������������õ�A �������ڵ�����·��*/
#include "iostream"
#include "iomanip"
#include "string"
using namespace std;
#define INFINITY 65535
#define MAX_VERTEX_NUM 10

typedef struct MGraph{
    string vexs[10]; //������Ϣ
    int arcs[10][10]; //�����ڽӾ���
    int vexnum,arcnum; //�������ͱ���
}MGraph;

int LocateVex(MGraph G,string u)
{//���ض���u��ͼ�е�λ��
    for(int i=0;i<G.vexnum;i++)
    {
        if(G.vexs[i]==u)
            return i;
    }
    return -1;//δ�ҵ�
}

void createDN(MGraph &G)
{//����������
    string v1,v2;
    int w;//Ȩ��
    int i,j,k;
    cout<<"�����붥�����ͱ���:";
    cin>>G.vexnum>>G.arcnum;

    cout<<"�����붥�㣺";
    for(i=0;i<G.vexnum;i++)
    {
        cin>>G.vexs[i];
    }

    for(i=0;i<G.vexnum;i++){
        for(j=0;j<G.vexnum;j++)
        {
            G.arcs[i][j]=INFINITY; //��ʼ���ڽӾ���
        }
    }

    cout<<"������ߺ�Ȩֵ";
    for(k=0;k<G.arcnum;k++)
    {
        cin>>v1>>v2>>w;
        i= LocateVex(G,v1);
        j= LocateVex(G,v2);
        G.arcs[i][j]=w;  //������������ֵ
    }
}

/*//�Ͻ�˹�����㷨��������G��v0���㵽���ඥ��v�����·��p[v]����Ȩ����D[v]
//p[][]=-1��ʾû��·����p[v][i]����Ǵ�v0��v��ǰ��õ����·�������ĵ�i+1������
 (���Ǵ�ӡ���·���Ĺؼ�)����v0��v�����·����Ϊp[v][0]��p[v][j]ֱ��p[v][j]=-1,
 ·����ӡ��ϡ�
//final[v]Ϊtrue���ҽ���v��S,���Ѿ���ô�v0��v�����·����*/
void ShortestPath_Dijkstra(MGraph G,int v0,int p[][MAX_VERTEX_NUM],int D[])
{
    int v,w,i,j,min;
    bool final[10];

    for(v=0;v<G.vexnum;v++)//v������ı��
    {
        final[v]=false;//���ó�ֵ
        D[v]=G.arcs[v0][v];//D[]���v0��v����̾��룬��ֵΪv0��v��ֱ�Ӿ���
        for(w=0;w<G.vexnum;w++)
        {
            p[v][w]=-1;//��p[][]��ֵΪ-1����û��·��
        }
        if(D[v]<INFINITY)
        {
            p[v][0]=v0; //v0��v��ֱ��·��  �Ͱѵ�һ�����㸳��v0���ڶ������㸳��v1
            p[v][1]=v;
        }
    }

    D[v0]=0; //v0���������Ϊ0
    final[v0]= true; //v0���㲢��S��

    for(i=1;i<G.vexnum;i++)//ÿ��ѭ������һ��������S��
    {
        //��������G.vexnum-1������
        //��ʼ��ѭ��,ÿ�����v0��ĳ������v�����·��������v����S��������p��D
        min=INFINITY;
        for(w=0;w<G.vexnum;w++)
        {
            //�����ж�����
            if(!final[w]&&D[w]<min){
                //��S��֮��Ķ������ҵ���v0����Ķ��㣬���丳��v�����븳��min
                v=w;
                min=D[w];
            }
        }
        final[v]= true;//��v����S��
        for(w=0;w<G.vexnum;w++)
        {
            //��S��֮���ҵ���v0����ĵ�
            if(!final[w]&&D[w]<min)
            {
                v=w;
                min=D[w];
            }
        }
        final[v]= true; //��S����v0����ĵ㲢��S��
        for(w=0;w<G.vexnum;w++)
        {
            //�����²���Ķ��㣬���²���S���Ķ��㵽v0�ľ����·������
            if(!final[w]&&min<INFINITY&&G.arcs[v][w]<INFINITY&&(min+G.arcs[v][w]<D[w]))
            {
                //w������S����v0->v>w�ľ���<Ŀǰv0->w�ľ���
                D[w]=min+G.arcs[v][w];
                for(j=0;j<G.vexnum;j++)
                {
                    p[w][j]=p[v][j]; //���·��
                    if(p[w][j]==-1)
                    {
                        p[w][j]=w;
                        break;
                    }
                }
            }
        }


    }

}

#endif //C_DIJKSTRA_H
