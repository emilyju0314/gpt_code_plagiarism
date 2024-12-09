#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
    int t;
    cin >> t;
    
    while(t--) {
        int n;
        cin >> n;
        
        unordered_set<int> seen;
        bool possible = true;
        
        for(int i = 0; i < n; i++) {
            int ai;
            cin >> ai;
            
            for(int j = 1; j <= 1000000; j++) {
                int bj = j + ai;
                if(seen.count(bj) == 0 && bj <= 1000000) {
                    seen.insert(bj);
                } else if(j == 1000000) {
                    possible = false;
                    break;
                }
            }
        }
        
        if(possible) {
            cout << "YES\n";
            for(int bj : seen)
                cout << bj << " ";
            cout << endl;
        } else {
            cout << "NO\n";
        }
    }
    
    return 0;
}