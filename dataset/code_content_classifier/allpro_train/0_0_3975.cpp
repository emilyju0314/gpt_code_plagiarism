#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 1120;
const int MAX_K = 14;

bool is_prime[MAX_N + 1];
vector<int> primes;

void initialize_primes() {
    fill(is_prime, is_prime + MAX_N + 1, true);
    
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= MAX_N; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= MAX_N; j += i) {
                is_prime[j] = false;
            }
        }
    }
    
    for (int i = 2; i <= MAX_N; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
        }
    }
}

int count_ways(int n, int k) {
    vector<vector<int>> dp(n + 1, vector<int>(k + 1));
    
    dp[0][0] = 1;
    for (int p : primes) {
        if (p > n) break;
        for (int i = n; i >= p; i--) {
            for (int j = k; j >= 1; j--) {
                dp[i][j] += dp[i - p][j - 1];
            }
        }
    }
    
    return dp[n][k];
}

int main() {
    initialize_primes();
    
    int n, k;
    while (cin >> n >> k && n != 0 && k != 0) {
        cout << count_ways(n, k) << endl;
    }
    
    return 0;
}