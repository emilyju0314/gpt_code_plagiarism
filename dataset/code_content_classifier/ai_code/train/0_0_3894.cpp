#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<vector<int>> grid(N, vector<int>(N));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> grid[i][j];
        }
    }

    vector<double> distances; 
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                for (int l = 0; l < N; l++) {
                    double dist = sqrt(pow(i - k, 2) + pow(j - l, 2));
                    distances.push_back(dist);
                }
            }
        }
    }

    sort(distances.begin(), distances.end());

    double total_dist = 0;
    for (double dist : distances) {
        total_dist += dist;
    }

    double average_dist = total_dist / (N * N * (N * N - 1));

    cout << setprecision(10) << average_dist << endl;

    int count = 1;
    double prev_dist = distances[0];
    for (int i = 1; i < distances.size(); i++) {
        if (distances[i] == prev_dist) {
            count++;
        } else {
            cout << fixed << setprecision(0) << prev_dist << " " << count << endl;
            prev_dist = distances[i];
            count = 1;
        }
    }

    return 0;
}