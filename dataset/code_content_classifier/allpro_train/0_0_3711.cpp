#include <iostream>
#include <vector>

#define MOD 1000000007

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<long long> A(N);
    vector<long long> B(N);

    // Input the values for A and B
    for (int i = 0; i < N; i++) {
        cin >> A[i] >> B[i];
    }

    long long total_ways = 1;

    for (int i = 0; i < N; i++) {
        total_ways = (total_ways * (A[i] + B[i])) % MOD;
    }

    // Subtracting 1 as we need to remove the scenario where both skewers have only beef or only green peppers
    total_ways = (total_ways - 1 + MOD) % MOD;

    // Multiply the total_ways by 2 as we can choose the skewers in two ways (skewer 1 - skewer 2) or (skewer 2 - skewer 1)
    total_ways = (total_ways * 2) % MOD;

    cout << total_ways << endl;

    return 0;
}