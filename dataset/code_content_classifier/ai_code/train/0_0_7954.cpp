#include <iostream>
#include <vector>

using namespace std;

const long long MOD = 1000000007;

long long factorial(int n) {
    long long result = 1;
    for (int i = 1; i <= n; i++) {
        result = (result * i) % MOD;
    }
    return result;
}

int main() {
    int N, R;
    while (true) {
        cin >> N;
        if (N == 0) break;
        
        cin >> R;
        
        vector<int> swaps(N + 1);
        for (int i = 1; i <= N; i++) {
            swaps[i] = i;
        }
        
        for (int i = 0; i < R; i++) {
            int s, t;
            cin >> s >> t;
            swap(swaps[s], swaps[t]);
        }
        
        long long result = 0;
        for (int i = 1; i <= N; i++) {
            long long mult = swaps[i] - 1;
            long long factorialRes = factorial(N - i);
            result = (result + mult * factorialRes) % MOD;
        }
        
        cout << result << endl;
    }
    
    return 0;
}