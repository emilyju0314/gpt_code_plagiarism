#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<double>> vectors(M, vector<double>(N));
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++) {
            cin >> vectors[i][j];
        }
    }

    double result = 0.0;
    for(int i = 0; i < M; i++) {
        double min_dist = 2.0;
        for(int j = 0; j < i; j++) {
            double dist = 0.0;
            for(int k = 0; k < N; k++) {
                dist += pow(vectors[i][k] - vectors[j][k], 2);
            }
            min_dist = min(min_dist, dist);
        }
        result += min_dist;
    }

    cout << result << endl;

    return 0;
}