#include <iostream>
#include <vector>

using namespace std;

int main() {
    long long N;
    cin >> N;

    vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};

    int ans = 0;
    for(int prime : primes) {
        while(N % prime == 0) {
            N /= prime;
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}