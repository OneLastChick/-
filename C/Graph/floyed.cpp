//
// Created by Npc on 2024/5/6.
//

#include "floyed.h"
bool check(int Vexnum, int edge) {
    if (Vexnum <= 0 || edge <= 0 || ((Vexnum*(Vexnum - 1)) / 2) < edge)
        return false;
    return true;
}
int main() {
    int vexnum; int edge;
    cout << "����ͼ�����ࣺ1��������ͼ��2��������ͼ" << endl;
    int kind;
    cin >> kind;
    //�ж������kind�Ƿ�Ϸ�
    while (1) {
        if (kind == 1 || kind == 2) {
            break;
        }
        else {
            cout << "�����ͼ�������Ų��Ϸ������������룺1��������ͼ��2��������ͼ" << endl;
            cin >> kind;
        }
    }

    cout << "����ͼ�Ķ�������ͱߵ�������" << endl;
    cin >> vexnum >> edge;
    while (!check(vexnum, edge)) {
        cout << "�������ֵ���Ϸ�������������" << endl;
        cin >> vexnum >> edge;
    }
    Graph_DG graph(vexnum, edge);
    graph.createGraph(kind);
    graph.printAdjMatrix();
    graph.Floyd();
    graph.printPath();
    system("pause");
    return 0;
}
/*���룺

2
7 12
1 2 12
1 6 16
1 7 14
2 3 10
2 6 7
3 4 3
3 5 5
3 6 6
4 5 4
5 6 2
5 7 8
6 7 9
 */