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
    Node<T>* head;
    int size;
public:
    Stack(): head(nullptr), size(0) {}
    ~Stack() {
        Node<T>* cur = head;
        while (cur) {
            Node<T>* tmp = cur->next;
            delete cur;
            cur = tmp;
        }
    }

    void push(T value) {
        Node<T>* node = new Node<T>(value);
        node->next = head;
        head = node;
        size++;
    }

    T pop() {
        if (head) {
            Node<T>* tmp = head;
            T ret = head->value;
            head = head->next;
            delete tmp;
            return ret;
        } else return T();
    }

    T front() {
        if (head) {
            return head->value;
        } else return T();
    }

    void print() {
        Node<T>* cur = head;
        while (cur) {
            cout<<cur->value<<' ';
            cur = cur->next;
        }
        cout<<endl;
    }
};

int main() {
    Stack<int> s;
    s.push(0);
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.print();
    s.pop();
    s.print();
    return 0;
}
