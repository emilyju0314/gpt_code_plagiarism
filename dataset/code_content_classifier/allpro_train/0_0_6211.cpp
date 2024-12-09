#include <iostream>
#include <vector>
#include <algorithm>

#define MOD 1000000007

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<long long> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    long long factorial = 1;
    long long totalCost = 0;
    long long sumWeight = 0;

    for(int i = 0; i < N; i++) {
        sumWeight = (sumWeight + A[i]) % MOD;
        factorial = (factorial * (i + 1)) % MOD;
        totalCost = (totalCost + (factorial * sumWeight) % MOD) % MOD;
    }

    cout << totalCost << endl;

    return 0;
}