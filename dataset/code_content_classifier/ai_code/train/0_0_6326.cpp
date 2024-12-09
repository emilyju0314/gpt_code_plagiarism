#include <iostream>
#include <string>

using namespace std;

int minOperationsToDeleteString(string s) {
    int operations = 0;
    int n = s.length();
    
    for (int i = 0; i < n; i++) {
        int count = 1;
        while (i + 1 < n && s[i] == s[i + 1]) {
            count++;
            i++;
        }
        operations++;
    }
    
    return operations;
}

int main() {
    int n;
    cin >> n;
    
    string s;
    cin >> s;
    
    cout << minOperationsToDeleteString(s) << endl;
    
    return 0;
}