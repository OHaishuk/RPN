#include <iostream>
#include <sstream>
#include <string>
#include "StackArr.h"

int main() {
    std::string expression;
    std::getline(std::cin, expression);

    std::stringstream ss(expression);
    Stack<int, 100> stack;

    std::string token;
    while (ss >> token) {
        if (token == "+" || token == "-" || token == "*" || token == "/") {
            int b = stack.pop();
            int a = stack.pop();
            int result;

            if (token == "+")
                result = a + b;
            else if (token == "-")
                result = a - b;
            else if (token == "*")
                result = a * b;
            else
				result = a / b; // token == "/", no division by zero error handling

            stack.push(result);
        }
        else {
            int value = std::stoi(token);
            stack.push(value);
        }
    }

    std::cout << stack.pop() << std::endl;
    return 0;
}
