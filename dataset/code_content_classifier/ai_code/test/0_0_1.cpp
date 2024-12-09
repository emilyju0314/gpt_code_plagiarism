#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

const double EPS = 1e-9;

bool check(const vector<pair<int, int>>& habitats, int n, int k, double r) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        double dist = sqrt(habitats[i].first * habitats[i].first + habitats[i].second * habitats[i].second);
        if (dist - r <= EPS) {
            count++;
        }
    }
    return count >= k;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<pair<int, int>> habitats(n);
    for (int i = 0; i < n; i++) {
        cin >> habitats[i].first >> habitats[i].second;
    }

    double low = 0, high = 2e5;
    while (high - low > EPS) {
        double mid = (low + high) / 2;
        if (check(habitats, n, k, mid)) {
            high = mid;
        } else {
            low = mid;
        }
    }

    cout << fixed;
    cout.precision(10);
    cout << low << endl;

    return 0;
}