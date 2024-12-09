#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int f(int n);

int evaluateArithmExpr(string arithmExpr, int n) {
    int result = 0;
    string currentExpr = "";
    char operation = '+';
    
    for (int i = 0; i < arithmExpr.size(); i++) {
        char c = arithmExpr[i];
        if (c == ' ') continue;
        if (c == '+' || c == '-') {
            if (!currentExpr.empty()) {
                int value = currentExpr[0] == 'f' ? f(evaluateArithmExpr(currentExpr.substr(2), n)) : stoi(currentExpr);
                result = operation == '+' ? (result + value) % 32768 : (result - value + 32768) % 32768;
                currentExpr = "";
            }
            operation = c;
        } else {
            currentExpr += c;
        }
    }
    
    if (!currentExpr.empty()) {
        int value = currentExpr[0] == 'f' ? f(evaluateArithmExpr(currentExpr.substr(2), n)) : stoi(currentExpr);
        result = operation == '+' ? (result + value) % 32768 : (result - value + 32768) % 32768;
    }
    
    return result;
}

bool evaluateLogicalExpr(string logicalExpr, int n) {
    int pos = logicalExpr.find("==");
    if (pos != string::npos) {
        return evaluateArithmExpr(logicalExpr.substr(0, pos), n) == evaluateArithmExpr(logicalExpr.substr(pos + 2), n);
    }
    
    pos = logicalExpr.find("<");
    if (pos != string::npos) {
        return evaluateArithmExpr(logicalExpr.substr(0, pos), n) < evaluateArithmExpr(logicalExpr.substr(pos + 1), n);
    }
    
    pos = logicalExpr.find(">");
    if (pos != string::npos) {
        return evaluateArithmExpr(logicalExpr.substr(0, pos), n) > evaluateArithmExpr(logicalExpr.substr(pos + 1), n);
    }
    
    return false;
}

int f(int n) {
    // Input description of the function
    int result;
    string line;
    while (getline(cin, line)) {
        size_t pos = line.find("return");
        if (pos != string::npos) {
            result = evaluateArithmExpr(line.substr(pos + 6), n);
        } else {
            pos = line.find("if");
            if (evaluateLogicalExpr(line.substr(pos + 3, line.size() - pos - 5), n)) {
                getline(cin, line);
                result = evaluateArithmExpr(line.substr(6), n);
            }
        }
    }
    
    return result;
}

int main() {
    int target;
    cin >> target;
    
    for (int i = 0; i <= 32767; i++) {
        if (f(i) == target) {
            cout << i << endl;
            return 0;
        }
    }
    
    cout << -1 << endl;
    
    return 0;
}