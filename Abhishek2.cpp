// task2_calculator.cpp

#include <iostream>
using namespace std;

int main() {
    float num1, num2;
    char op;

    cout << "?? Simple Calculator\n";
    cout << "Enter first number: ";
    cin >> num1;

    cout << "Enter operator (+, -, *, /): ";
    cin >> op;

    cout << "Enter second number: ";
    cin >> num2;

    switch(op) {
        case '+': cout << "Result: " << num1 + num2; break;
        case '-': cout << "Result: " << num1 - num2; break;
        case '*': cout << "Result: " << num1 * num2; break;
        case '/':
            if (num2 != 0)
                cout << "Result: " << num1 / num2;
            else
                cout << "Error: Cannot divide by zero!";
            break;
        default:
            cout << "Invalid operator!";
    }

    return 0;
}

