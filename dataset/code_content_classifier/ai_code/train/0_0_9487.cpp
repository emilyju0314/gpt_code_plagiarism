#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    
    int ans = 1;
    int current = 1;
    for(int i = 1; i < n; i++) {
        if(s[i] != s[i-1]) {
            current++;
        } else {
            ans = max(ans, current);
            current = 1;
        }
    }
    ans = max(ans, current);
    
    if(ans >= n-1) {
        cout << n << endl;
    } else {
        int flip = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] == s[(i+1) % n]) {
                flip++;
            }
        }
        cout << min(n, ans+2*flip) << endl;
    }
    
    return 0;
}