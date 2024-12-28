#include <iostream>
using namespace std;

template <class T>
class vector {
private:
    T* arr;
    int size, capacity;

    void resize(int new_capacity) {
        T* tmp = new T[new_capacity];
        for (int i = 0; i<size; i++) {
            tmp[i] = arr[i];
        }
        delete[] arr;
        arr = tmp;
        capacity = new_capacity;
    }
public:
    vector(int cap = 0): arr(new T[cap]), capacity(cap), size(0) {}
    ~vector() {
        delete[] arr;
    }

    int getSize() {
        return size;
    }

    bool isEmpty() {
        return size == 0;
    }

    void pushBack(T value) {
        if (size == capacity) {
            resize(capacity*2+1);
        }
        arr[size++] = value;
    }

    void popBack() {
        if (size > 0) size--;
    }

    void insert(int index, T value) {
        if (index >= size || index < 0) return;
        if (size == capacity) {
            resize(capacity*2+1);
        }
        for (int i = size; i>index; i--) {
            arr[i] = arr[i-1];
        }
        arr[index] = value;
        size++;
    }

    void erase(int index) {
        if (index >= size || index < 0) return;
        for (int i = index; i<size-1; i++) {
            arr[i] = arr[i+1];
        }
        size--;
    }

    T& operator[](int index) {
        if (index >= size || index < 0) return T();
        return arr[index];
    }

    void print() {
        for (int i = 0; i<size; i++) {
            cout<<arr[i]<<' ';
        }
        cout<<endl;
    }
};

int main() {
    vector<int> a;
    a.pushBack(0);
    a.pushBack(1);
    a.pushBack(2);
    a.pushBack(3);
    a.pushBack(4);
    a.pushBack(5);
    a.print();
    a.erase(4);
    a.print();
    a.insert(1, 4);
    a.print();
    a.popBack();
    a.print();
    return 0;
}
