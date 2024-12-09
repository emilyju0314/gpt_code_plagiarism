#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;

    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    vector<int> X(Q);
    for (int i = 0; i < Q; i++) {
        cin >> X[i];
    }

    vector<int> ans(Q);

    for (int i = 1; i < N; i++) {
        A[i] = min(A[i], A[i - 1]);
    }

    for (int i = 0; i < Q; i++) {
        int index = lower_bound(A.begin(), A.end(), X[i]) - A.begin();
        int sum = 0;
        if (index == 0) {
            sum = A[N - 1];
        } else if (index == N) {
            sum = A[N - 1] + X[i];
        } else {
            sum = A[N - 1] + X[i] - A[index - 1];
        }
        ans[i] = sum;
    }

    for (int i = 0; i < Q; i++) {
        cout << ans[i] << endl;
    }

    return 0;
}