//
// Created by Npc on 2024/4/21.
//

#include "binaryTree.h"
#include "stdlib.h"
#include "iostream"
int main()
{
    Tree tree;
    tree.root=NULL;//����һ������
    int n;
    std::cout<<"������Ҫ����������"<<std::endl;
    scanf("%d",&n);

    //����n����,�����������
    for(int i=0;i<n;i++)
    {
        int temp;
        std::cout<<">";
        scanf("%d",&temp);
        insert(&tree,temp);
    }


    printf("\n");
    std::cout<<"����������:"<<std::endl;
    inorder(tree.root); //�������
    printf("\n");
    std::cout<<"����������:"<<std::endl;
    preorder(tree.root);
    printf("\n");
    std::cout<<"����������:"<<std::endl;
    postorder(tree.root);
    system("pause");
    return 0;
}