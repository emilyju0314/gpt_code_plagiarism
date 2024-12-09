#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

bool check(vector<pair<int, int>>& bird_habitats, int k, double radius) {
    int count = 0;
    for (auto habitat : bird_habitats) {
        double dist = sqrt(habitat.first * habitat.first + habitat.second * habitat.second);
        if (dist <= radius) {
            count++;
        }
    }
    return count >= k;
}

double findMinimumRadius(vector<pair<int, int>>& bird_habitats, int k) {
    double low = 0, high = 2e5;
    for (int i = 0; i < 100; i++) {
        double mid = (low + high) / 2.0;
        if (check(bird_habitats, k, mid)) {
            high = mid;
        } else {
            low = mid;
        }
    }
    return low;
}

int main() {
    int n, k;
    cin >> n >> k;
    
    vector<pair<int, int>> bird_habitats(n);
    for (int i = 0; i < n; i++) {
        cin >> bird_habitats[i].first >> bird_habitats[i].second;
    }
    
    double min_radius = findMinimumRadius(bird_habitats, k);
    cout << fixed;
    cout.precision(10);
    cout << min_radius << endl;
    
    return 0;
}