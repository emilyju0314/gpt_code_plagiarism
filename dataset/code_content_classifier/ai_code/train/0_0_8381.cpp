#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    long long sum = 0;
    int min_abs = INT_MAX;
    int negative_count = 0;

    for (int i = 0; i < N; i++) {
        sum += abs(A[i]);
        if (A[i] < 0) {
            negative_count++;
        }
        min_abs = min(min_abs, abs(A[i]));
    }

    if (negative_count % 2 == 1) {
        sum -= 2 * min_abs;
    }

    cout << sum << endl;

    return 0;
}