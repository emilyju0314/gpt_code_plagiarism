#include <iostream>
#include <vector>

using namespace std;

int main() {
    int L, R;
    cin >> L >> R;
    
    // Check if it is possible to find a (L, R)-continuous city with at most 32 blocks
    if (R > (1 << 16)) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        int n = 2;
        int m = 1;
        vector<pair<int, int>> roads;
        
        while (n <= 32 && (1 << n) - 1 <= R) {
            roads.push_back({n-1, n});
            m++;
            n++;
        }
        
        cout << n << " " << m << endl;
        for (auto road : roads) {
            cout << road.first << " " << road.second << " " << L << endl;
        }
    }
    
    return 0;
}