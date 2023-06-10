#include <iostream>

using namespace std;

class Node {
public:
    int val;
    Node* next;

    Node(int val) {
        this->val = val;
        this->next = nullptr;
    }
};

class Queue {
private:
    Node* front_node;
    Node* rear_node;

public:
    Queue() {
        this->front_node = nullptr;
        this->rear_node = nullptr;
    }

    ~Queue() {
        while (!empty()) {
            pop();
        }
    }

    bool empty() {
        return front_node == nullptr;
    }

    void push(int val) {
        Node* new_node = new Node(val);

        if (empty()) {
            front_node = new_node;
            rear_node = new_node;
        }
        else {
            rear_node->next = new_node;
            rear_node = new_node;
        }
    }

    void pop() {
        if (!empty()) {
            Node* temp = front_node;

            if (front_node == rear_node) {
                front_node = nullptr;
                rear_node = nullptr;
            }
            else {
                front_node = front_node->next;
            }

            delete temp;
        }
    }

    int size() {
        int count = 0;
        Node* current = front_node;
        while (current != nullptr) {
            count++;
            current = current->next;
        }
        return count;
    }

    int front() {
        if (!empty()) {
            return front_node->val;
        }
        else {
            throw "Queue is empty";
        }
    }

    int rear() {
        if (!empty()) {
            return rear_node->val;
        }
        else {
            throw "Queue is empty";
        }
    }
};