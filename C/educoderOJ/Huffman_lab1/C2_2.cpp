
//Your code begin.
//ʾ�������ο�����Ҳ���������޸����
#include<stdio.h>
#include<stdlib.h>
#include "string.h"
/*1.�������񣺽���Ƶ��������ͳ���ַ���Ƶ�ȡ�*/
/*2.����������,���ַ���Ƶ�������д��ڣ�����ַ���Ƶ�ȼ�1�����򴴽��½�㲢���ý����뵽Ƶ��������*/
/*3.����������,�����õ���Ƶ�������������ʹ���ַ���Ƶ�Ȱ��Ӹߵ�������*/
/*�������룺
hello world!
Ԥ�������
'l' 3
'o' 2
'h' 1
'e' 1
' ' 1
'w' 1
'r' 1
'd' 1
'!' 1

�������룺
Data structure experiment
HuffmanTree
metro line
Ԥ�������
'e' 8
't' 5
'r' 5
'a' 3
' ' 3
'u' 3
'm' 3
'n' 3
'i' 2
'\n' 2
'f' 2
'D' 1
's' 1
'c' 1
'x' 1
'p' 1
'H' 1
'T' 1
'o' 1
'l' 1*/
/*��ʾ��
1.�ַ���Ƶ�ȴӸߵ������У���ͬƵ�ȵ��ַ��������Ⱥ�������У���������ַ�������ǰ����������ַ������ں�
2.���ʾ��Ϊ'�ַ�' Ƶ�ȣ��ַ���Ƶ��֮����һ���ո������һ���ַ���Ƶ�Ⱥ����������һ���ַ���Ƶ��
3.���з��ַ����ʾ��'\n' 10
4.���һ���ַ���Ƶ������������һ�����з�Ҫ���*/
typedef struct ListNode            //���ṹ������������Ƶ��������
{
    char c;                    //�����ַ�
    int frequency;            // �ַ���Ƶ��
    char *code;            // �ַ��ı���(�Թ������������Ч)
    struct ListNode *parent;            //����˫T�׽��(�Թ������������Ч)
    struct ListNode *left;                //����������(�Թ������������Ч)
    struct ListNode *right;                // ����������(�Թ������������Ч)
    struct ListNode *next;                // ���ĺ�̽��(��Ƶ����������Ч)
} ListNode, HuffmanTree;
/*frequency���൱��weight*/
/*����HuffmanTree֮ǰҪ�Ƚ����ڵ�*/
/*���������ǻ���head������ͷ��������¿����������Ա�����������Ĵ����Ӷ��򻯲���*/
ListNode *createOneNode(char ch) {
    ListNode *temp = (ListNode *) malloc(sizeof(ListNode));
    temp->c = ch;
    temp->frequency = 1;
    temp->next = NULL;
    temp->left = NULL;
    temp->right = NULL;
    temp->parent = NULL;
    return temp;
}

/*���Ҹ��ַ��Ƿ��ڸ�������*/
int isInList(ListNode *head, char ch) {
    ListNode *p = head->next;
    while (p) {
        if (p->c == ch) {
            p->frequency++;
            return 1;
        }
        p = p->next;
    }
    return 0;
}

//����������ַ�����������ַ��������е��б�frequency+1�����򴴽��ýڵ�
ListNode *createListNode(ListNode *head, char *str) {
    int str_len = strlen(str);
    ListNode *p = head;
    //����ÿ���ַ�
    for (int i = 0; i < str_len; i++) {
        char ch = *(str + i);
        if (isInList(head, ch)) {
            //����ҵ��˾�Ĭ��frequency++,�������ֱ�ӽ�����һ���ַ����ж�
            continue;
        } else {
            //����β�巨��������
            while (p->next) {
                p = p->next;
                //������β�ڵ�
            }
            ListNode *newNode = createOneNode(ch);
            p->next = newNode;
        }
    }
    return head;
}

void ListTraverse(ListNode *head) {
    ListNode *p = head->next;
    while (p&&p->c!='\0') {
        /* ʾ�����:   'e' 8   */  //ע�⻻�з�Ҫ�������⴦��
        if (p->c == '\n') {
            printf("'\\n' %d %s\n", p->frequency,p->code);
        } else { printf("'%c' %d %s\n", p->c, p->frequency,p->code); }
        p = p->next;
    }
}

/*ͻȻ������ѡ������̫������ĿҪ����ΪҪ����ͬƵ�ʵĽڵ㰴������˳�����У�����д��ѡ��������������д��һ��ð������*/
void frequencyChoiceSort(ListNode *Head) {
    ListNode *q = Head->next;
    ListNode *prevq = Head;
    // ����ѡ�����򣬽���ָ��
    while (q) { // ��ֹ������q�������
        int max = q->frequency;
        ListNode *maxNode = q;
        ListNode *temp = q->next; //  ���ڱ���ʣ��ڵ�
        ListNode *prevtmp = q->next; // ���ڱ���temp��ǰһ���ڵ�
        ListNode *prevMax = q; // ���ڱ�����Ҫ�����Ľڵ��ǰһ���ڵ�

        while (temp) {
            if (temp->frequency > max) {
                max = temp->frequency;
                maxNode = temp;
                prevMax = prevtmp;
            }
            prevtmp = temp;
            temp = temp->next;
        }
        //���max�仯�˾ͽ����ڵ�
        if (maxNode != q) {
            prevq->next = maxNode;
            ListNode *temp2 = q->next;
            q->next = maxNode->next;
            maxNode->next = temp2;
            prevMax->next = q;

            //����ָ�뷢���˽���������pָ�벻��ָ��ԭ���Ľڵ�
            //�ָ�ָ��ָ��Ľڵ�
            q = maxNode;
        }
        prevq = q;
        q = q->next;
    }
}


void frequencyBubbleSort(ListNode *Head) {
    if (Head == NULL || Head->next == NULL) {
        return;
    }
    ListNode *tail = Head;
    int length = 0;
    //��ȡ������
    while (tail->next) {
        length += 1;
        tail = tail->next;
    }

    for (int i = 0; i < length; ++i) {
        ListNode *current = Head->next;
        ListNode *prev = Head;
        while (current && current->next) {
            if (current->frequency < current->next->frequency) {
                // �����ڵ�
                prev->next = current->next;
                current->next = current->next->next;
                prev->next->next = current;
            }
            prev = prev->next;
            current = prev->next;
        }
    }
}

// ѡ��Ƶ����С�������ڵ�
ListNode *selectMins(ListNode *head, ListNode *ignore) {
    ListNode *min1 = NULL;
    ListNode *min2 = NULL;
    ListNode *p = head->next;
    while (p) {
        if (p != ignore && (!p->parent)) {
            if (min1 == NULL || p->frequency < min1->frequency) {
                min2 = min1;
                min1 = p;
            } else if (min2 == NULL || p->frequency < min2->frequency) {
                min2 = p;
            }
        }
        p = p->next;
    }
    return min1;
}

HuffmanTree *buildHuffmanTree(ListNode *Head) {
    // ���������С,�����β�ڵ�
    ListNode *temp = Head->next;
    ListNode *tail = Head;
    int size = 0;
    while (temp) {
        size += 1;
        tail = temp;
        temp = temp->next;
    }

    // ������������
    for (int i = 1; i <= size - 1; ++i) {
        // ѡ��Ƶ����С�������ڵ�
        ListNode *min1 = selectMins(Head, NULL);
        ListNode *min2 = selectMins(Head, min1);

        // �����½ڵ㣬�ϲ������ڵ�
        ListNode *newNode = createOneNode('\0');
        newNode->frequency = min1->frequency + min2->frequency;
        newNode->left = min1;
        min1->parent=newNode;
        newNode->right = min2;
        min2->parent=newNode;

        // ���½ڵ��������
        tail->next = newNode;
        tail = newNode;

    }
    return tail; //���صľ���root�ڵ�
}

// �ݹ麯�������ɹ��������벢�洢���ڵ���
void generateHuffmanCodeHelper(ListNode *root, char *code, int depth) {
    if (root == NULL) {
        return;
    }

    // ������Ҷ�ӽڵ㣬������洢���ڵ���
    if (root->left == NULL && root->right == NULL) {
        root->code = (char *)malloc((depth + 1) * sizeof(char));
        strcpy(root->code, code);
        return;
    }

    // ������·������� 0
    code[depth] = '0';
    code[depth+1]='\0';
    generateHuffmanCodeHelper(root->left, code, depth + 1);

    // ������·������� 1
    code[depth] = '1';
    code[depth+1]='\0';
    generateHuffmanCodeHelper(root->right, code, depth + 1);
}

// ���ɹ���������ĺ���
void generateHuffmanCode(ListNode *root) {
    // �����ڴ����洢����
    char *code = (char *)malloc(256 * sizeof(char));
    // �Ӹ��ڵ㿪ʼ���ɱ���
    generateHuffmanCodeHelper(root, code, 0);
}
// �����Ȩ·������ R �ĵݹ麯��
int calculateWeightedPathLengthHelper(ListNode *root, int depth) {
    if (root == NULL) {
        return 0;
    }
    // ����Ҷ�ӽڵ㣬���������Ƶ�ʵĳ˻�
    if (root->left == NULL && root->right == NULL) {
        return depth * root->frequency;
    }
    // �ݹ�������������������Ĵ�Ȩ·�����ȣ������
    return calculateWeightedPathLengthHelper(root->left, depth + 1) + calculateWeightedPathLengthHelper(root->right, depth + 1);
}

// �����Ȩ·������ R �ĺ���
int calculateWeightedPathLength(ListNode *root) {
    // �Ӹ��ڵ㿪ʼ����
    return calculateWeightedPathLengthHelper(root, 0);
}
int main() {
    char *str;
    int i = 0;
    char ch;

    str = (char *) malloc(sizeof(char) * 2000);//����Ҫ����1000���ַ�
    memset(str, 0, 2000);


    //��ȡ�ַ���
    while ((ch = getchar()) != EOF) {
        *(str + i) = ch;
        i += 1;
    }
    //����һ��ͷ���
    ListNode *Head = createOneNode('0');
    createListNode(Head, str);
    frequencyBubbleSort(Head);
    ListNode *root= buildHuffmanTree(Head);
    generateHuffmanCode(root);
    ListTraverse(Head);
    printf("%d", calculateWeightedPathLength(root));
    system("pause");
    return 0;
}
//Your code end