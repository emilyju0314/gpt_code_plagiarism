#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    int prev_difficulty = 0;
    
    unordered_map<int, int> freq;
    unordered_map<int, int> changes;
    
    for (int i = 1; i < n; i++) {
        if (a[i] != a[i-1]) {
            prev_difficulty++;
        }
        freq[a[i-1]]++;
    }
    freq[a[n-1]]++;
    
    cout << prev_difficulty << endl;
    
    while (q--) {
        int idx, val;
        cin >> idx >> val;
        idx--;
        
        int old_val = a[idx];
        int new_val = val;
        
        if (changes.count(old_val) > 0) {
            old_val = changes[old_val];
        }
        
        if (changes.count(new_val) > 0) {
            new_val = changes[new_val];
        }
        
        if (old_val == new_val) {
            cout << prev_difficulty << endl;
            continue;
        }
        
        int cnt = freq[old_val];
        freq[old_val] = 0;
        prev_difficulty -= (cnt - 1);
        
        if (freq[new_val] == 0) {
            prev_difficulty++;
        }
        freq[new_val] += cnt;
        
        a[idx] = val;
        changes[old_val] = new_val;
        
        cout << prev_difficulty << endl;
    }
    
    return 0;
}