#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int N, D;
    cin >> N >> D;

    vector<vector<int>> points(N, vector<int>(D));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < D; j++) {
            cin >> points[i][j];
        }
    }

    int pairs = 0;

    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            int distance = 0;
            for (int k = 0; k < D; k++) {
                distance += pow(points[i][k] - points[j][k], 2);
            }
            int sqrt_distance = sqrt(distance);
            if (sqrt_distance * sqrt_distance == distance) {
                pairs++;
            }
        }
    }

    cout << pairs << endl;

    return 0;
}