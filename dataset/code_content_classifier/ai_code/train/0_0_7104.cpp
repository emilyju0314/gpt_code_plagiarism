#include <iostream>
#include <string>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    
    string s, t;
    cin >> s >> t;
    
    long long c = 0;
    
    for (int i = 0; i < n; i++) {
        int diff = t[i] - s[i] + 1;
        c += diff;
    }
    
    if (n == 1) {
        cout << c << endl;
    } else {
        int common_prefix = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == t[i]) {
                common_prefix++;
            } else {
                break;
            }
        }
        
        c -= (c - common_prefix) / 2;
        cout << c << endl;
    }
    
    return 0;
}