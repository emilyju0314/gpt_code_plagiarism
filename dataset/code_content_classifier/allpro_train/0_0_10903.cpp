#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minStrokes(int n, int k, string s, string t) {
    vector<int> diff(n, 0);
    int count = (s[0] != t[0] ? 1 : 0);
    diff[0] = count;
    
    for(int i = 1; i < n; i++) {
        count += (s[i] != t[i] ? 1 : 0);
        diff[i] = count;
        if(i >= k) {
            count -= (s[i-k] != t[i-k] ? 1 : 0);
        }
    }
    
    int minStrokes = diff[n-1];
    for(int i = 0; i < n - k + 1; i++) {
        minStrokes = min(minStrokes, diff[i] + (i > 0 ? i : 0) + (diff[n-1] - diff[i+k-1]));
    }
    
    return minStrokes;
}

int main() {
    int n, k;
    string s, t;
    
    cin >> n >> k;
    cin >> s >> t;
    
    cout << minStrokes(n, k, s, t) << endl;
    
    return 0;
}