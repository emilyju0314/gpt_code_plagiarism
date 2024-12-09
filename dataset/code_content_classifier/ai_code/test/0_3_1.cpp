#include<bits/stdc++.h>
using namespace std;

const double EPS = 1e-9;

double dist(double x1, double y1, double x2, double y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

bool check(double r, int k, vector<pair<double, double>>& habitats) {
    int count = 0;
    for (auto& habitat : habitats) {
        if (dist(0, 0, habitat.first, habitat.second) - r <= EPS)
            count++;
    }
    return count >= k;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<pair<double, double>> habitats(n);
    for (int i = 0; i < n; i++) {
        cin >> habitats[i].first >> habitats[i].second;
    }

    double low = 0, high = 2e5;
    while (high - low > EPS) {
        double mid = (low + high) / 2;
        if (check(mid, k, habitats)) {
            high = mid;
        } else {
            low = mid;
        }
    }

    cout << fixed << setprecision(10) << high << endl;

    return 0;
}