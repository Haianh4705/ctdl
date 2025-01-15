#include <iostream>
using namespace std;

template <class T>
struct Node {
    T value;
    Node<T>* left;
    Node<T>* right;
    int height;
    Node(T v = T()) : value(v), left(nullptr), right(nullptr), height(0) {}
};

template <class T>
class AVL {
private:
    Node<T>* root;

    int getHeight(Node<T>* node) {
        return node ? node->height : 0;
    }

    int getBalance(Node<T>* node) {
        return node ? getHeight(node->left) - getHeight(node->right) : 0;
    }

    Node<T>* findMin(Node<T>* node) {
        while (node && node->left) {
            node = node->left;
        }
        return node;
    }

    void rr(Node<T>* &node) {
        Node<T>* tmp = node->right;
        node->right = tmp->left;
        tmp->left = node;

        node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
        tmp->height = max(getHeight(tmp->right), node->height) + 1;
        node = tmp;
    }

    void ll(Node<T>* &node) {
        Node<T>* tmp = node->left;
        node->left = tmp->right;
        tmp->right = node;

        node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
        tmp->height = max(getHeight(tmp->left), node->height) + 1;
        node = tmp;
    }

    void lr(Node<T>* &node) {
        rr(node->left);
        ll(node);
    }

    void rl(Node<T>* &node) {
        ll(node->right);
        rr(node);
    }

    void insert(T value, Node<T>* &node) {
        if (!node) {
            node = new Node<T>(value);
        } else if (value < node->value) {
            insert(value, node->left);
        } else if (value > node->value) {
            insert(value, node->right);
        }
        balance(node);
    }

    void remove(T value, Node<T>* &node) {
        if (!node) return;
        if (value < node->value) {
            remove(value, node->left);
        } else if (value > node->value) {
            remove(value, node->right);
        } else {
            if (node->left && node->right) {
                node->value = findMin(node->right)->value;
                remove(node->value, node->right);
            } else {
                Node<T>* tmp = node;
                node = (node->left) ? node->left : node->right;
                delete tmp;
            }
        }
        balance(node);
    }

    void balance(Node<T>* &node) {
        if (!node) return;
        if (getBalance(node) > 1) {
            if (getBalance(node->left) >= 0) {
                ll(node);
            } else {
                lr(node);
            }
        } else if (getBalance(node) < -1) {
            if (getBalance(node->right) <= 0) {
                rr(node);
            } else {
                rl(node);
            }
        }
        node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
    }

    void print(Node<T>* node) {
        if (node) {
            print(node->left);
            cout << node->value << " ";
            print(node->right);
        }
    }

    void clear(Node<T>* &node) {
        if (node) {
            clear(node->left);
            clear(node->right);
            delete node;
            node = nullptr;
        }
    }

public:
    AVL() : root(nullptr) {}

    ~AVL() {
        clear(root);
    }

    void insert(T value) {
        insert(value, root);
    }

    void remove(T value) {
        remove(value, root);
    }

    void print() {
        print(root);
        cout << endl;
    }
};

int main() {
    AVL<int> t;
    t.insert(1);
    t.insert(2);
    t.insert(3);
    t.insert(4);
    t.insert(5);
    t.remove(3);
    t.print();
    return 0;
}
