#include <iostream>
#include <string>

using namespace std;

int main() {
    // Input string
    string input = "R?????,2?)";
    
    // Define variables for the numbers and the operator
    int num1 = 0, num2 = 0;
    char op;
    
    // Loop through the input to gather the numbers and operator
    for (char c : input) {
        if (c >= '0' && c <= '9') {
            if (num1 == 0) {
                num1 = c - '0';
            } else {
                num2 = c - '0';
            }
        } else if (c == '+' || c == '-' || c == '*' || c == '/') {
            op = c;
        }
    }
    
    // Perform the calculation
    int result;
    if (op == '+') {
        result = num1 + num2;
    } else if (op == '-') {
        result = num1 - num2;
    } else if (op == '*') {
        result = num1 * num2;
    } else if (op == '/') {
        if (num2 != 0) {
            result = num1 / num2;
        } else {
            cout << "Cannot divide by zero" << endl;
            return 1;
        }
    }
    
    // Output the result
    cout << result << endl;
    
    return 0;
}