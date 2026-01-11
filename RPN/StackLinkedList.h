#include <iostream>
#include<stdexcept>
template <typename T>
struct Node {
    T data;
    Node* next;
    Node(T value) {
        data = value;
        next = nullptr;
    }
};

template <typename T>
class Stack {
    Node<T>* top;
    int size;
public:
    Stack() {
        top = nullptr;
        size = 0;
    }
    bool isEmpty() {
        return size == 0;
    }
    void push(T value) {
        //add the new element at front of the list
        Node <T>* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
        size++;
    }
    T pop() {
        //returns and remove element from the front
        if (isEmpty()) {
            std::cout << "Stack is Empty";
            throw std::underflow_error("Stack is empty");
        }
        T elem = top->data;
        Node<T>* temp = top;
        top = top->next;
        delete temp;
        size--;
        return elem;
    }
    T peek() {
        //returns element from the front
        if (isEmpty()) {
            std::cout << "Stack is Empty";
            throw std::underflow_error("Stack is empty");
        }
        return top->data;
    }

    int numberOfElements() {
        //returns numbers of elements stored in stack
        return size;
    }
};
