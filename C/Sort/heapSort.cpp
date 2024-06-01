//
// Created by Npc on 2024/6/1.
//
#include <stdio.h>
#include "stdlib.h"
// ������������
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// �ѵ���(����)����
void shiftdown(int arr[], int n, int i) {
    int largest = i;     // ����ǰ�ڵ����Ϊ���ֵ
    int left = 2 * i + 1; // ���ӽڵ��±�
    int right = 2 * i + 2; // ���ӽڵ��±�

    // ������ӽڵ�����Ҵ��ڵ�ǰ�ڵ㣬�������ֵ�±�
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // ������ӽڵ�����Ҵ��ڵ�ǰ�ڵ㣬�������ֵ�±�
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // ������ֵ���ǵ�ǰ�ڵ㣬�򽻻����ݹ����
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        shiftdown(arr, n, largest);
    }
}

// ������������
void heapSort(int arr[], int n) {
    // �����󶥶�(��ÿ�����ڵ��������)
    for (int i = n / 2 - 1; i >= 0; i--)
        shiftdown(arr, n, i);

    // һ����ȡ��Ԫ�ز����¹�������
    for (int i = n - 1; i >= 0; i--) {
        // ����ǰ�Ѷ������ֵ���Ƶ�����ĩβ
        swap(&arr[0], &arr[i]);

        // �Լ�����һ��Ԫ�صĶѼ������жѵ���
        shiftdown(arr, i, 0);
    }
}

// ��ӡ����
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// ������
int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("����ǰ������: \n");
    printArray(arr, n);

    heapSort(arr, n);

    printf("����������: \n");
    printArray(arr, n);
    system("pause");
    return 0;
}