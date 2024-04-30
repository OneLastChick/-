//
// Created by Npc on 2024/4/30.
//

#include "Dijkstra.h"
int main()
{
    int i,j;
    MGraph g;
    createDN(g);
    int p[MAX_VERTEX_NUM][MAX_VERTEX_NUM];//���·������p
    int D[MAX_VERTEX_NUM];//��̾�������D
    ShortestPath_Dijkstra(g,0,p,D);

    cout<<"���·������p[i][j]���£�"<<endl;
    for(i=0;i<g.vexnum;i++)
    {
        for(j=0;j<g.vexnum;j++)
        {
            cout<<setw(3)<<p[i][j]<<" ";
        }
        cout<<endl;
    }


    cout<<g.vexs[0]<<"������������·��������Ϊ:"<<endl;
    for(i=0;i<g.vexnum;i++)
    {
        if(i!=0&&D[i]!=INFINITY)
        {
            cout<<g.vexs[0]<<"-"<<g.vexs[i]<<"�����·������Ϊ��"<<D[i];
            cout<<"  ���·��Ϊ ��";
            for(j=0;j<g.vexnum;j++)
            {
                if(p[i][j]>-1)
                {
                    cout<<g.vexs[p[i][j]]<<" ";
                }
            }
            cout<<endl;
        }else if(D[i]==INFINITY)
        {
            cout<<g.vexs[0]<<"-"<<g.vexs[i]<<":"<<"���ɴ�"<<endl;
        }
    }
    system("pause");
    return 0;
}
/*��������
 * �����붥�����ͱ���:5 7
�����붥�㣺A B C D E
������ߺ�ȨֵA D 2
A B 4
B D 1
D C 1
B C 4
D E 7
C D 1
���·������p[i][j]���£�
 -1  -1  -1  -1  -1
  0   1  -1  -1  -1
  0   3   2  -1  -1
  0   3  -1  -1  -1
  0   3   4  -1  -1
A������������·��������Ϊ:
A-B�����·������Ϊ��4  ���·��Ϊ ��A B
A-C�����·������Ϊ��3  ���·��Ϊ ��A D C
A-D�����·������Ϊ��2  ���·��Ϊ ��A D
A-E�����·������Ϊ��9  ���·��Ϊ ��A D E*/