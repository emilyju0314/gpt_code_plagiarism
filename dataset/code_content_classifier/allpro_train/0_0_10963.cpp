#include <iostream>
#include <string>
using namespace std;

int palindromeDegree(string s) {
    int n = s.length();
    int degree = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] == s[n-1 - i]) {
            degree++;
        } else {
            break;
        }
    }
    return degree;
}

int main() {
    string s;
    cin >> s;
    
    int sum = 0;
    for(int i = 0; i < s.length(); i++) {
        sum += palindromeDegree(s.substr(0, i+1));
    }
    
    cout << sum << endl;
    
    return 0;
}