#include <iostream>
#include <string>

using namespace std;

bool isUndoubtedlyLucky(int num) {
    string s = to_string(num);
    char x, y;
    if(s.length() == 1) return true;
    x = s[0];
    y = s[1];
    for(char c : s) {
        if(c != x && c != y) {
            return false;
        }
    }
    return true;
}

int countUndoubtedlyLucky(int n) {
    int count = 0;
    for(int i = 1; i <= n; i++) {
        if(isUndoubtedlyLucky(i)) {
            count++;
        }
    }
    return count;
}

int main() {
    int n;
    cin >> n;
    
    int result = countUndoubtedlyLucky(n);
    
    cout << result << endl;
    
    return 0;
}