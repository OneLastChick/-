//
// Created by Npc on 2024/5/7.
//

#include "ActivityOnEdge.h"
int main()
{
    int n,e;
    cout<<"������ͼ�ĵ����ͱ���"<<endl;
    cin>>n>>e;
    Graph G(n,e);
    G.setve();
    G.setvl();
    G.sete();
    G.setl();
    G.getPoint();
    system("pause");
    return 0;
}

/*������ͼ�ĵ����ͱ���
9
11
������ ��� �ص� Ȩ��
1 2 6
1 3 4
1 4 5
2 5 1
3 5 1
4 6 2
5 7 9
5 8 7
6 8 4
7 9 2
8 9 4
v1 v2 v5 v5 v7 v8 v9  //�����ؼ�·��
 �밴���������. . .*/