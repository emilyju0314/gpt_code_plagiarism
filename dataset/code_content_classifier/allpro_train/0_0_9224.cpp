#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int longest_alternating_subsequence(int n, string& s) {
    int result = 1;
    
    int prev = 1;
    
    for(int i=1; i<n; i++) {
        if(s[i] != s[i-1]) {
            prev++;
        } else {
            result = max(result, prev);
            prev = 1;
        }
    }
    
    result = max(result, prev);
    
    return min(result+2, n);
}

int main() {
    int n;
    cin >> n;
    
    string s;
    cin >> s;
    
    int answer = longest_alternating_subsequence(n, s);
    
    cout << answer << endl;
    
    return 0;
}