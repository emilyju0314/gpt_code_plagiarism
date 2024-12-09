#include <iostream>
#include <string>

using namespace std;

int main() {
    string pattern;
    cin >> pattern;
    
    int n = pattern.size();
    
    int opening_count = 0;
    int closing_count = 0;
    
    for (int i = 0; i < n; i++) {
        if (pattern[i] == '(') {
            opening_count++;
        } else if (pattern[i] == ')') {
            closing_count++;
        }
    }
    
    int m = (n - opening_count - closing_count) / 2;
    
    int total_cost = 0;
    
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        
        if (a < b) {
            total_cost += a;
            pattern[pattern.find('?')] = '(';
        } else {
            total_cost += b;
            pattern[pattern.find('?')] = ')';
        }
    }
    
    if (opening_count + m != closing_count + m) {
        cout << "-1" << endl;
    } else {
        cout << total_cost << endl;
        cout << pattern << endl;
    }
    
    return 0;
}