#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

bool checkFeasibility(double radius, int k, const vector<pair<int, int>>& habitats) {
    vector<double> distances;
    for(auto& habitat : habitats) {
        double distance = sqrt(habitat.first * habitat.first + habitat.second * habitat.second);
        distances.push_back(distance - radius);
    }
    sort(distances.begin(), distances.end());
    
    double sum = 0;
    for(int i = 0; i < k; i++) {
        sum += distances[i];
    }
    
    return sum <= 0;
}

double findMinimumRadius(int n, int k, const vector<pair<int, int>>& habitats) {
    double low = 0, high = 2e5;
    while(high - low > 1e-6) {
        double mid = (low + high) / 2;
        if(checkFeasibility(mid, k, habitats)) {
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
    
    vector<pair<int, int>> habitats(n);
    for(int i = 0; i < n; i++) {
        cin >> habitats[i].first >> habitats[i].second;
    }
    
    double minRadius = findMinimumRadius(n, k, habitats);
    cout.precision(10);
    cout << minRadius << endl;
    
    return 0;
}