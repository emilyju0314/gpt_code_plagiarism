#include <iostream>
#include <string>
#include <vector>

using namespace std;

int minChanges(string s, int k) {
    string target = "RGB";
    int minChanges = k;
    
    for (int i = 0; i < s.length() - k + 1; i++) {
        for (int j = 0; j < k; j++) {
            int idx = j % 3;
            if (s[i + j] != target[idx]) {
                minChanges--;
            }
        }
    }
    
    return minChanges;
}

int main() {
    int q;
    cin >> q;
    
    vector<int> results;
    
    for (int i = 0; i < q; i++) {
        int n, k;
        cin >> n >> k;
        
        string s;
        cin >> s;
        
        results.push_back(minChanges(s, k));
    }
    
    for (int res : results) {
        cout << res << endl;
    }
    
    return 0;
}