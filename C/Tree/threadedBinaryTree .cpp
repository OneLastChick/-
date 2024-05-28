//
// Created by Npc on 2024/5/8.
//

#include "threadedBinaryTree .h"
// ���Գ���
int main() {
    TBTNode* root = createNode(1);
    root->lchild = createNode(2);
    root->rchild = createNode(3);
    root->lchild->lchild = createNode(4);
    root->lchild->rchild = createNode(5);
    root->rchild->lchild = createNode(6);
    root->rchild->rchild = createNode(7);

    // ����������
    TBTNode* pre = NULL;
    InThread(root, pre);
    // �����������������
    printf("Inorder Traversal: ");
    InOrder(root);
    printf("\n");

    // ����������
    pre = NULL;
    PreThread(root, pre);
    // �����������������
    printf("Preorder Traversal: ");
    PreOrder(root);
    printf("\n");

    // ����������
    pre = NULL;
    PostThread(root, pre);
    // �����������������
    printf("Postorder Traversal: ");
    PostOrder(root);
    printf("\n");
    system("pause");
    return 0;
}