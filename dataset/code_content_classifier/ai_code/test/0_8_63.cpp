#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> cnt(n);
    int total_open = 0, max_valid_prefix = 0;
    
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        
        int open = 0, close = 0;
        for(char c : s) {
            if (c == '(') {
                open++;
            } else {
                if (open > 0) {
                    open--;
                } else {
                    close++;
                }
            }
        }
        
        if (open > 0 && close == 0) {
            cnt[i] = open;
        } else if (open == 0 && close > 0) {
            cnt[i] = -close;
        }
        
        total_open += open;
        max_valid_prefix += min(open, close);
    }
    
    if (total_open == 0) {
        cout << max_valid_prefix << endl;
    } else {
        cout << 0 << endl;
    }

    return 0;
}