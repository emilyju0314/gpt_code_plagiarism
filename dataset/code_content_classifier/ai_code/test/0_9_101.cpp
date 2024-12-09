#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string canTransformIntoPermutation(vector<int> a, string colors) {
    int n = a.size();
    vector<int> cnt(n+1, 0);
    
    for (int i = 0; i < n; i++) {
        if (colors[i] == 'B') {
            a[i]--;
        }
        cnt[a[i]]++;
    }
    
    for (int i = 1; i <= n; i++) {
        if (cnt[i] != 1) {
            return "NO";
        }
    }
    
    return "YES";
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        string colors;
        cin >> colors;
        
        cout << canTransformIntoPermutation(a, colors) << endl;
    }
    
    return 0;
}