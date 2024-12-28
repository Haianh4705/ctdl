#include <iostream>
using namespace std;

template <class T>
struct Node {
    T value;
    Node<T>* next;

    Node(T v = T(), Node<T>* n = nullptr): value(v), next(n) {}
};

template <class T>
class LinkedList {
private:
    Node<T>* head;
    int size;
public:
    LinkedList(): head(nullptr), size(0) {}
    ~LinkedList() {
        Node<T>* cur = head;
        while (cur) {
            Node<T>* tmp = cur->next;
            delete cur;
            cur = tmp;
        }
    }

    void pushBack(T value) {
        Node<T>* node = new Node<T>(value);
        if (head) {
            Node<T>* cur = head;
            while (cur->next) {
                cur = cur->next;
            }
            cur->next = node;
        } else {
            head = node;
        }
        size++;
    }

    void pushFront(T value) {
        Node<T>* node = new Node<T>(value);
        node->next = head;
        head = node;
        size++;
    }

    void insert(int index, T value) {
        if (index >= size || index < 0) return;
        Node<T>* node = new Node<T>(value);
        if (index) {
            Node<T>* cur = head;
            for (int i = 1; i<index; i++) {
                cur = cur->next;
            }
            Node<T>* tmp = cur->next;
            cur->next = node;
            node->next = tmp;
        } else {
            node->next = head;
            head = node;
        }
        size++;
    }

    void erase(T value) {
        if (!head) return;
        if (head->value == value) {
            Node<T>* tmp = head;
            head = head->next;
            delete tmp;
            size--;
        } else {
            Node<T>* cur = head;
            while (cur->next) {
                if (cur->next->value == value) {
                    Node<T>* tmp = cur->next;
                    cur->next = cur->next->next;
                    delete tmp;
                    size--;
                    break;
                }
                cur = cur->next;
            }
        }
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
    LinkedList<int> ll;
    ll.pushBack(5);
    ll.pushFront(4);
    ll.pushFront(3);
    ll.pushFront(2);
    ll.pushFront(1);
    ll.pushFront(0);
    ll.print();
    ll.insert(1, 6);
    ll.print();
    ll.erase(3);
    ll.print();
    return 0;
}
