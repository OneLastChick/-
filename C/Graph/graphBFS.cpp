//
// Created by Npc on 2024/4/25.
//

/**
 * ���غ��ʵļ�������
 */
/*
int BFS(Node root, Node target)
{
    Queue<Node> queue;  //��������
    int step = 0;       // ��ǰ���еĲ����
    // initialize
    add root to queue;
    // BFS
    while (queue is not empty)
    {
        step = step + 1;
        //����������
        int size = queue.size();
        for (int i = 0; i < size; ++i)
        {
            Node cur = the first node in queue;
            if cur is target
                return step - 1;
            for (Node next : the neighbors of cur)
            {//���ﳣ��һ����ά��������ʵ��
                add next to queue;
            }
            remove the first node from queue;
        }
    }
    return -1;          //������ֵ
}*/
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
    int Vnum;               // ͼ�Ķ�������
} *pGraph;

// ��ʼ��ͼ
pGraph initGraph(int Vnum) {
    pGraph G = (pGraph)malloc(sizeof(struct Graph));
    for (int i = 0; i < 30; ++i) {
        G->vertice[i].firstarc = NULL;
    }
    G->Vnum = Vnum;
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
void BFSL(int pos, pGraph G, int visited[30]) {
    int queue[G->Vnum];     // ���и��� BFS ����
    int head = 0, tail = 0; // ��ͷ����βָ��
    node p;
    queue[tail] = pos;
    visited[pos] = 1;       // ��Ǳ�����
    tail++;
    while (head != tail) {
        pos = queue[head];  // ���Ӳ���
        head++;
        printf("%d ", pos);
        p = G->vertice[pos].firstarc;
        while (p != NULL) {
            if (visited[p->adjvex] == 0) // �ж��Ƿ������
            {
                queue[tail] = p->adjvex;    // ��Ӳ���
                visited[p->adjvex] = 1;     // ��Ǳ�����
                tail++;
            }
            p = p->next;
        }
    }
}

int main() {
    // ��ʼ��ͼ
    pGraph G = initGraph(6);
    int visited[30] = {0};  // ��ʼ�����ʱ������
    // ��ӱߵ�ͼ��
    addEdge(G, 0, 1);
    addEdge(G, 0, 2);
    addEdge(G, 1, 3);
    addEdge(G, 1, 4);
    addEdge(G, 2, 5);
    // ���������������ӡ�������
    printf("BFS result: ");
    BFSL(0, G, visited);
    printf("\n");
    system("pause");
    return 0;
}
/*
   0
  / \
 1   2
 |   |
 4   5
 |
 3
*/
