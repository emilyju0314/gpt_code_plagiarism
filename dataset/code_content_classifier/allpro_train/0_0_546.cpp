#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, p;
vector<int> d;
vector<pair<int, int>> cats;

bool check(long long time) {
    vector<long long> feeders(p, 0);
    int catIdx = 0;
    
    for (int i = 0; i < p; i++) {
        long long currTime = time;
        while (catIdx < m && currTime >= abs(feeders[i] - cats[catIdx].first) + cats[catIdx].second) {
            currTime -= abs(feeders[i] - cats[catIdx].first) + cats[catIdx].second;
            catIdx++;
        }
        
        if (catIdx == m) {
            return true;
        }
        
        feeders[i] += time;
    }
    
    return false;
}

int main() {
    cin >> n >> m >> p;
    d.resize(n - 1);
    
    for (int i = 0; i < n - 1; i++) {
        cin >> d[i];
    }
    
    for (int i = 0; i < m; i++) {
        int hi, ti;
        cin >> hi >> ti;
        cats.push_back({hi, ti});
    }
    
    sort(cats.begin(), cats.end(), [](pair<int, int>& a, pair<int, int>& b) {
        return a.second < b.second;
    });
    
    long long left = 0, right = 1e18, ans = 0;
    while (left <= right) {
        long long mid = left + (right - left) / 2;
        
        if (check(mid)) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    
    cout << ans << endl;
    
    return 0;
}