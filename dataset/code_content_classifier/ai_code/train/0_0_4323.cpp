ethod 1: Use eval() function in Python to evaluate the expression
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

int main() {
    string expr;
    cin >> expr;
    string result_str;
    cin >> result_str;

    int result = stoi(result_str);

    int calc_result = 0;
    stringstream stream(expr);
    char operation;
    int number;

    stream >> calc_result;

    while(stream >> operation >> number) {
        if(operation == '+') {
            calc_result += number;
        } else if(operation == '-') {
            calc_result -= number;
        } else if(operation == '*') {
            calc_result *= number;
        } else if(operation == '/') {
            calc_result /= number;
        }
    }

    if(result == calc_result) {
        cout << "Method 1: True" << endl;
    } else {
        cout << "Method 1: False" << endl;
    }

    return 0;
}
