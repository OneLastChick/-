//
// Created by Npc on 2024/6/2.
//
#include <stdio.h>
#include <stdlib.h>

// ����������
void countingSort(int *array, int size, int range) {
    // ��������ʼ����������
    int *count = (int *)calloc(range + 1, sizeof(int));
    int *output = (int *)malloc(size * sizeof(int));

    // ͳ��ÿ��Ԫ�صĳ��ִ���
    for (int i = 0; i < size; i++) {
        count[array[i]]++;
    }

    // �ۼƼ�������
    for (int i = 1; i <= range; i++) {
        count[i] += count[i - 1];
    }

    // ���ݼ���������ֵ���ۻ��������������
    for (int i = size - 1; i >= 0; i--) {
        output[count[array[i]] - 1] = array[i];
        count[array[i]]--;
    }

    // �������Ľ�����ƻ�ԭ����
    for (int i = 0; i < size; i++) {
        array[i] = output[i];
    }

    // �ͷŶ�̬�ڴ�
    free(count);
    free(output);
}

void printArray(int *array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    int array[] = {4, 2, 2, 8, 3, 3, 1};
    int size = sizeof(array) / sizeof(array[0]);
    int max_element = 8; // ����Ԫ�ص�ֵ��Χ��0��max_element

    printf("����ǰ������: \n");
    printArray(array, size);

    countingSort(array, size, max_element);

    printf("����������: \n");
    printArray(array, size);
    system("pause");
    return 0;
}