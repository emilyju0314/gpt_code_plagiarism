#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<pair<int, int>> pairs(m);
    for(int i = 0; i < m; i++) {
        cin >> pairs[i].first >> pairs[i].second;
    }
    
    for(int x = 1; x < n; x++) {
        for(int y = x + 1; y <= n; y++) {
            bool valid = true;
            for(int i = 0; i < m; i++) {
                if(pairs[i].first != x && pairs[i].first != y && pairs[i].second != x && pairs[i].second != y) {
                    valid = false;
                    break;
                }
            }
            if(valid) {
                cout << "YES" << endl;
                return 0;
            }
        }
    }
    
    cout << "NO" << endl;
    
    return 0;
}