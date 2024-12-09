#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<int> mood(n);
    for (int i = 0; i < n; i++) {
        cin >> mood[i];
    }
    
    int max_happiness = 0;
    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        
        int happiness = 0;
        for (int j = l - 1; j < r; j++) {
            happiness += mood[j];
        }
        
        if (happiness > 0) {
            max_happiness += happiness;
        }
    }
    
    cout << max_happiness << endl;
    
    return 0;
}