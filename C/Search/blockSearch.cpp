#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int key;  // ������ֵ
    int start;  // �����ʼ����
    int end;  // ��Ľ�������
} IndexBlock;

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int blockSearch(int arr[], IndexBlock indexTable[], int n, int blockSize, int key) {
    int blockIndex = -1;

    // �ҵ����ܵĿ�
    for (int i = 0; i < blockSize; i++) {
        if (key <= indexTable[i].key) {
            blockIndex = i;
            break;
        }
    }

    // ���û���ҵ����ʵĿ飬�򷵻�-1
    if (blockIndex == -1) {
        return -1;
    }

    // �����Բ��ҿ��е�Ԫ��
    for (int i = indexTable[blockIndex].start; i <= indexTable[blockIndex].end; i++) {
        if (arr[i] == key) {
            return i;  // �ҵ�Ԫ�أ�����������
        }
    }

    return -1;  // δ�ҵ�Ԫ��
}

int main() {
    int arr[] = {3, 7, 15, 20, 25, 29, 35, 50, 55, 65, 75, 80, 85, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    int blockSize = 4;  // �������

    // ����������
    IndexBlock indexTable[blockSize];
    for (int i = 0; i < blockSize; i++) {
        indexTable[i].start = i * (n / blockSize);
        indexTable[i].end = (i == blockSize - 1) ? (n - 1) : ((i + 1) * (n / blockSize) - 1);
        indexTable[i].key = arr[indexTable[i].end];
    }

    // ���Ҽ�ֵ
    int key = 50;
    int result = blockSearch(arr, indexTable, n, blockSize, key);
    if (result != -1) {
        printf("Element %d found at index %d\n", key, result);
    } else {
        printf("Element %d not found\n", key);
    }
    system("pause");
    return 0;
}
