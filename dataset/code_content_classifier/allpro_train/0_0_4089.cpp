#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    string s;
    cin >> s;
    
    vector<int> sets(n, 0);
    vector<int> prefix_counts(n, 0);
    
    int count = 1;
    for(int i = 1; i < n; i++) {
        if (s[i] == s[i-1] && s[i] != '?') {
            count++;
        } else {
            sets[count]++;
            count = 1;
        }
    }
    
    count = 0;
    for(int i = n-1; i >= 0; i--) {
        if (s[i] != '?') {
            count++;
        }
        prefix_counts[i] = count;
    }
    
    for(int i = 1; i <= n; i++) {
        int ans = 0;
        for(int j = 0; j < n; j++) {
            int length = prefix_counts[min(n-1, j + i - 1)] - j;
            ans += min(length, sets[i]);
            j += length - 1;
        }
        cout << ans << " ";
    }
    
    return 0;
}