#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

bool check(const vector<pair<int, int>>& habitats, double radius, int k) {
    int count = 0;
    for(const auto& habitat : habitats) {
        double distance = sqrt(habitat.first * habitat.first + habitat.second * habitat.second);
        if(distance <= radius) {
            count++;
        }
    }
    return count >= k;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<pair<int, int>> habitats(n);
    for(int i = 0; i < n; i++) {
        cin >> habitats[i].first >> habitats[i].second;
    }

    double left = 0, right = 2e5;
    const double eps = 1e-7;
    while(right - left > eps) {
        double mid = (left + right) / 2;
        if(check(habitats, mid, k)) {
            right = mid;
        } else {
            left = mid;
        }
    }

    cout << fixed;
    cout.precision(10);
    cout << right << endl;

    return 0;
}