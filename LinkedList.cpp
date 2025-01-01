#include <iostream>
using namespace std;

template <class T>
struct Node {
    T value;
    Node<T>* next;
    Node(T v = T(), Node<T>* n = nullptr): value(v), next(n) {}
};

template <class T>
class SingleList {
private:
    Node<T>* root;
    int size;
public:
    SingleList() {
        root = nullptr;
        size = 0;
    }

    ~SingleList() {
        Node<T>* cur = root;
        while (cur) {
            Node<T>* tmp = cur;
            cur = cur->next;
            delete tmp;
        }
    }

    void print() {
        Node<T>* cur = root;
        while (cur) {
            cout << cur->value << ' ';
            cur = cur->next;
        }
    }

    void pushFront(T value) {
        Node<T>* node = new Node<T>(value, root);
        root = node;
        size++;
    }

    void popFront() {
        if (root) {
            Node<T>* tmp = root;
            root = tmp->next;
            delete tmp;
            size--;
        }
    }

    void insert(int index, T value) {
        Node<T>* node = new Node<T>(value);
        if (index) {
            Node<T>* cur = root;
            for (int i = 0; i<index-1; i++) cur = cur->next;
            node->next = cur->next;
            cur->next = node;
        } else {
            pushFront(value);
        }
        size++;
    }

    void erase(int index) {
        if (size == 0) return;
        if (index) {
            Node<T>* cur = root;
            for (int i = 0; i<index-1; i++) cur = cur->next;
            Node<T>* tmp = cur->next;
            cur->next = tmp->next;
            delete tmp;
        } else {
            Node<T>* tmp = root;
            root = root->next;
            delete tmp;
        }
        size--;
    }
};

main() {
    SingleList<int> s;
    s.pushFront(3);
    s.pushFront(1);
    s.insert(1, 2);
    s.erase(2);
    s.print();
}
