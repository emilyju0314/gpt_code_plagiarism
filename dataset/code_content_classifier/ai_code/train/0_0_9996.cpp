#include <iostream>
#include <string>

using namespace std;

int main() {
    string expression;
    cin >> expression;

    int countA = 0, countB = 0, countC = 0;
    int equalPos = expression.find('=');
    
    // Count the number of sticks for A, B, and C
    for (int i = 0; i < equalPos; i++) {
        if (expression[i] == '|') {
            countA++;
        }
    }
    for (int i = equalPos + 1; i < expression.length(); i++) {
        if (expression[i] == '|') {
            countC++;
        }
    }
    countB = expression.length() - equalPos - countC - 2; // subtract 2 for '=' and '+'
    
    // Check if the expression is already correct
    if (countA + countB == countC) {
        cout << expression << endl;
    } else { // Try to shift sticks to make the expression correct
        if (countA + 1 + countB == countC - 1) {
            cout << "|";
            for (int i = 1; i < countA; i++) {
                cout << "|";
            }
            cout << "+";
            for (int i = 0; i < countB; i++) {
                cout << "|";
            }
            cout << "=";
            for (int i = 0; i < countC - 1; i++) {
                cout << "|";
            }
        } else if (countA - 1 + countB == countC + 1) {
            for (int i = 0; i < countA - 1; i++) {
                cout << "|";
            }
            cout << "+";
            for (int i = 0; i < countB; i++) {
                cout << "|";
            }
            cout << "=";
            for (int i = 0; i < countC + 1; i++) {
                cout << "|";
            }
        } else {
            cout << "Impossible";
        }
        cout << endl;
    }

    return 0;
}