#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    string result = "";
    
    if (n == 1) {
        result = "a";
    } else if (n == 2) {
        result = "aa";
    } else {
        result = "abb";
        char lastChar = 'b';
        for (int i = 3; i < n; i++) {
            if (lastChar == 'a') {
                result += 'b';
                lastChar = 'b';
            } else {
                result += 'a';
                lastChar = 'a';
            }
        }
    }
    
    cout << result << endl;
    
    return 0;
}