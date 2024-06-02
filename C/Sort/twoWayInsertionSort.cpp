#include <stdio.h>
#include <stdlib.h>

// ��ӡ����
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// ��·��������ʵ��
void twoWayInsertionSort(int arr[], int size) {
    // ��ʱ�������洢������
    int *temp = (int *)malloc(size * sizeof(int));
    int start = 0, end = 0; // ��ʱ�������ʼ�ͽ�������

    temp[0] = arr[0]; // ��ʼ����һ��Ԫ��
    for (int i = 1; i < size; i++) {
        if (arr[i] < temp[start]) {
            // ���뵽temp����ʼλ��ǰ
            start = (start - 1 + size) % size;
            temp[start] = arr[i];
        } else if (arr[i] > temp[end]) {
            // ���뵽temp�Ľ���λ�ú�
            end = (end + 1) % size;
            temp[end] = arr[i];
        } else {
            // ���뵽temp���м�λ��
            int j = end;
            // �����ƶ�Ԫ�����ڳ��ռ�
            while (arr[i] < temp[j]) {
                temp[(j + 1) % size] = temp[j];
                j = (j - 1 + size) % size;
            }
            temp[(j + 1) % size] = arr[i];
            end = (end + 1) % size;
        }
    }

    // ��������Ԫ�ؿ�����ԭ����
    for (int i = 0; i < size; i++) {
        arr[i] = temp[(start + i) % size];
    }

    // �ͷ���ʱ�����ڴ�
    free(temp);
}

int main() {
    int arr[] = {22, 11, 99, 88, 9, 7, 42};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Original array:\n");
    printArray(arr, size);

    twoWayInsertionSort(arr, size);

    printf("Sorted array:\n");
    printArray(arr, size);

    system("pause");
    return 0;
}
