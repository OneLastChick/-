//
// Created by Npc on 2024/6/1.
//
#include <stdio.h>
#include "stdlib.h"
// ������������ֵ�ĺ궨��
#define SWAP(x, y, T) do { T SWAP = x; x = y; y = SWAP; } while (0)

// ����������ͨ��ѡ��һ����׼�㣬���������
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // ѡ�����һ��Ԫ����Ϊ��׼��
    int i = low - 1; // i ��С�ڻ�׼ֵ������������һ��Ԫ�ص�����

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            SWAP(arr[i], arr[j], int); // ��С�ڻ�׼ֵ��Ԫ���Ƶ�ǰ��
        }
    }
    SWAP(arr[i + 1], arr[high], int); // ����׼ֵ�ŵ���ȷ��λ��
    return i + 1; // ���ػ�׼ֵ������
}

// ����������
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high); // ��������

        quickSort(arr, low, pi - 1); // �ݹ������׼ֵ��ߵ�������
        quickSort(arr, pi + 1, high); // �ݹ������׼ֵ�ұߵ�������
    }
}

// ��ӡ���麯��
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("����ǰ������:\n");
    printArray(arr, n);

    quickSort(arr, 0, n - 1);

    printf("����������:\n");
    printArray(arr, n);
    system("dir");
    system("pause");
    return 0;
}