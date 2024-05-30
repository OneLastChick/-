#include <iostream>

using namespace std;

// �������ڵ���
class TreeNode {
public:
    int val;            // �ڵ�ֵ
    TreeNode* left;     // ���ӽڵ�ָ��
    TreeNode* right;    // ���ӽڵ�ָ��
    int height;         // �ڵ�߶�

    // ���캯������ʼ���ڵ�ֵ�������ӽڵ�ָ��
    TreeNode(int x) : val(x), left(nullptr), right(nullptr), height(1) {}
};

// ����AVL����
class AVLTree {
private:
    TreeNode* root; // ���ĸ��ڵ�

    // ��ȡ�ڵ�߶�
    int height(TreeNode* node) {
        return node ? node->height : 0;
    }

    // ��ȡƽ������
    int getBalance(TreeNode* node) {
        return node ? height(node->left) - height(node->right) : 0;
    }

    // ����ת
    TreeNode* rightRotate(TreeNode* y) {
        TreeNode* x = y->left;
        TreeNode* T2 = x->right;

        // ������ת
        x->right = y;
        y->left = T2;

        // ���¸߶�
        y->height = max(height(y->left), height(y->right)) + 1;
        x->height = max(height(x->left), height(x->right)) + 1;

        // �����µĸ��ڵ�
        return x;
    }

    // ����ת
    TreeNode* leftRotate(TreeNode* x) {
        TreeNode* y = x->right;
        TreeNode* T2 = y->left;

        // ������ת
        y->left = x;
        x->right = T2;

        // ���¸߶�
        x->height = max(height(x->left), height(x->right)) + 1;
        y->height = max(height(y->left), height(y->right)) + 1;

        // �����µĸ��ڵ�
        return y;
    }

    // ����ڵ��˽�еݹ麯��
    TreeNode* insert(TreeNode* node, int val) {
        // 1. ִ����ͨ��BST�������
        if (!node) return new TreeNode(val);
        if (val < node->val)
            node->left = insert(node->left, val);
        else if (val > node->val)
            node->right = insert(node->right, val);
        else
            return node;

        // 2. ���½ڵ�ĸ߶�
        node->height = 1 + max(height(node->left), height(node->right));

        // 3. ��ȡ�ڵ��ƽ������
        int balance = getBalance(node);

        // 4. ����Ƿ���Ҫ������ת�Ա���AVL����ƽ��

        // �������
        if (balance > 1 && val < node->left->val)
            return rightRotate(node);

        // �������
        if (balance < -1 && val > node->right->val)
            return leftRotate(node);

        // �������
        if (balance > 1 && val > node->left->val) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        // �������
        if (balance < -1 && val < node->right->val) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    // ���ҽڵ��˽�еݹ麯��
    TreeNode* search(TreeNode* node, int val) {
        if (!node || node->val == val)
            return node;
        if (val < node->val)
            return search(node->left, val);
        else
            return search(node->right, val);
    }

    // ����������Сֵ�ڵ��˽�к���
    TreeNode* minValueNode(TreeNode* node) {
        TreeNode* current = node;
        while (current->left)
            current = current->left;
        return current;
    }

    // ɾ���ڵ��˽�еݹ麯��
    TreeNode* deleteNode(TreeNode* root, int key) {
        // 1. ִ�б�׼��BSTɾ������
        if (!root)
            return root;
        if (key < root->val)
            root->left = deleteNode(root->left, key);
        else if (key > root->val)
            root->right = deleteNode(root->right, key);
        else {
            if (!root->left) {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            } else if (!root->right) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }

            TreeNode* temp = minValueNode(root->right);
            root->val = temp->val;
            root->right = deleteNode(root->right, temp->val);
        }

        // 2. �������ֻ��һ���ڵ㣬ֱ�ӷ���
        if (!root)
            return root;

        // 3. ���½ڵ�ĸ߶�
        root->height = 1 + max(height(root->left), height(root->right));

        // 4. ��ȡ�ڵ��ƽ������
        int balance = getBalance(root);

        // 5. ����Ƿ���Ҫ������ת�Ա���AVL����ƽ��

        // �������
        if (balance > 1 && getBalance(root->left) >= 0)
            return rightRotate(root);

        // �������
        if (balance > 1 && getBalance(root->left) < 0) {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }

        // �������
        if (balance < -1 && getBalance(root->right) <= 0)
            return leftRotate(root);

        // �������
        if (balance < -1 && getBalance(root->right) > 0) {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }

        return root;
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
    AVLTree() : root(nullptr) {}

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
    AVLTree avl;

    // ����ڵ�
    avl.insert(50);
    avl.insert(30);
    avl.insert(20);
    avl.insert(40);
    avl.insert(70);
    avl.insert(60);
    avl.insert(80);

    // ��ӡ����������
    cout << "Inorder traversal of the given tree: ";
    avl.inorder();

    // ɾ���ڵ㲢��ӡ����������
    cout << "\nDelete 20\n";
    avl.deleteNode(20);
    cout << "Inorder traversal of the modified tree: ";
    avl.inorder();

    cout << "\nDelete 30\n";
    avl.deleteNode(30);
    cout << "Inorder traversal of the modified tree: ";
    avl.inorder();

    cout << "\nDelete 50\n";
    avl.deleteNode(50);
    cout << "Inorder traversal of the modified tree: ";
    avl.inorder();

    // ���ҽڵ�
    cout << "\nSearch for 40: " << (avl.search(40) ? "Found" : "Not Found") << endl;
    system("pause");
    return 0;
}
