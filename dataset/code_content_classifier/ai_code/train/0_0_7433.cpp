#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, Q, S, T;
    cin >> N >> Q >> S >> T;

    vector<int> A(N+1);
    for (int i = 0; i <= N; i++) {
        cin >> A[i];
    }

    int temperature = 0;
    for (int i = 0; i < N; i++) {
        if (A[i] < A[i+1]) {
            temperature -= S * (A[i+1] - A[i]);
        } else {
            temperature += T * (A[i] - A[i+1]);
        }
    }

    for (int i = 0; i < Q; i++) {
        int L, R, X;
        cin >> L >> R >> X;

        if (A[L-1] < A[L]) {
            temperature += S * (min(A[L] + X, A[R]) - A[L]);
        } else {
            temperature += T * (A[L] - max(A[L] - X, A[R]));
        }

        if (R < N) {
            if (A[R] < A[R+1]) {
                temperature -= S * (A[R+1] - min(A[L] + X, A[R]));
            } else {
                temperature += T * (max(A[L] - X, A[R]) - A[R]);
            }
        }

        A[L] += X;
        if (R < N) A[R+1] -= X;

        cout << temperature << endl;
    }

    return 0;
}