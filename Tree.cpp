#include <iostream>
using namespace std;

template <class T>
struct Node {
    T value;
    Node<T>* child;
    Node<T>* sibling;
    Node(T v = T(), Node<T>* c = nullptr, Node<T>* s = nullptr): value(v), child(c), sibling(s) {}
};

template <class T>
class Tree {
private:
    Node<T>* root;

    Node<T>* findNode(Node<T>* node, T value) {
        if (!node) return nullptr;
        if (node->value == value) return node;
        Node<T>* tmp = findNode(node->child, value);
        if (tmp) return tmp;
        return findNode(node->sibling, value);
    }

    void delTree(Node<T>* node) {
        if (!node) return;
        delTree(node->child);
        delTree(node->sibling);
        delete node;
    }

    Node<T>* delNode(Node<T>* parent, Node<T>* node) {
        if (!parent || !node) return nullptr;
        if (parent->child == node) {
            Node<T>* tmp = node->sibling;
            delTree(node->child);
            delete node;
            parent->child = tmp;
            return tmp;
        }
        Node<T>* cur = parent->child;
        while (cur && cur->sibling != node) {
            cur = cur->sibling;
        }
        if (cur) {
            Node<T>* tmp = node->sibling;
            delTree(node->child);
            delete node;
            cur->sibling = tmp;
        }
        return nullptr;
    }

    void printTree(Node<T>* node) {
        if (!node) return;
        printTree(node->child);
        printTree(node->sibling);
        cout << node->value << ' ';
    }
public:
    Tree() {
        root = nullptr;
    }

    ~Tree() {
        delTree(root);
    }

    void addRoot(T value) {
        Node<T>* node = new Node<T>(value);
        if (root) {
            node->child = root;
            root = node;
        } else {
            root = node;
        }
    }

    Node<T>* findNode(T value) {
        return findNode(root, value);
    }

    void addNode(T parent, T value) {
        Node<T>* par = findNode(parent);
        if (par) {
            Node<T>* node = new Node<T>(value);
            if (par->child) {
                node->sibling = par->child;
            }
            par->child = node;
        }
    }

    void delNode(T value) {
        if (!root) return;
        if (root->value == value) {
            delTree(root);
            return;
        }
        delNode(root, findNode(root, value));
    }

    void printTree() {
        printTree(root);
    }
};

main() {
    Tree<int> t;
    t.addRoot(1);
    t.addNode(1, 2);
    t.addNode(1, 3);
    t.addNode(2, 4);
    t.delNode(2);
    t.printTree();
}
