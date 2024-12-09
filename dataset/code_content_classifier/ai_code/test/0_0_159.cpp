#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> sieve(int n) {
    vector<int> isprime(n + 1, true);
    isprime[0] = isprime[1] = false;
    for (int i = 2; i * i <= n; ++i) {
        if (isprime[i]) {
            for (int j = i * i; j <= n; j += i) {
                isprime[j] = false;
            }
        }
    }
    vector<int> primes;
    for (int i = 2; i <= n; ++i) {
        if (isprime[i]) {
            primes.push_back(i);
        }
    }
    return primes;
}

int main() {
    int n;
    cin >> n;
    vector<int> ans;
    vector<int> primes = sieve(n);
    for (int i = 0; i < primes.size(); ++i) {
        int num = primes[i];
        while (num <= n) {
            ans.push_back(num);
            num *= primes[i];
        }
    }
    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << " ";
    }
    cout << "\n";

    return 0;
}