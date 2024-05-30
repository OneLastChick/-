//
// Created by Npc on 2024/5/28.
//
#include <iostream>

using namespace std;

// �������ڵ���
class TreeNode {
public:
    int val;            // �ڵ�ֵ
    TreeNode* left;     // ���ӽڵ�ָ��
    TreeNode* right;    // ���ӽڵ�ָ��

    // ���캯������ʼ���ڵ�ֵ�������ӽڵ�ָ��
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// ���������������
class BST {
private:
    TreeNode* root; // ���ĸ��ڵ�

    // ����ڵ��˽�еݹ麯��
    TreeNode* insert(TreeNode* node, int val) {
        // �����ǰ�ڵ�Ϊ�գ��򴴽��½ڵ�
        if (!node) return new TreeNode(val);
        // ���ֵС�ڵ�ǰ�ڵ�ֵ���ݹ���뵽������
        if (val < node->val)
            node->left = insert(node->left, val);
        // ���ֵ���ڵ�ǰ�ڵ�ֵ���ݹ���뵽������
        else if (val > node->val)
            node->right = insert(node->right, val);
        // ���ص�ǰ�ڵ�
        return node;
    }

    // ���ҽڵ��˽�еݹ麯��
    TreeNode* search(TreeNode* node, int val) {
        // �����ǰ�ڵ�Ϊ�ջ�ڵ�ֵ���ڲ���ֵ���򷵻ص�ǰ�ڵ�
        if (!node || node->val == val) return node;
        // �������ֵС�ڵ�ǰ�ڵ�ֵ���ݹ����������
        if (val < node->val)
            return search(node->left, val);
        // �������ֵ���ڵ�ǰ�ڵ�ֵ���ݹ����������
        else
            return search(node->right, val);
    }

    // ɾ���ڵ��˽�еݹ麯��
    TreeNode* deleteNode(TreeNode* root, int key) {
        // �����Ϊ�գ����ؿ�
        if (!root) return root;
        // ���ɾ��ֵС�ڵ�ǰ�ڵ�ֵ���ݹ�ɾ���������Ľڵ�
        if (key < root->val)
            root->left = deleteNode(root->left, key);
        // ���ɾ��ֵ���ڵ�ǰ�ڵ�ֵ���ݹ�ɾ���������Ľڵ�
        else if (key > root->val)
            root->right = deleteNode(root->right, key);
        // �ҵ�Ҫɾ���Ľڵ�
        else {
            // ����ڵ�ֻ�����ӽڵ��û���ӽڵ�
            if (!root->left) {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }
            // ����ڵ�ֻ�����ӽڵ�
            else if (!root->right) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }
            // ����ڵ��������ӽڵ㣬�ҵ��������е���Сֵ�ڵ�
            TreeNode* temp = minValueNode(root->right);
            // ����Сֵ�ڵ��滻��ǰ�ڵ�ֵ
            root->val = temp->val;
            // �ݹ�ɾ���������е���Сֵ�ڵ�
            root->right = deleteNode(root->right, temp->val);
        }
        // ���ص�ǰ�ڵ�
        return root;
    }

    // ����������Сֵ�ڵ��˽�к���
    TreeNode* minValueNode(TreeNode* node) {
        TreeNode* current = node;
        // ѭ����������Ҷ�ӽڵ㣬����Сֵ�ڵ�
        while (current && current->left)
            current = current->left;
        return current;
    }

    // ���������ӡ���ڵ�ֵ��˽�еݹ麯��
    void inorder(TreeNode* root) {
        if (root) {
            inorder(root->left);      // �ݹ����������
            cout << root->val << " "; // ��ӡ��ǰ�ڵ�ֵ
            inorder(root->right);     // �ݹ����������
        }
    }

public:
    // ���캯������ʼ�����ڵ�Ϊ��
    BST() : root(nullptr) {}

    // ����ڵ�Ĺ�������
    void insert(int val) {
        root = insert(root, val);
    }

    // ���ҽڵ�Ĺ�������
    bool search(int val) {
        return search(root, val) != nullptr;
    }

    // ɾ���ڵ�Ĺ�������
    void deleteNode(int val) {
        root = deleteNode(root, val);
    }

    // ���������ӡ���ڵ�ֵ�Ĺ�������
    void inorder() {
        inorder(root);
        cout << endl;
    }
};

// ���Ժ���
int main() {
    BST bst;
    // ����ڵ�
    bst.insert(50);
    bst.insert(30);
    bst.insert(20);
    bst.insert(40);
    bst.insert(70);
    bst.insert(60);
    bst.insert(80);

    // ��ӡ����������
    cout << "Inorder traversal of the given tree: ";
    bst.inorder();

    // ɾ���ڵ㲢��ӡ����������
    cout << "\nDelete 20\n";
    bst.deleteNode(20);
    cout << "Inorder traversal of the modified tree: ";
    bst.inorder();

    cout << "\nDelete 30\n";
    bst.deleteNode(30);
    cout << "Inorder traversal of the modified tree: ";
    bst.inorder();

    cout << "\nDelete 50\n";
    bst.deleteNode(50);
    cout << "Inorder traversal of the modified tree: ";
    bst.inorder();

    // ���ҽڵ�
    cout << "\nSearch for 40: " << (bst.search(40) ? "Found" : "Not Found") << endl;

    return 0;
}

