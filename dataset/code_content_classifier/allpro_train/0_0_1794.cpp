#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int N;
    cin >> N;
    
    vector<long long> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    
    long long sum = 0;
    long long total = 0;
    
    for (int i = 0; i < N; i++) {
        total += A[i];
        total %= MOD;
    }
    
    for (int i = 0; i < N; i++) {
        sum += ((total - A[i] + MOD) * A[i]) % MOD;
        sum %= MOD;
    }
    
    cout << sum << endl;
    
    return 0;
}