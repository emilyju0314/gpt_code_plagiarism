#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    
    vector<pair<int, int>> meats(N);
    vector<int> c(N);
    
    for (int i = 0; i < N; i++) {
        cin >> meats[i].first >> meats[i].second >> c[i];
    }
    
    double left = 0, right = 1e9;
    while (right - left > 1e-6) {
        double mid = (left + right) / 2;
        
        vector<double> times;
        for (int i = 0; i < N; i++) {
            double dist = sqrt(pow(meats[i].first - mid, 2) + pow(meats[i].second - mid, 2));
            times.push_back(dist * c[i]);
        }
        
        sort(times.begin(), times.end());
        
        double sum = 0;
        for (int i = 0; i < K; i++) {
            sum += times[i];
        }
        
        if (sum <= mid) {
            right = mid;
        } else {
            left = mid;
        }
    }
    
    cout << fixed;
    cout << setprecision(7) << left << endl;
    
    return 0;
}