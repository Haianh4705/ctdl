#include <iostream>
using namespace std;

template <class T>
struct Node {
    T value;
    Node<T>* l;
    Node<T>* r;
    Node(T v = T(), Node<T>* _l = nullptr, Node<T>* _r = nullptr): value(v), l(_l), r(_r) {}
};

template <class T>
class BST {
private:
    Node<T>* root;

    Node<T>* addNode(Node<T>* node, T value) {
        if (!node) return new Node<T>(value);
        if (value < node->value) {
            node->l = addNode(node->l, value);
        } else if (value > node->value) {
            node->r = addNode(node->r, value);
        }
        return node;
    }

    Node<T>* findMin(Node<T>* node) {
        while (node && node->l) {
            node = node->l;
        }
        return node;
    }

    Node<T>* delNode(Node<T>* node, T value) {
        if (!node) return node;
        if (value < node->value) {
            node->l = delNode(node->l, value);
        } else if (value > node->value) {
            node->r = delNode(node->r, value);
        } else {
            if (node->l == nullptr) {
                Node<T>* tmp = node->r;
                delete node;
                return tmp;
            } else if (node->r == nullptr) {
                Node<T>* tmp = node->l;
                delete node;
                return tmp;
            }

            Node<T>* tmp = findMin(node->r);
            node->value = tmp->value;
            node->r = delNode(node->r, tmp->value);
        }
        return node;
    }

    void printTree(Node<T>* node) {
        if (node) {
            printTree(node->l);
            cout << node->value << ' ';
            printTree(node->r);
        }
    }
public:
    BST() {
        root = nullptr;
    }

    ~BST() {}

    void addNode(T value) {
        root = addNode(root, value);
    }

    void delNode(T value) {
        root = delNode(root, value);
    }

    void printTree() {
        printTree(root);
    }
};

main() {
    BST<int> t;
    t.addNode(3);
    t.addNode(2);
    t.addNode(4);
    t.addNode(5);
    t.addNode(1);
    t.delNode(3);
    t.printTree();
}
