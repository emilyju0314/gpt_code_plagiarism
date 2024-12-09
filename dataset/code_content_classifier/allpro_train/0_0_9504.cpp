#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

long long f(long long x, long long m) {
    return x % m;
}

int main() {
    long long N, X, M;
    cin >> N >> X >> M;

    vector<long long> A; // to store the sequence A
    unordered_map<long long, long long> index; // to store the start index of the cycle

    long long total_sum = 0, cycle_sum = 0, cycle_length = 0, non_cycle_sum = 0;

    while (N > 0) {
        if (index.find(X) != index.end()) {
            cycle_length = A.size() - index[X];
            cycle_sum = total_sum - non_cycle_sum;
            break;
        }

        A.push_back(X);
        index[X] = A.size() - 1;
        total_sum += X;

        X = f(X * X, M);

        N--;
    }

    if (N > 0) {
        non_cycle_sum = total_sum - cycle_sum;
        total_sum = non_cycle_sum + (N / cycle_length) * cycle_sum;

        N %= cycle_length;

        for (int i = 0; i < N; i++) {
            total_sum += A[i];
        }
    }

    cout << total_sum << endl;

    return 0;
}