#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> X(N, 0);
    vector<int> A(M), B(M);
    for (int i = 0; i < M; i++) {
        cin >> A[i] >> B[i];
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            X[i] += (A[j] + i + 1) % B[j];
        }
    }

    for (int i = 0; i < N; i++) {
        cout << X[i] << endl;
    }

    return 0;
}