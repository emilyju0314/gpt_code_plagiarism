#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        string A, B;
        cin >> A >> B;
        
        map<char, vector<int>> mp;
        for (int i = 0; i < n; i++) {
            mp[A[i]].push_back(i);
        }
        
        bool possible = true;
        int moves = 0;
        
        for (int i = 0; i < n; i++) {
            if (A[i] != B[i]) {
                if (mp[B[i]].size() > 0) {
                    A[mp[B[i]].back()] = A[i];
                    mp[A[i]].push_back(mp[B[i]].back());
                    mp[B[i]].pop_back();
                    moves++;
                } else {
                    possible = false;
                    break;
                }
            }
        }
        
        if (possible) {
            cout << moves << endl;
        } else {
            cout << -1 << endl;
        }
    }
    
    return 0;
}