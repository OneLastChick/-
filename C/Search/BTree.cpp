#include <iostream>
#include <vector>

using namespace std;

// B���Ľڵ���
class BTreeNode {
public:
    vector<int> keys;       // �洢��ֵ
    vector<BTreeNode*> children;  // �洢�ӽڵ�ָ��
    int t;                  // ��С����
    bool leaf;              // �Ƿ�ΪҶ�ӽڵ�

    // ���캯��
    BTreeNode(int _t, bool _leaf) : t(_t), leaf(_leaf) {}

    // �����ֵ�������ڵ�
    void insertNonFull(int k);

    // �����ӽڵ�
    void splitChild(int i, BTreeNode* y);

    // ���Ҽ�ֵ
    BTreeNode* search(int k);

    // ��ӡB��
    void traverse();

    // ��ȡ����Ϊidx��ǰ��
    int getPred(int idx);

    // ��ȡ����Ϊidx�ĺ��
    int getSucc(int idx);

    // ���ֵܽڵ���ֵ
    void fill(int idx);

    // ��ǰһ���ֵܽڵ���ֵ
    void borrowFromPrev(int idx);

    // �Ӻ�һ���ֵܽڵ���ֵ
    void borrowFromNext(int idx);

    // �ϲ��ڵ�
    void merge(int idx);

    // ɾ����ֵ
    void remove(int k);

    // ɾ����Ҷ�ӽڵ�ļ�ֵ
    void removeFromNonLeaf(int idx);

    // ɾ��Ҷ�ӽڵ�ļ�ֵ
    void removeFromLeaf(int idx);

    // ���Ҽ�ֵ��λ��
    int findKey(int k);
};

// B����
class BTree {
public:
    BTreeNode* root; // ���ĸ��ڵ�
    int t;           // ��С����

    // ���캯��
    BTree(int _t) : t(_t), root(nullptr) {}

    // �����ֵ
    void insert(int k);

    // ���Ҽ�ֵ
    BTreeNode* search(int k);

    // ɾ����ֵ
    void remove(int k);

    // ��ӡB��
    void traverse() {
        if (root) root->traverse();
    }
};

// BTreeNode���Ա����ʵ��

// �������B��
void BTreeNode::traverse() {
    int i;
    for (i = 0; i < keys.size(); i++) {
        if (!leaf) {
            children[i]->traverse();  // �ݹ��������
        }
        cout << " " << keys[i];        // ��ӡ��ֵ
    }
    if (!leaf) {
        children[i]->traverse();      // �ݹ�������һ������
    }
}

// ��B����������ֵ
BTreeNode* BTreeNode::search(int k) {
    int i = 0;
    while (i < keys.size() && k > keys[i]) {
        i++;
    }
    if (i < keys.size() && keys[i] == k) {
        return this;                  // �ҵ���ֵ�����ص�ǰ�ڵ�
    }
    if (leaf) {
        return nullptr;               // �����Ҷ�ӽڵ���δ�ҵ������ؿ�
    }
    return children[i]->search(k);    // �ݹ���������
}

// ��B���в����ֵ
void BTree::insert(int k) {
    if (!root) {
        root = new BTreeNode(t, true);  // �����Ϊ�գ��������ڵ�
        root->keys.push_back(k);        // �����ֵ
    } else {
        if (root->keys.size() == 2 * t - 1) {
            BTreeNode* s = new BTreeNode(t, false);  // ������ڵ����ˣ����Ѹ��ڵ�
            s->children.push_back(root);             // �¸��ڵ�ָ��ɸ��ڵ�
            s->splitChild(0, root);                  // ���Ѿɸ��ڵ�
            int i = 0;
            if (s->keys[0] < k) {
                i++;
            }
            s->children[i]->insertNonFull(k);        // �����ֵ���ʵ�����
            root = s;                                // ���¸��ڵ�
        } else {
            root->insertNonFull(k);                  // ���ڵ�δ����ֱ�Ӳ���
        }
    }
}

// �����ֵ�������ڵ�
void BTreeNode::insertNonFull(int k) {
    int i = keys.size() - 1;
    if (leaf) {
        keys.push_back(0);              // Ϊ�¼�ֵ�ڳ��ռ�
        while (i >= 0 && keys[i] > k) { // �ҵ�����λ��
            keys[i + 1] = keys[i];
            i--;
        }
        keys[i + 1] = k;                // �����ֵ
    } else {
        while (i >= 0 && keys[i] > k) {
            i--;
        }
        if (children[i + 1]->keys.size() == 2 * t - 1) {
            splitChild(i + 1, children[i + 1]);  // �ӽڵ����ˣ������ӽڵ�
            if (keys[i + 1] < k) {
                i++;
            }
        }
        children[i + 1]->insertNonFull(k);  // �ݹ�����ֵ���ӽڵ�
    }
}

// �����ӽڵ�
void BTreeNode::splitChild(int i, BTreeNode* y) {
    BTreeNode* z = new BTreeNode(y->t, y->leaf);  // �����½ڵ�
    for (int j = 0; j < t - 1; j++) {
        z->keys.push_back(y->keys[j + t]);       // ������ֵ���½ڵ�
    }
    if (!y->leaf) {
        for (int j = 0; j < t; j++) {
            z->children.push_back(y->children[j + t]);  // �����ӽڵ�ָ�뵽�½ڵ�
        }
    }
    y->keys.resize(t - 1);  // ����ԭ�ڵ�ļ�ֵ��
    y->children.resize(t);  // ����ԭ�ڵ���ӽڵ���
    children.insert(children.begin() + i + 1, z);  // �������ӽڵ�ָ��
    keys.insert(keys.begin() + i, y->keys[t - 1]);  // ������ֵ�����ڵ�
}

// ��B����ɾ����ֵ
void BTree::remove(int k) {
    if (!root) {
        cout << "���ǿյ�\n";
        return;
    }
    root->remove(k);
    if (root->keys.size() == 0) {  // ������ڵ�Ϊ�գ����¸��ڵ�
        BTreeNode* tmp = root;
        if (root->leaf) {
            root = nullptr;
        } else {
            root = root->children[0];
        }
        delete tmp;
    }
}

// �ӽڵ���ɾ����ֵ
void BTreeNode::remove(int k) {
    int idx = findKey(k);
    if (idx < keys.size() && keys[idx] == k) {  // �ҵ���ֵ
        if (leaf) {
            removeFromLeaf(idx);  // �����Ҷ�ӽڵ㣬ֱ��ɾ��
        } else {
            removeFromNonLeaf(idx);  // ����Ƿ�Ҷ�ӽڵ㣬ɾ����Ҷ�ӽڵ�ļ�ֵ
        }
    } else {
        if (leaf) {
            cout << "��ֵ " << k << " ��������\n";
            return;
        }
        bool flag = (idx == keys.size());
        if (children[idx]->keys.size() < t) {
            fill(idx);  // ����ӽڵ��ֵ��С��t������ӽڵ�
        }
        if (flag && idx > keys.size()) {
            children[idx - 1]->remove(k);  // ������һ���ӽڵ㱻�ϲ����ݹ�ɾ��
        } else {
            children[idx]->remove(k);  // �ݹ�ɾ����ֵ
        }
    }
}

// ��Ҷ�ӽڵ�ɾ����ֵ
void BTreeNode::removeFromLeaf(int idx) {
    keys.erase(keys.begin() + idx);
}

// �ӷ�Ҷ�ӽڵ�ɾ����ֵ
void BTreeNode::removeFromNonLeaf(int idx) {
    int k = keys[idx];
    if (children[idx]->keys.size() >= t) {  // ���ǰ���ӽڵ����㹻�ļ�ֵ
        int pred = getPred(idx);
        keys[idx] = pred;
        children[idx]->remove(pred);
    } else if (children[idx + 1]->keys.size() >= t) {  // �������ӽڵ����㹻�ļ�ֵ
        int succ = getSucc(idx);
        keys[idx] = succ;
        children[idx + 1]->remove(succ);
    } else {
        merge(idx);  // �ϲ��ӽڵ㲢ɾ����ֵ
        children[idx]->remove(k);
    }
}

// ��ȡ����Ϊidx��ǰ��
int BTreeNode::getPred(int idx) {
    BTreeNode* cur = children[idx];
    while (!cur->leaf) {
        cur = cur->children[cur->keys.size()];
    }
    return cur->keys[cur->keys.size() - 1];
}
// ��ȡ����Ϊidx�ĺ��
int BTreeNode::getSucc(int idx) {
    BTreeNode* cur = children[idx + 1];
    while (!cur->leaf) {
        cur = cur->children[0];
    }
    return cur->keys[0];
}

// ���ֵܽڵ���ֵ
void BTreeNode::fill(int idx) {
    if (idx != 0 && children[idx - 1]->keys.size() >= t) {
        borrowFromPrev(idx);  // ���ǰһ���ֵܽڵ����㹻�ļ�ֵ����ǰһ���ֵܽڵ���ֵ
    } else if (idx != keys.size() && children[idx + 1]->keys.size() >= t) {
        borrowFromNext(idx);  // �����һ���ֵܽڵ����㹻�ļ�ֵ���Ӻ�һ���ֵܽڵ���ֵ
    } else {
        if (idx != keys.size()) {
            merge(idx);  // ���ǰ���ֵܽڵ㶼û���㹻�ļ�ֵ���ϲ���ǰ�ڵ�ͺ�һ���ֵܽڵ�
        } else {
            merge(idx - 1);  // �����ǰ�ڵ������һ���ڵ㣬�ϲ���ǰ�ڵ��ǰһ���ֵܽڵ�
        }
    }
}

// ��ǰһ���ֵܽڵ���ֵ
void BTreeNode::borrowFromPrev(int idx) {
    BTreeNode* child = children[idx];
    BTreeNode* sibling = children[idx - 1];
    for (int i = child->keys.size() - 1; i >= 0; i--) {
        child->keys[i + 1] = child->keys[i];  // ����ǰ�ڵ�ļ�ֵ����
    }
    if (!child->leaf) {
        for (int i = child->children.size() - 1; i >= 0; i--) {
            child->children[i + 1] = child->children[i];  // ����ǰ�ڵ���ӽڵ�ָ������
        }
    }
    child->keys[0] = keys[idx - 1];  // �����ڵ�ļ�ֵ���Ƶ���ǰ�ڵ�
    if (!child->leaf) {
        child->children[0] = sibling->children[sibling->children.size() - 1];  // ���ֵܽڵ�����һ���ӽڵ�ָ���Ƶ���ǰ�ڵ�ĵ�һ��λ��
    }
    keys[idx - 1] = sibling->keys[sibling->keys.size() - 1];  // ���ֵܽڵ�����һ����ֵ���Ƶ����ڵ�
    sibling->keys.pop_back();  // ɾ���ֵܽڵ�����һ����ֵ
    if (!sibling->leaf) {
        sibling->children.pop_back();  // ɾ���ֵܽڵ�����һ���ӽڵ�ָ��
    }
}

// �Ӻ�һ���ֵܽڵ���ֵ
void BTreeNode::borrowFromNext(int idx) {
    BTreeNode* child = children[idx];
    BTreeNode* sibling = children[idx + 1];
    child->keys.push_back(keys[idx]);  // �����ڵ�ļ�ֵ���Ƶ���ǰ�ڵ�
    if (!child->leaf) {
        child->children.push_back(sibling->children[0]);  // ���ֵܽڵ�ĵ�һ���ӽڵ�ָ���Ƶ���ǰ�ڵ�����һ��λ��
    }
    keys[idx] = sibling->keys[0];  // ���ֵܽڵ�ĵ�һ����ֵ���Ƶ����ڵ�
    sibling->keys.erase(sibling->keys.begin());  // ɾ���ֵܽڵ�ĵ�һ����ֵ
    if (!sibling->leaf) {
        sibling->children.erase(sibling->children.begin());  // ɾ���ֵܽڵ�ĵ�һ���ӽڵ�ָ��
    }
}

// �ϲ��ڵ�
void BTreeNode::merge(int idx) {
    BTreeNode* child = children[idx];
    BTreeNode* sibling = children[idx + 1];
    child->keys.push_back(keys[idx]);  // �����ڵ�ļ�ֵ���Ƶ���ǰ�ڵ�
    for (int i = 0; i < sibling->keys.size(); i++) {
        child->keys.push_back(sibling->keys[i]);  // ���ֵܽڵ�ļ�ֵȫ���Ƶ���ǰ�ڵ�
    }
    if (!child->leaf) {
        for (int i = 0; i < sibling->children.size(); i++) {
            child->children.push_back(sibling->children[i]);  // ���ֵܽڵ���ӽڵ�ָ��ȫ���Ƶ���ǰ�ڵ�
        }
    }
    keys.erase(keys.begin() + idx);  // ɾ�����ڵ�ļ�ֵ
    children.erase(children.begin() + idx + 1);  // ɾ�����ڵ���ӽڵ�ָ��
    delete sibling;  // �ͷ��ֵܽڵ���ڴ�
}

// ���Ҽ�ֵ��λ��
int BTreeNode::findKey(int k) {
    int idx = 0;
    while (idx < keys.size() && keys[idx] < k) {
        ++idx;
    }
    return idx;  // ���ؼ�ֵ��λ��
}

// ����B��
int main() {
    BTree t(3); // ����һ����С����Ϊ3��B��
    t.insert(10);
    t.insert(20);
    t.insert(5);
    t.insert(6);
    t.insert(12);
    t.insert(30);
    t.insert(7);
    t.insert(17);

    cout << "���������ı���: ";
    t.traverse();
    cout << endl;

    t.remove(6);
    cout << "ɾ��6������ı���: ";
    t.traverse();
    cout << endl;

    t.remove(13);
    cout << "ɾ��13������ı���: ";
    t.traverse();
    cout << endl;

    t.remove(7);
    cout << "ɾ��7������ı���: ";
    t.traverse();
    cout << endl;

    t.remove(4);
    cout << "ɾ��4������ı���: ";
    t.traverse();
    cout << endl;

    t.remove(2);
    cout << "ɾ��2������ı���: ";
    t.traverse();
    cout << endl;

    t.remove(16);
    cout << "ɾ��16������ı���: ";
    t.traverse();
    cout << endl;
    system("pause");
    return 0;
}
