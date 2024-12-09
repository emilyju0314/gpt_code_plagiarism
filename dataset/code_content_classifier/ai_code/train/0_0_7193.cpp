#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> tuning(n);
    for (int i = 0; i < n; i++) {
        cin >> tuning[i];
    }
    
    int q;
    cin >> q;
    
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        
        set<int> pitches;
        for (int j = 0; j < n; j++) {
            for (int k = l; k <= r; k++) {
                pitches.insert(tuning[j] + k);
            }
        }
        
        cout << pitches.size() << " ";
    }
    
    cout << endl;

    return 0;
}