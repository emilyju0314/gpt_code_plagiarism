#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int minChanges(string s, string u) {
    int n = s.length();
    int m = u.length();
    int minChanges = m;
    
    for (int i = 0; i <= n - m; ++i) {
        int changes = 0;
        for (int j = 0; j < m; ++j) {
            if (s[i+j] != u[j]) {
                changes++;
            }
        }
        minChanges = min(minChanges, changes);
    }
    
    return minChanges;
}

int main() {
    string s, u;
    cin >> s >> u;
    
    int result = minChanges(s, u);
    
    cout << result << endl;
    
    return 0;
}