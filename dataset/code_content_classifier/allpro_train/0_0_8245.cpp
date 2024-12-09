#include <iostream>
#include <string>

using namespace std;

int minOperations(string s) {
    int cnt = 0;
    int n = s.length();
    
    // Count the number of occurrences of "010" and "101" in the string
    for (int i = 0; i < n - 2; i++) {
        if (s[i] == '0' && s[i + 1] == '1' && s[i + 2] == '0') {
            cnt++;
            s[i + 1] = '0';
        } else if (s[i] == '1' && s[i + 1] == '0' && s[i + 2] == '1') {
            cnt++;
            s[i + 1] = '1';
        }
    }
    
    return cnt;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        string s;
        cin >> s;
        
        cout << minOperations(s) << endl;
    }
    
    return 0;
}