#include <iostream>
using namespace std;

template <class T>
class Vector {
private:
    T* arr;
    int size, capacity;
    
    void resize(int new_capacity) {
        T* new_arr = new T[new_capacity];
        for (int i = 0; i<size; i++) {
            new_arr[i] = arr[i];
        }
        delete[] arr;
        arr = new_arr;
        capacity = new_capacity;
    }
public:
    Vector(int initCapacity = 0): capacity(initCapacity) {
        size = 0;
    }

    ~Vector() {
        delete[] arr;
    }

    int getSize() {
        return size;
    }

    bool isEmpty() {
        return size == 0;
    }

    void pushBack(T value) {
        if (size == capacity) resize(size*2+1);
        arr[size++] = value;
    }

    T popBack() {
        if (size) {
            size--;
            return arr[size-1];
        } else return T();
    }

    void insert(int index, T value) {
        if (size == capacity) resize(size*2+1);
        for (int i = index; i<size; i++) {
            arr[i+1] = arr[i];
        }
        arr[index] = value;
        size++;
    }

    T erase(int index) {
        if (size) {
            T ret = arr[index];
            for (int i = index; i<size-1; i++) {
                arr[i] = arr[i+1];
            }
            size--;
            return ret;
        } else return T();
    }

    T operator[](int index) {
        return arr[index];
    }

    void print() {
        for (int i = 0; i<size; i++) {
            cout << arr[i] << " ";
        }
    }
};

main() {
    Vector<int> v;
    v.pushBack(1);
    v.insert(0, 0);
    v.popBack();
    v.print();
}
