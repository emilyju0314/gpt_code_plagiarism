#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

double calculateDistance(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

int main() {
    int N;
    cin >> N;

    vector<pair<int, int>> holes(N);
    for (int i = 0; i < N; i++) {
        cin >> holes[i].first >> holes[i].second;
    }

    const long double R = pow(10, pow(10, pow(10, 10)));

    vector<double> probabilities(N);

    for (int i = 0; i < N; i++) {
        double area = 0;
        for (int j = 0; j < N; j++) {
            if (j == i) continue;
            double distance = calculateDistance(holes[i].first, holes[i].second, holes[j].first, holes[j].second);
            double angle = 2 * asin(distance / (2 * R));
            area += 0.5 * pow(distance, 2) * (angle - sin(angle));
        }
        probabilities[i] = 1 - area / (M_PI * pow(R, 2));
    }

    cout.precision(17);
    for (int i = 0; i < N; i++) {
        cout << probabilities[i] << endl;
    }

    return 0;
}