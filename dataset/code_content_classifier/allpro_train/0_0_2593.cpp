#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> x(n), y(n), r(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i] >> r[i];
    }
    
    vector<vector<double>> dist(n, vector<double>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dist[i][j] = sqrt(pow(x[i] - x[j], 2) + pow(y[i] - y[j], 2)) - r[i] - r[j];
            if (dist[i][j] < 0) {
                dist[i][j] = 0;
            }
        }
    }
    
    double max_dist = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            max_dist = max(max_dist, dist[i][j]);
        }
    }
    
    int result;
    if (max_dist == 0) {
        result = n;
    } else {
        result = n - 1;
    }
    
    cout << result << endl;
    
    return 0;
}