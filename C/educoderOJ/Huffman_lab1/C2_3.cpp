//
// Created by Npc on 2024/4/23.
//

//Your code begin.
//ʾ�������ο�����Ҳ���������޸����
#include<stdio.h>
#include<stdlib.h>
#include "string.h"
/*�������񣺱�д�������ͽ������������һ�صõ��Ĺ���������������ı����б���ͽ��롣

���֪ʶ
Ϊ����ɱ�����������Ҫ���գ�
1.���Ҷ������Ľ��
2.�ж�Ҷ�ӽ��

���Ҫ��
������ʾ�����Ҳ�༭��������룬�������ı����б���ͽ��룬������������ı����������ı��Լ�������ı��ĳ��ȡ�

����˵��
ƽ̨������д�Ĵ�����в��ԣ�

�������룺

Data structure experiment
HuffmanTree
metro line
Ԥ�������

1111000110001011001111111010010101000111110001100001011001111101111110000011001010111100111010100011110000001100011101111011001011010100001001011011011100100111000101000011011110110101111010110
Data structure experiment
HuffmanTree
metro line
193*/
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

void HuffmanCode2Str(ListNode*root,char *HuffmanCode,char *decode_str)
{
    int i=0;
    ListNode *p=root;
    while(*(HuffmanCode+i)!='\0')
    {
        if(*(HuffmanCode+i)=='0')
        {
            if(p->left==NULL)
            {
                //�Ѿ����ﾡͷ�ˣ���ȡstr
                strncat(decode_str,&(p->c),1);
                //ͬʱ��ͷ��ʼ����
                p=root;
                /*�������Ҫֱ�ӽ�����һ�Σ�����ͻᵼ������һ������û����ȡ*/
                continue;
            }
            else
            {
                //��������ڵ�
                p=p->left;
            }
        }
        else
        {
            if(p->right==NULL)
            {
                strncat(decode_str,&(p->c),1);
                p=root;
                continue;
            }
            else
            {
                p=p->right;
            }
        }
        i+=1;
    }
}


void printHuffmanCode(char *str,char *HuffmanCode,ListNode *Head)
{
    int i=0;
    while(*(str+i)!='\0')
    {
        ListNode *temp=Head->next;

        while(temp->c!=*(str+i))
        {
            temp=temp->next;
        }
        strcat(HuffmanCode,temp->code);
        i++;
    }
}
int main() {
    char *str;
    int i = 0;
    char ch;

    str = (char *) malloc(sizeof(char) * 2000);//����Ҫ����1000���ַ�
    memset(str, 0, 2000);
//    int length=sizeof(str)/sizeof (char );

    //��ȡ�ַ���
    while ((ch = getchar()) != EOF) {
        *(str + i) = ch;
        i += 1;
    }
    //����һ��ͷ���
    ListNode *Head = createOneNode('0');
    //�����ڵ�����
    createListNode(Head, str);
    //����Ƶ��ð������
    frequencyBubbleSort(Head);
    //������������
    ListNode *root= buildHuffmanTree(Head);
    //���ɹ���������
    generateHuffmanCode(root);

    //�����huffmancode�洢�Ŀռ�һ��Ҫ���󣬲�Ȼ���Լ��еıȽϴ�ᵼ�����
    char *HuffmanCode;
    HuffmanCode=(char *) malloc(sizeof(char)*10000);
    memset(HuffmanCode, 0, 10000);

    //���ù����������ַ���תΪ����������
    printHuffmanCode(str,HuffmanCode,Head);
    printf("%s\n",HuffmanCode);

    //���������������ԭ
    char *decode_str;
    decode_str=(char *) malloc(sizeof (char )*2000);
    memset(decode_str, 0, 2000);
    HuffmanCode2Str(root,HuffmanCode,decode_str);
    printf("%s\n",decode_str);

    printf("%d",calculateWeightedPathLength(root));
    system("pause");
    return 0;
}
//Your code end