#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, D;
    cin >> N >> D;

    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    long long total_cost = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            total_cost += abs(i - j) * D + A[i] + A[j];
        }
    }

    cout << total_cost << endl;

    return 0;
}