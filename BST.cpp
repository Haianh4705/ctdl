#include <iostream>
using namespace std;

template <class T>
struct Node {
    T value;
    Node<T>* left;
    Node<T>* right;
    Node(T v = T(), Node<T>* l = nullptr, Node<T>* r = nullptr): value(v), left(l), right(r) {}
};

template <class T>
class BST {
private:
    Node<T>* root;

    Node<T>* add(Node<T>* node, T value) {
        if (!node) return new Node(value);
        if (value < node->value) node->left = add(node->left, value);
        else node->right = add(node->right, value);
        return node;
    }

    Node<T>* findMin(Node<T>* node) {
        while (node && node->left) {
            node = node->left;
        }
        return node;
    }

    Node<T>* del(Node<T>* node, T value) {
        if (!node) return node;
        if (value < node->value) node->left = del(node->left, value);
        else if (value > node->value) node->right = del(node->right, value);
        else {
            if (node->left == nullptr) {
                Node<T>* tmp = node->right;
                delete node;
                return tmp;
            } else if (node->right == nullptr) {
                Node<T>* tmp = node->left;
                delete node;
                return tmp;
            }

            Node<T>* tmp = findMin(node->right);
            node->value = tmp->value;
            node->right = del(node->right, tmp->value);
        }
        return node;
    }

    void print(Node<T>* node) {
        if (node) {
            print(node->left);
            cout << node->value << ' ';
            print(node->right);
        }
    }

    void clr(Node<T>* node) {
        if (node) {
            clr(node->left);
            clr(node->right);
            delete node;
        }
    }
public:
    BST() {
        root = nullptr;
    }

    ~BST() {
        clr(root);
    }

    void add(T value) {
        root = add(root, value);
    }

    void del(T value) {
        root = del(root, value);
    }

    void print() {
        print(root);
    }
};

int main() {
    BST<int> t;
    t.add(5);
    t.add(7);
    t.add(4);
    t.add(6);
    t.add(9);
    t.add(2);
    t.del(5);
    t.print();
    return 0;
}
