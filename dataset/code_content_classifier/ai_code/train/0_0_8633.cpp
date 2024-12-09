#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;

    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    for (int i = 0; i < Q; i++) {
        int T;
        cin >> T;

        if (T == 1) {
            int X, V;
            cin >> X >> V;
            A[X-1] = V;
        } else if (T == 2) {
            int L, R;
            cin >> L >> R;
            int max_val = A[L-1];
            for (int j = L; j < R; j++) {
                max_val = max(max_val, A[j]);
            }
            cout << max_val << endl;
        } else if (T == 3) {
            int X, V;
            cin >> X >> V;
            int j = N + 1;
            for (int k = X-1; k < N; k++) {
                if (A[k] >= V) {
                    j = k+1;
                    break;
                }
            }
            cout << j << endl;
        }
    }

    return 0;
}