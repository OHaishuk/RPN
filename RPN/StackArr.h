#include <array>
#include <iostream>
#include <stdexcept>
template <typename T, int Size>
class Stack {
    std::array<T, Size> s;
    int top;
public:
    Stack() {
        top = -1;
    }
    bool isEmpty() {
        return top == -1;
    }
    bool isFull() {
        return top == Size - 1;
    }
    void push(T value) {
        if (isFull()) {
            std::cout << "Stack is full - is not possible to add the element";
            throw std::overflow_error("Stack is full");
        }
        top++;
        s[top] = value;
    }
    T pop() {
        if (isEmpty()) {
            std::cout << "Stack is empty - is not possible to remove element";
            throw std::underflow_error("Stack is empty");
        }
        T elem = s[top];
        top--;
        return elem;
    }
    T peek() {
        if (isEmpty()) {
            std::cout << "Stack is empty - is not possible to get element";
            throw std::underflow_error("Stack is empty");
        }
        return s[top];
    }
    int size() {
        return top + 1;
    }
};
