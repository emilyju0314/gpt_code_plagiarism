#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> A(M);
    for (int i = 0; i < M; i++) {
        cin >> A[i];
    }

    string ans;
    while (N > 0) {
        int max_matchsticks = 0;
        int max_digit = 0;

        for (int i = 0; i < M; i++) {
            if (max_matchsticks < N / A[i] * A[i] && N / A[i] >= 1) {
                max_matchsticks = N / A[i] * A[i];
                max_digit = A[i];
            }
        }

        N -= max_matchsticks;
        ans += to_string(max_digit);
    }

    cout << ans << endl;

    return 0;
}