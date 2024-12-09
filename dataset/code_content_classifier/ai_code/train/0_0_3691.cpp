#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<pair<int, int>> points(N);
    for (int i = 0; i < N; i++) {
        cin >> points[i].first >> points[i].second;
    }

    long long sumOfDistances = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            long long distance = pow(points[i].first - points[j].first, 2) + pow(points[i].second - points[j].second, 2);
            sumOfDistances += distance;
        }
    }

    cout << sumOfDistances << endl;

    return 0;
}