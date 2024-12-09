#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    if (N == 2) {
        cout << -1 << endl;
        return 0;
    }

    vector<vector<int>> A(N, vector<int>(N-1));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N-1; j++) {
            A[i][j] = (i+j+1) % N + 1;
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N-1; j++) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}