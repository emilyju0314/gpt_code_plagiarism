#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;
    
    while(t--) {
        int n, m;
        cin >> n >> m;
        
        int balance = 0;
        vector<pair<int, int>> dishes(n);
        for (int i = 0; i < n; i++) {
            cin >> dishes[i].first >> dishes[i].second;
            balance += dishes[i].first - dishes[i].second;
        }
        
        cout << abs(balance) << endl;
        for (int i = 0; i < n; i++) {
            int x = min(dishes[i].first, m);
            int y = m - x;
            cout << x << " " << y << endl;
        }
    }
    
    return 0;
}