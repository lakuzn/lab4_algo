#pragma once

#include <string>
#include <sstream>
#include "stack.h"
#include "queue.h"

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}


bool isOperand(char c) {
    return isdigit(c);
}

int precedence(char c) {
    if (c == '+' || c == '-') {
        return 1;
    }
    else if (c == '*' || c == '/') {
        return 2;
    }
    else {
        return 0;
    }
}

int Operation(string operation, int operand1, int operand2) {
    if (operation == "+")
        return operand1 + operand2;
    else if (operation == "-")
        return operand1 - operand2;
    else if (operation == "*")
        return operand1 * operand2;
    else if (operation == "/")
        return operand1 / operand2;
    cout << "Недопустимая операция." << endl; //защита, чтобы пользователь не написал какой-либо другой знак
    return 0;
}

string to_postfix(string inf_expresssion) {
    Stack operator_stack;
    Queue postfix_queue;
    for (int i = 0; i < inf_expresssion.length(); i++) {
        char c = inf_expresssion[i];
        if (c == ' ') {
            continue;
        }
        if (isOperand(c)) {
            postfix_queue.push(c);
        }
        else if (c == '(') {
            operator_stack.push(c);
        }
        else if (c == ')') {
            while (!operator_stack.empty() && operator_stack.top() != '(') {
                postfix_queue.push(operator_stack.top());
                operator_stack.pop();
            }
            operator_stack.pop();
        }
        else if (precedence(c) > 0) {
            while (!operator_stack.empty() && precedence(operator_stack.top()) >= precedence(c)) {
                postfix_queue.push(operator_stack.top());
                operator_stack.pop();
            }
            operator_stack.push(c);
        }
    }
    while (!operator_stack.empty()) {
        postfix_queue.push(operator_stack.top());
        operator_stack.pop();
    }
    string postfix_expression = "";
    while (!postfix_queue.empty()) {
        postfix_expression += postfix_queue.front();
        postfix_queue.pop();
    }
    return postfix_expression;
}
