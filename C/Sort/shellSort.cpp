//
// Created by Npc on 2024/5/29.
//
#include <stdio.h>
#include "stdlib.h"
// ϣ�������㷨
void shellSort(int arr[], int n) {
    // ��ʼ����Ϊ���鳤�ȵ�һ�룬����ÿһ�ֽ���������
    for (int gap = n / 2; gap > 0; gap /= 2) {
        // �ӵ�ǰ����λ�ÿ�ʼ���Բ���������в�������
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
            // �������򣬶Ե�ǰ�����������
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

// ������������ӡ����
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// ������
int main() {
    int arr[] = {12, 34, 54, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("����ǰ������:\n");
    printArray(arr, n);

    shellSort(arr, n);

    printf("����������:\n");
    printArray(arr, n);
    system("pause");
    return 0;
}