#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

bool check(vector<pair<long long, long long>>& animals, double radius) {
    double left = -1e9, right = 1e9;
    for(auto animal : animals) {
        double x = animal.first, y = animal.second;
        double dist = sqrt(radius * radius - y * y);
        double l = x - dist, r = x + dist;
        left = max(left, l);
        right = min(right, r);
    }
    return left <= right;
}

int main() {
    int n;
    cin >> n;
    
    vector<pair<long long, long long>> animals(n);
    for(int i = 0; i < n; i++) {
        cin >> animals[i].first >> animals[i].second;
    }
    
    sort(animals.begin(), animals.end(), [](pair<long long, long long>& a, pair<long long, long long>& b) {
        return a.second > b.second;
    });
    
    double lo = 0, hi = 1e9;
    for(int i = 0; i < 50; i++) {
        double mid = (lo + hi) / 2;
        if(check(animals, mid)) {
            hi = mid;
        } else {
            lo = mid;
        }
    }
    
    if(hi > 1e8) {
        cout << -1 << endl;
    } else {
        cout.precision(10);
        cout << hi << endl;
    }
    
    return 0;
}