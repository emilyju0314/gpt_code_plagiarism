#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    long long N, K;
    cin >> N >> K;

    while (N >= K) {
        N = min(N % K, abs(N - K));
    }

    cout << N << endl;

    return 0;
}