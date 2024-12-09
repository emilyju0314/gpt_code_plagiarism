#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    int openCount = 0;
    int answer = 0;
    
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        
        int balance = 0;
        for (char c : s) {
            if (c == '(') {
                balance++;
            } else {
                balance--;
            }
            
            openCount = min(openCount, balance);
        }
        
        if (balance >= 0) {
            answer += count(s.begin(), s.end(), '(');
        } else if (balance + openCount >= 0) {
            answer += s.size();
        }
    }
    
    cout << answer << endl;
    
    return 0;
}