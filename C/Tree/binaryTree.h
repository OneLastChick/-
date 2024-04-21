//
// Created by Npc on 2024/4/21.
//

#ifndef C_BINARYTREE_H
#define C_BINARYTREE_H

#include "stdio.h"
#include "stdlib.h"
//�������Ľڵ����
/*a)���Ԫ�أ�data�������洢���ݣ��������int��char�Ȼ��������ͣ�ͬʱҲ������struct����Щ���ӵĸ����������͡�

b)���ӽ�㣬leftָ�룬��������ָ��ǰ������һ�����߽�㣬������һ��ָ�롣

c)�Һ��ӽ�㣬rightָ�룬��������ָ��ǰ������һ����ұ߽�㣬������һ��ָ�롣

d)����㣨��ѡ����parentָ�룬����ָ��ǰ����ǰһ����㣬��Ƹ��׽�㣬�䲻���ڱ�������ƣ�ʡ�Ե����Դ��Ž�ʡ�ڴ��Ч������ʹ������Ը�������ж����������������в�ʹ�ø��ڵ㡣*/

//���Ľڵ�
typedef struct node{
    int data;
    struct node* left;
    struct node* right;
}Node;

//����
typedef struct {
    Node* root;
}Tree;

//���Ĵ���
void insert(Tree* tree,int value)
{
    //����һ���ڵ㣬������ָ��ȫ��ָ���,����Ϊvalue
    //�����ĳ�ʼ��
    Node *node=(Node*)malloc(sizeof (Node));
    node->data=value;
    node->left=NULL;
    node->right=NULL;

    //�ж����ǲ��ǿ���������ǣ�ֱ��������ָ����һ���ڵ�
    if(tree->root==NULL)
    {
        tree->root=node;
    }else//���ǿ���
    {
        Node *temp=tree->root;
        while(temp!=NULL)
        {
            //С�ھͽ������
            if(value<temp->data) {
                if (temp->left == NULL) {
                    temp->left = node;
                    return;
                } else {//�������������Ѱ
                    temp = temp->left;
                }
            }
            else{
                if(temp->right==NULL)
                {
                    temp->right=node;
                    return;
                }else{
                    temp=temp->right;
                }
            }
        }
    }
    return;


}


//������
/*Method-1*/
//in-order traversal
void inorder(Node *node)
{
    if(node!=NULL)
    {
        inorder(node->left);
        printf("%d ",node->data);
        inorder(node->right);
    }
}
/*Method-2*/
//preorder traversal
void preorder(Node* node)
{
    if(node!=NULL)
    {;
        printf("%d ",node->data);
        preorder(node->left);
        preorder(node->right);
    }
}
/*Method-3*/
//postorder traversal
void postorder(Node* node)
{
    if(node!=NULL)
    {;
        postorder(node->left);
        postorder(node->right);
        printf("%d ",node->data);
    }
}
#endif //C_BINARYTREE_H
