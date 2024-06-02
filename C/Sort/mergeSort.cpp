//
// Created by Npc on 2024/6/2.
//
#include <stdio.h>
#include "stdlib.h"
// �ϲ������������������
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // ������ʱ����
    int L[n1], R[n2];

    // �����ݸ��Ƶ���ʱ����
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // �ϲ���ʱ���鵽ԭʼ����
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // ����ʣ��Ԫ�أ�����У�
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// �鲢������
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        // �ҵ��е�
        int mid = left + (right - left) / 2;

        // ����벿�ֽ�������
        mergeSort(arr, left, mid);
        // ���Ұ벿�ֽ�������
        mergeSort(arr, mid + 1, right);

        // �ϲ�������Ĳ���
        merge(arr, left, mid, right);
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
    int arr[] = {12, 11, 13, 5, 6, 7};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    printf("����ǰ������:\n");
    printArray(arr, arr_size);

    mergeSort(arr, 0, arr_size - 1);

    printf("����������:\n");
    printArray(arr, arr_size);
    system("pause");
    return 0;
}