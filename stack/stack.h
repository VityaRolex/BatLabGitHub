#ifdef STACK_H
#define STACK_H
#include <iostream>
template <typename T>
class MyStack {
    T* arr;
    const int SIZE;
    int top;
public:
    MyStack(int size = 100) : SIZE(size), top(0) {
        arr = new T[SIZE];
    }

    MyStack(const MyStack& other) : SIZE(other.SIZE), top(other.top) {
        arr = new T[SIZE];
        for (int i{}; i <= top; ++i)
        {
            arr[i] = other_stack.arr[i];
        }
    }

    ~MyStack() {
        delete[] arr;
    }

    bool isEmpty() const {
        return top == 0;
    }

    bool isFull() const {
        return top == SIZE;
    }

    void push(const T& value) {
        if (isFull()) {
            throw "Stack overflow";
            return;
        }
        arr[top] = value;
        ++top;
    }

    void pop() {
        if (isEmpty()) {
            throw "Stack empty";
            return;
        }
        --top;
    }

    T peek() const {
        if (isEmpty()) {
            throw "Stack empty";
        }
        return arr[top - 1];
    }
};

#endif