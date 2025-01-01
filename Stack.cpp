#include <iostream>
using namespace std;

template <class T>
struct Node {
    T value;
    Node<T>* next;
    Node(T v = T(), Node<T>* n = nullptr): value(v), next(n) {}
};

template <class T>
class Stack {
private:
    Node<T>* root;
    int size;
public:
    Stack() {
        root = nullptr;
        size = 0;
    }

    ~Stack() {
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

    void push(T value) {
        Node<T>* node = new Node<T>(value, root);
        root = node;
        size++;
    }

    void pop() {
        if (root) {
            Node<T>* tmp = root;
            root = tmp->next;
            delete tmp;
            size--;
        }
    }
};

main() {
    Stack<int> s;
    s.push(0);
    s.push(1);
    s.pop();
    s.print();
}
