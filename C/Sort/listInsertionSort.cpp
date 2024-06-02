//
// Created by Npc on 2024/6/2.
//
#include <stdio.h>
#include <stdlib.h>

// ��������ڵ�ṹ
struct ListNode {
    int val;
    struct ListNode *next;
};

// �����½ڵ�
struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*) malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

// ���ڵ���뵽������
void insertIntoSortedList(struct ListNode** head, struct ListNode* newNode) {
    struct ListNode* current;

    // �������Ϊ�ջ��½ڵ�Ӧ�ó�Ϊ�µ�ͷ�ڵ�
    if (*head == NULL || (*head)->val >= newNode->val) {
        newNode->next = *head;
        *head = newNode;
    } else {
        current = *head;
        // �ҵ��½ڵ�Ӧ�ò����λ��
        while (current->next != NULL && current->next->val < newNode->val) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

// ���������
void listInsertionSort(int arr[], int n) {
    struct ListNode* sortedList = NULL;

    // �������飬��Ԫ�ز��뵽������
    for (int i = 0; i < n; i++) {
        struct ListNode* newNode = createNode(arr[i]);
        insertIntoSortedList(&sortedList, newNode);
    }

    // ������õ��������ݸ��ƻ�����
    struct ListNode* current = sortedList;
    int index = 0;
    while (current != NULL) {
        arr[index++] = current->val;
        struct ListNode* temp = current;
        current = current->next;
        free(temp);  // �ͷŽڵ�
    }
}

// ������������ӡ����
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("����ǰ������:\n");
    printArray(arr, n);

    listInsertionSort(arr, n);

    printf("����������:\n");
    printArray(arr, n);

    system("pause");
    return 0;
}