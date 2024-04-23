//
// Created by Npc on 2024/4/22.
//

#include "huffmanTree.h"


/*����HuffmanTree�ĺ���*/
int main()
{
    int weights[] = {5, 9, 12, 13, 16, 45}; // ����Ȩ��
    int n = sizeof(weights) / sizeof(weights[0]); // ������

    HuffmanTree HT; // HuffmanTree ����
    CreateHuffmanTree(&HT, weights, n); // ���� Huffman ��

    // ������Խ��
    printf("Huffman Tree Constructed:\n");
    printf("Weight | Parent | Left | Right\n");
    for (int i = 1; i <= 2 * n - 1; i++) {
        printf("%6d | %6d | %4d | %5d\n", HT[i].weight, HT[i].parent, HT[i].left, HT[i].right);
    }
    system("pause");
/*  char ch;
  while((ch=getchar())!=EOF)
  {
      printf("%c",ch);
  }
    char *string;
    string= (char*)malloc(sizeof(char)*1000 );
    scanf("%s",string);
    printf("EEE%s",string);
    system("pause");*/

}