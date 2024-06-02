//
// Created by Npc on 2024/6/2.
//
#include <stdio.h>
#include <stdlib.h>

// ����ڵ�ṹ��
struct Node {
    float data;
    struct Node* next;
};

// ����һ���µĽڵ�
struct Node* createNode(float value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// ����ڵ㵽������
void insertNode(struct Node** head, float value) {
    struct Node* newNode = createNode(value);
    if (*head == NULL || (*head)->data >= value) {
        newNode->next = *head;
        *head = newNode;
    } else {
        struct Node* current = *head;
        while (current->next != NULL && current->next->data < value) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

// ��ӡ����
void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%f ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Ͱ������
void bucketSort(float array[], int n) {
    // 1. ����Ͱ���������飩
    struct Node** buckets = (struct Node**)malloc(n * sizeof(struct Node*));
    for (int i = 0; i < n; i++) {
        buckets[i] = NULL;
    }

    // 2. ���������е�Ԫ�ص�����Ͱ
    for (int i = 0; i < n; i++) {
        int bucketIndex = (int)(n * array[i]);
        insertNode(&buckets[bucketIndex], array[i]);
    }

    // 3. �ϲ�����Ͱ�е�Ԫ��
    int index = 0;
    for (int i = 0; i < n; i++) {
        struct Node* current = buckets[i];
        while (current != NULL) {
            array[index++] = current->data;
            current = current->next;
        }
    }

    // 4. �ͷ�Ͱ�ڴ�
    for (int i = 0; i < n; i++) {
        struct Node* current = buckets[i];
        while (current != NULL) {
            struct Node* temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(buckets);
}

// ��ӡ����
void printArray(float array[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%f ", array[i]);
    }
    printf("\n");
}

int main() {
    float array[] = {0.78, 0.17, 0.39, 0.26, 0.72, 0.94, 0.21, 0.12, 0.23, 0.68};
    int size = sizeof(array) / sizeof(array[0]);

    printf("����ǰ������: \n");
    printArray(array, size);

    bucketSort(array, size);

    printf("����������: \n");
    printArray(array, size);
    system("pause");
    return 0;
}