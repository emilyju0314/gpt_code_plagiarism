#include <iostream>
#include <algorithm>

using namespace std;

long long find_min_coins(long long N, long long M, long long K, long long L) {
    if(M * N < K + L) {
        return -1;
    }

    long long groups = (K + L + M - 1) / M;
    long long remaining_gifts = groups * M - K - L;
    long long ans = (N - K + M - 1) / M;

    if(ans >= groups) {
        return -1;
    }

    return max(0LL, groups - ans);
}

int main() {
    long long N, M, K, L;
    cin >> N >> M >> K >> L;

    long long min_coins = find_min_coins(N, M, K, L);
    
    cout << min_coins << endl;

    return 0;
}