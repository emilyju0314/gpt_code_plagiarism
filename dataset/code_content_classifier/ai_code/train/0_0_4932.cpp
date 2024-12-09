#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    if (N == 1) {
        cout << "Yes" << endl;
        cout << "1" << endl;
    } else if (N == 2) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;

        vector<vector<int>> A(N, vector<int>(N, 0));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                A[i][j] = (i + j) % N + 1;
            }
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}