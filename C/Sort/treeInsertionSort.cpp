//
// Created by Npc on 2024/6/2.
//
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// ��ʼ��������
void initializeTree(int tree[], int data[], int n) {
    // �����ݷ���Ҷ�ӽ��
    for (int i = 0; i < n; i++) {
        tree[n + i] = data[i];
    }

    // ����������
    for (int i = n - 1; i > 0; i--) {
        tree[i] = (tree[2 * i] < tree[2 * i + 1]) ? tree[2 * i] : tree[2 * i + 1];
    }
}

// ����������
void adjustTree(int tree[], int n, int index) {
    // ��Ҷ�ӽ����Ϊ�����
    tree[index] = INT_MAX;

    // ���ϵ������ṹ
    while (index > 1) {
        int sibling = (index % 2) ? index - 1 : index + 1;
        int parent = index / 2;
        tree[parent] = (tree[index] < tree[sibling]) ? tree[index] : tree[sibling];
        index = parent;
    }
}

// ����ѡ������
void treeSelectionSort(int data[], int n) {
    // ʹ��2 * n��С��������ģ����ȫ������
    int size = 2 * n;
    int* tree = (int *)malloc(size * sizeof(int));
    if (!tree) {
        printf("Memory allocation error\n");
        return;
    }

    // ��ʼ��������
    initializeTree(tree, data, n);

    // �ظ��ҵ���Сֵ��������
    for (int i = 0; i < n; i++) {
        // ���ڵ��ǵ�ǰ��Сֵ
        data[i] = tree[1];

        // �ҵ���Сֵ��Ҷ�ӽڵ��λ�ò�������
        for (int j = n; j < size; j++) {
            if (tree[j] == data[i]) {
                adjustTree(tree, n, j);
                break;
            }
        }
    }

    // �ͷ��ڴ�
    free(tree);
}

// ��ӡ����
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("����ǰ������:\n");
    printArray(arr, n);

    treeSelectionSort(arr, n);

    printf("����������:\n");
    printArray(arr, n);

    return 0;
}
