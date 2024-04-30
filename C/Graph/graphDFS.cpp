//
// Created by Npc on 2024/4/25.
//DFS��Depth-First-Search����������������㷨�ľ��������ǣ���ĳ����һֱ����ߣ��ߵ�����������֮��
// �ͻ��˵���һ����ֱ���ҵ��������е����ꡣ


/*
void dfs()//����������ʾ״̬
{
    if(�����յ�״̬)
    {
        ...//�����������
        return;
    }
    if(Խ������ǲ��Ϸ�״̬)
        return;
    if(����״̬)//��֦��ȥ��һЩ����Ҫ���ʵĳ�������һ��i����
        return ;
    for(��չ��ʽ)
    {
        if(��չ��ʽ���ﵽ״̬�Ϸ�)
        {
            �޸Ĳ���;//�������������
            ��ǣ�
            dfs������
            (��ԭ���)��
            //�Ƿ�ԭ��Ǹ�������
            //������ϣ���ԭ��ǣ����� ���ݷ�
        }

    }
}*/
//��pos�㿪ʼ����ȱ�������ͼ
//pos��ʾ��ǰ��㣬G��ʾͼ��visited[]����������ʾ�ýڵ��Ƿ��Ѿ�����
#include <stdio.h>
#include <stdlib.h>

// ����ͼ�Ķ���ṹ��
typedef struct ArcNode {
    int adjvex;             // �ڽӵ��ڶ��������е��±�
    struct ArcNode *next;   // ָ����һ���ڽӵ��ָ��
} *node;

typedef struct VertexNode {
    node firstarc;          // ָ���һ���ڽӵ��ָ��
} VertexNode;

typedef struct Graph {
    VertexNode vertice[30]; // ͼ�Ķ�������
} *pGraph;

// ��ʼ��ͼ
pGraph initGraph() {
    pGraph G = (pGraph)malloc(sizeof(struct Graph));
    for (int i = 0; i < 30; ++i) {
        G->vertice[i].firstarc = NULL;
    }
    return G;
}

// ��ӱߵ�ͼ��
void addEdge(pGraph G, int from, int to) {
    node newNode = (node)malloc(sizeof(struct ArcNode));
    newNode->adjvex = to;
    newNode->next = G->vertice[from].firstarc;
    G->vertice[from].firstarc = newNode;
}

// ���������������
void DFS(int pos, pGraph G, int visited[30]) {
    node p;
    printf("%d ", pos);    // ��ӡ��ȱ����ĵ�
    visited[pos] = 1;      // ���Ϊ�ѷ��ʹ�
    p = G->vertice[pos].firstarc;  // ����ǰ��ĵ�һ��ָ�븳ֵ��p
    // �Ƿ�����ڽӵ�
    while (p != NULL) {
        // �жϸ��ڽӵ��Ƿ񱻱�����
        if (visited[p->adjvex] == 0) {
            DFS(p->adjvex, G, visited);
        }
        p = p->next;    // ����һλ��Ϊ֮���Ƿ����ڽӵ���׼��
    }
}

int main() {
    // ��ʼ��ͼ
    pGraph G = initGraph();
    int visited[30] = {0};  // ��ʼ�����ʱ������
    // ��ӱߵ�ͼ��
    addEdge(G, 0, 1);
    addEdge(G, 0, 2);
    addEdge(G, 1, 3);
    addEdge(G, 1, 4);
    addEdge(G, 2, 5);
    // ���������������ӡ�������
    printf("DFS result: ");
    DFS(0, G, visited);
    printf("\n");
    system("pause");
    return 0;
}
/*
    0
   / \
  1   2
 / \   \
3   4   5
*/
