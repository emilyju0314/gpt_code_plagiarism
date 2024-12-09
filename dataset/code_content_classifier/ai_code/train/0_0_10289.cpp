#include <iostream>
#include <vector>

#define INF 1000000000

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<vector<int>> A(N, vector<int>(N));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> A[i][j];
        }
    }

    int total_length = 0;
    bool valid = true;

    // Floyd-Warshall algorithm
    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (A[i][j] > A[i][k] + A[k][j]) {
                    valid = false;
                } 
                if (i != j && A[i][j] == A[i][k] + A[k][j]) {
                    total_length += A[i][j];
                }
            }
        }
    }

    if (!valid) {
        cout << -1 << endl;
    } else {
        cout << total_length / 2 << endl;
    }

    return 0;
}