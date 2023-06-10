#pragma once
#include <iostream>

using namespace std;

class TNode {
public:
    int val;
    TNode* next;

    TNode(int val) {
        this->val = val;
        this->next = nullptr;
    }
};

class Stack {
private:
    TNode* top_node;

public:
    Stack() {
        this->top_node = nullptr;
    }

    ~Stack() {
        while (!empty()) {
            pop();
        }
    }

    bool empty() {
        return top_node == nullptr;
    }

    void push(int val) {
        TNode* new_node = new TNode(val);
        new_node->next = top_node;
        top_node = new_node;
    }

    int pop() {
        if (!empty()) {
            TNode* temp = top_node;
            top_node = top_node->next;
            delete temp;
        }
        return 0;
    }

    int size() {
        int count = 0;
        TNode* current = top_node;
        while (current != nullptr) {
            count++;
            current = current->next;
        }
        return count;
    }

    int top() {
        if (!empty()) {
            return top_node->val;
        }
        else {
            throw "Stack is empty";
        }
    }
};
