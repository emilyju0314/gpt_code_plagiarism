#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int factorial(int n) {
    return (n == 1 || n == 0) ? 1 : n * factorial(n - 1);
}

bool isValidDistanceMatrix(vector<int>& distances, int N, vector<vector<int>>& distanceMatrix) {
    int idx = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            if (distanceMatrix[i][j] != distances[idx]) {
                return false;
            }
            idx++;
        }
    }
    return true;
}

void printDistances(vector<int>& dist) {
    for (int i = 0; i < dist.size(); ++i) {
        cout << dist[i] << " ";
    }
    cout << endl;
}

int main() {
    int N;
    while (true) {
        cin >> N;
        if (N == 0) {
            break;
        }

        vector<int> distances(N * (N - 1) / 2);
        for (int i = 0; i < N * (N - 1) / 2; ++i) {
            cin >> distances[i];
        }

        sort(distances.begin(), distances.end(), greater<int>());

        do {
            vector<vector<int>> distanceMatrix(N, vector<int>(N, 0));

            // Calculate distance matrix using the current permutation
            for (int i = 0; i < N; ++i) {
                for (int j = i + 1; j < N; ++j) {
                    if (i == 0 && j == N - 1) {
                        distanceMatrix[i][j] = distances.back();
                    } else {
                        distanceMatrix[i][j] = abs(dist[i] - dist[j]);
                    }
                    distances.pop_back();
                }
            }

            // Check if the distance matrix matches the input distances
            if (isValidDistanceMatrix(distances, N, distanceMatrix)) {
                for (int i = 0; i < N - 1; ++i) {
                    printDistances(distanceMatrix[0]);
                }
                cout << "-----" << endl;
            }

        } while (next_permutation(dist.begin(), dist.end()));

    }

    return 0;
}