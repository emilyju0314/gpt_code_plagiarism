#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

double distanceToOrigin(int x, int y) {
    return sqrt(x*x + y*y);
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<double> distances;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        distances.push_back(distanceToOrigin(x, y));
    }

    vector<double> pairDistances;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            double dist = fabs(distances[i] - distances[j]) / sqrt(1 + pow((distances[i] * distances[j]) / (distances[i] + distances[j]), 2));
            pairDistances.push_back(dist);
        }
    }

    sort(pairDistances.begin(), pairDistances.end());

    cout << fixed;
    cout.precision(9);
    cout << pairDistances[k-1] << endl;

    return 0;
}