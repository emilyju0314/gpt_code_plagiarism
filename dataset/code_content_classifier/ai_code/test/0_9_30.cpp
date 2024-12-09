#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int minErasedSymbolsToMakePalindrome(int n, string s) {
    unordered_map<char, vector<int>> positions;
    for (int i = 0; i < n; i++) {
        positions[s[i]].push_back(i);
    }
    
    int ans = n;
    for (auto& it : positions) {
        vector<int> &pos = it.second;
        int l = 0, r = pos.size() - 1;
        int tmp = 0;
        while (l < r) {
            tmp += pos[r] - pos[l] - (r - l);
            l++;
            r--;
        }
        ans = min(ans, tmp);
    }
    
    return (ans == n) ? -1 : ans;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        
        cout << minErasedSymbolsToMakePalindrome(n, s) << endl;
    }
    
    return 0;
}