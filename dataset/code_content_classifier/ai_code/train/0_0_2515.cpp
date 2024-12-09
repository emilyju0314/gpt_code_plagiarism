#include <iostream>
#include <vector>

#define MOD 65537

using namespace std;

void restoreSequence(int N, int K, vector<int> B) {
    vector< vector<int> > A(N+1, vector<int>(N+1, 0));

    for(int j = 1; j <= N; j++) {
        A[N][j] = B[j-1];
    }

    for(int i = N-1; i >= 1; i--) {
        for(int j = 1; j <= i; j++) {
            A[i][j] = (K * A[i+1][j] + A[i+1][j+1]) % MOD;
        }
    }

    for(int i = 1; i <= N; i++) {
        cout << A[1][i] << " ";
    }
    cout << "\n";
}

int main() {
    int T;
    cin >> T;

    for(int t = 0; t < T; t++) {
        int N, K;
        cin >> N >> K;
        
        vector<int> B(N);
        for(int i = 0; i < N; i++) {
            cin >> B[i];
        }

        restoreSequence(N, K, B);
    }

    return 0;
}