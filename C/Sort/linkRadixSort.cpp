//
// Created by Npc on 2024/6/2.
//
#include <stdio.h>
#include <stdlib.h>

// ����ڵ�ṹ��
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// ����һ���½ڵ�
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// ����׷�ӽڵ�
void appendNode(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// ��Ͱ��������ݺϲ���������
void collectBuckets(Node** buckets, int arr[], int n) {
    int i, j;
    int index = 0;
    for (i = 0; i < 10; ++i) {
        Node* current = buckets[i];
        while (current != NULL) {
            arr[index++] = current->data;
            Node* temp = current;
            current = current->next;
            free(temp);
        }
        buckets[i] = NULL;
    }
}

// ��ȡ����������Ԫ��
int getMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// ��������������ʽ��������
void radixSort(int arr[], int n) {
    // ����Ͱ��������
    Node* buckets[10] = {NULL};

    // �ҵ����ֵ�Ծ������λ��
    int max = getMax(arr, n);
    int exp;

    // ��λ������ռ�
    for (exp = 1; max / exp > 0; exp *= 10) {
        // ������Ԫ�ط��䵽Ͱ��
        for (int i = 0; i < n; ++i) {
            int bucketIndex = (arr[i] / exp) % 10;
            appendNode(&buckets[bucketIndex], arr[i]);
        }

        // �ռ�Ͱ�е�Ԫ�ص�������
        collectBuckets(buckets, arr, n);
    }
}

// ��ӡ����
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("����ǰ������: \n");
    printArray(arr, n);

    radixSort(arr, n);

    printf("����������: \n");
    printArray(arr, n);
    system("pause");
    return 0;
}