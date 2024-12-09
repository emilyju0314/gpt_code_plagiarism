#include <iostream>
#include <string>

using namespace std;

int main() {
    string brackets;
    cin >> brackets;

    int balance = 0;
    int min_balance = 0;

    for(char c : brackets) {
        balance += (c == '(' ? 1 : -1);
        min_balance = min(min_balance, balance);
    }

    string result = "";
    for(int i = 0; i < -min_balance; i++) {
        result += "(";
    }

    result += brackets;
    
    balance = 0;
    for(char c : result) {
        balance += (c == '(' ? 1 : -1);
    }

    for(int i = 0; i < -min_balance; i++) {
        result += ")";
    }
    
    cout << result << endl;

    return 0;
}