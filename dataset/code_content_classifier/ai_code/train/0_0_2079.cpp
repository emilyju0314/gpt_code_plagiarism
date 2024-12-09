#include <iostream>

typedef long long ll;

int main() {
    ll N, K;
    std::cin >> N >> K;

    ll ans = K / N;
    if(N > 1) {
        ans = std::min(ans, K - (N - 1));
    }

    std::cout << ans << std::endl;

    return 0;
}