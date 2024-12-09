#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    string s;
    cin >> s;
    
    int m = s.length();
    
    vector<int> z(2*m);
    s += s;
    
    for (int l = 0, r = 0, i = 1; i < 2*m; i++) {
        if (i <= r) z[i] = min(r-i+1, z[i-l]);
        while (i+z[i] < 2*m && s[z[i]] == s[i+z[i]]) z[i]++;
        if (i+z[i]-1 > r) l = i, r = i+z[i]-1;
    }
    
    vector<int> count_prefix(n);
    for (int i = m; i < 2*m; i++) {
        if (z[i] == m) {
            int start = (i-m) % m;
            count_prefix[start]++;
        }
    }
    
    long long total = 1LL << n;
    long long result = total;
    for (int i = 0; i < m; i++) {
        if (count_prefix[i] > 0) {
            result -= (1LL << (n - count_prefix[i]));
        }
    }
    
    cout << result << endl;
    
    return 0;
}