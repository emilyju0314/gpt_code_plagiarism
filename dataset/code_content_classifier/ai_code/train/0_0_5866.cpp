#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    sort(A.begin(), A.end());

    int result = INT_MAX;

    for(int i = 1; i < N - 2; i++) {
        int P = accumulate(A.begin(), A.begin() + i, 0);
        int Q = accumulate(A.begin() + i, A.begin() + i + 1, 0);
        int R = accumulate(A.begin() + i + 1, A.begin() + N - 1, 0);
        int S = accumulate(A.begin() + N - 1, A.end(), 0);

        result = min(result, max({P, Q, R, S}) - min({P, Q, R, S}));
    }

    cout << result << endl;

    return 0;
}