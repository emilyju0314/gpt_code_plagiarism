#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool canObtainSequence(vector<int>& sequence, vector<int>& desired, int k) {
    int ptr = 0;
    
    for (int i = 0; i < desired.size(); i++) {
        while (ptr < sequence.size() && sequence[ptr] < desired[i]) {
            ptr++;
        }
        
        if (sequence[ptr] != desired[i]) {
            int cnt = 0;
            while (ptr < sequence.size() && sequence[ptr] <= desired[i] + (k - 1)/2) {
                cnt++;
                ptr++;
            }
            if (cnt < k) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int t;
    cin >> t;
    
    while(t--) {
        int n, k, m;
        cin >> n >> k >> m;
        
        vector<int> sequence(n);
        for (int i = 0; i < n; i++) {
            sequence[i] = i + 1;
        }
        
        vector<int> desired(m);
        for (int i = 0; i < m; i++) {
            cin >> desired[i];
        }
        
        if (canObtainSequence(sequence, desired, k)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    
    return 0;
}