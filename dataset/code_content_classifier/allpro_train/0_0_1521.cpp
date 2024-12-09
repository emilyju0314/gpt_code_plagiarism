#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int MOD = 1e9 + 7;

long long computeArea(const vector<pair<int,int>>& points) {
    long long area = 0;
    int n = points.size();
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        area += (long long) points[i].first * points[j].second - (long long) points[j].first * points[i].second;
    }
    return abs(area) / 2;
}

int main() {
    int n;
    cin >> n;
    
    vector<pair<int,int>> points(n);
    for (int i = 0; i < n; i++) {
        cin >> points[i].first >> points[i].second;
    }
    
    long long totalArea = computeArea(points);

    long long disappointment = 0;
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        disappointment += abs((points[i].first * points[j].second - points[j].first * points[i].second) * 2) % MOD;
    }

    long long sumDisappointment = (disappointment * (n-3) * (totalArea/2)) % MOD;
    cout << sumDisappointment << endl;

    return 0;
}