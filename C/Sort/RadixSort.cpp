//
// Created by Npc on 2024/6/2.
//
#include <stdio.h>
#include <stdlib.h>

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

// �������ָ��λ�ã�λ�����м�������
void countSort(int arr[], int n, int exp) {
    int *output = (int *)malloc(n * sizeof(int)); // �������
    int i, count[10] = {0};

    // ����ÿ��λ���ֳ��ֵĴ���
    for (i = 0; i < n; i++) {
        int index = (arr[i] / exp) % 10;
        count[index]++;
    }

    // �ۻ�����
    for (i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // ���ݼ������鹹���������
    for (i = n - 1; i >= 0; i--) {
        int index = (arr[i] / exp) % 10;
        output[count[index] - 1] = arr[i];
        count[index]--;
    }

    // �������Ľ�����ƻ�ԭ����
    for (i = 0; i < n; i++) {
        arr[i] = output[i];
    }

    free(output);
}

// ����������
void radixSort(int arr[], int n) {
    int max = getMax(arr, n);  // �õ������е������

    // �������Чλ�������Чλ���������������
    for (int exp = 1; max / exp > 0; exp *= 10) {
        countSort(arr, n, exp);
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

    return 0;
}