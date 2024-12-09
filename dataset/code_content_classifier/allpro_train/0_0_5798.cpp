#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

const double EPS = 1e-9;

bool checkDistance(vector<pair<int, int>>& stores, vector<pair<int, int>>& factories, int n, int m, double maxDist) {
    vector<vector<double>> distances(n, vector<double>(m, 0));
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            distances[i][j] = sqrt(pow(stores[i].first - factories[j].first, 2) + pow(stores[i].second - factories[j].second, 2));
        }
    }
    
    vector<double> minDist(n, 1e9);
    vector<bool> visited(m, false);
    
    for(int i = 0; i < n; i++) {
        minDist[i] = 1e9;
        for(int j = 0; j < m; j++) {
            if(distances[i][j] - maxDist <= EPS && !visited[j]) {
                visited[j] = true;
                minDist[i] = min(minDist[i], distances[i][j]);
            }
        }
    }
    
    double totalDist = 0.0;
    for(int i = 0; i < n; i++) {
        totalDist += minDist[i];
    }
    
    return totalDist - maxDist <= EPS;
}

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<pair<int, int>> stores(n), factories(m);
    
    for(int i = 0; i < n; i++) {
        cin >> stores[i].first >> stores[i].second;
    }
    
    for(int i = 0; i < m; i++) {
        cin >> factories[i].first >> factories[i].second;
    }
    
    double left = 0.0, right = 1e9;

    for(int i = 0; i < 100; i++) {
        double mid = (left + right) / 2;

        if(checkDistance(stores, factories, n, m, mid)) {
            right = mid;
        } else {
            left = mid;
        }
    }

    cout.precision(10);
    cout << fixed << left << endl;

    return 0;
}