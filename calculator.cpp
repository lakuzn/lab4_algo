#include <string>
#include "calculator.h"

int evaluatePostfixExpression(string expression) {
    Stack stack;
    for (char c : expression) {
        if (isOperand(c)) {
            // преобразуем символ в число и кладем его в стек
            stack.push(c - '0');
        }
        else if (isOperator(c)) {
            // проверяем, что в стеке есть два операнда
            if (stack.size() < 2) {
                throw runtime_error("Invalid expression");
            }
            // извлекаем два операнда из стека и выполняем операцию
            int op2 = stack.top();
            stack.pop();
            int op1 = stack.top();
            stack.pop();
            switch (c) {
            case '+':
                stack.push(op1 + op2);
                break;
            case '-':
                stack.push(op1 - op2);
                break;
            case '*':
                stack.push(op1 * op2);
                break;
            case '/':
                if (op2 == 0) {
                    throw runtime_error("Division by zero");
                }
                stack.push(op1 / op2);
                break;
            }
        }
        else {
            // некорректный символ
            throw runtime_error("Invalid expression");
        }
    }
    // в стеке должен остаться один операнд
    if (stack.size() != 1) {
        throw runtime_error("Invalid expression");
    }
    return stack.top();
}

int main() {
    setlocale(LC_ALL, "RU");
    while (true) {
        string infix;
        string postfix;
        cout << "Введите постфиксное выражение. Для выхода из программы введите 0: ";
        getline(cin, infix);
        if (infix == "0") {
            break;
        }
        postfix = to_postfix(infix);
        cout << postfix << endl;
        int result = evaluatePostfixExpression(postfix);
        cout << "Результат: " << result << endl;
        }
    return 0;
}