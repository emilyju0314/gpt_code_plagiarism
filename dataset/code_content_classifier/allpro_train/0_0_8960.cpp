#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string expression;
    cin >> expression;
    
    long long result = 0;
    long long current_product = 1;
    
    for(int i = 0; i < expression.size(); i++) {
        if(expression[i] == '+') {
            result += current_product;
            current_product = 0;
        } else if (expression[i] == '*') {
            continue;
        } else {
            current_product *= (expression[i] - '0');
        }
    }
    
    result += current_product;
    
    cout << result << endl;
    
    return 0;
}