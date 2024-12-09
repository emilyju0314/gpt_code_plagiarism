#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> distances(N, vector<int>(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> distances[i][j];
        }
    }

    // Sort the distances for each familiar
    for (int i = 0; i < N; i++) {
        sort(distances[i].begin(), distances[i].end());
    }

    // Calculate the maximum difference in the number of visiting demons per familiar
    int max_difference = 0;
    int min_visits = distances[0][M-1];
    int max_visits = distances[N-1][0];
    max_difference = max_visits - min_visits;

    // Calculate the maximum distance between the demon and the familiar in charge
    int max_distance = 0;
    for (int j = 0; j < M; j++) {
        int max_familiar_distance = 0;
        for (int i = 0; i < N; i++) {
            max_familiar_distance = max(max_familiar_distance, distances[i][j]);
        }
        max_distance = max(max_distance, max_familiar_distance);
    }

    cout << max_difference << endl;
    cout << max_distance << endl;

    return 0;
}