#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, Q, L, R;
    cin >> N >> Q >> L >> R;

    vector<long long> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    for (int i = 0; i < Q; i++) {
        int q, x, s, t;
        cin >> q >> x >> s >> t;

        if (q == 1) {
            for (int j = 0; j < N; j++) {
                if (A[j] >= x) {
                    A[j] = t * (A[j] + s);
                }
            }
        } else if (q == 2) {
            for (int j = 0; j < N; j++) {
                if (A[j] <= x) {
                    A[j] = ((A[j] - s) / t);
                }
            }
        }
    }

    int count = 0;
    for (int i = 0; i < N; i++) {
        if (A[i] >= L && A[i] <= R) {
            count++;
        }
    }

    cout << count << endl;

    return 0;
}