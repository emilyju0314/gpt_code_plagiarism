#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long solve(vector<pair<int, int>>& fence) {
    long long min_cost = 0;
    
    for (int i = 1; i < fence.size(); i++) {
        if (fence[i].first <= fence[i-1].first) {
            int diff = fence[i-1].first - fence[i].first + 1;
            min_cost += diff * fence[i].second;
            fence[i].first += diff;
        }
    }
    
    return min_cost;
}

int main() {
    int q;
    cin >> q;
    
    while (q--) {
        int n;
        cin >> n;
        
        vector<pair<int, int>> fence(n);
        for (int i = 0; i < n; i++) {
            cin >> fence[i].first >> fence[i].second;
        }
        
        long long result = solve(fence);
        cout << result << endl;
    }
    
    return 0;
}