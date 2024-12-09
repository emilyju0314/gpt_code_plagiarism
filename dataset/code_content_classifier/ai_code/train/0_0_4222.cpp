#include <iostream>
#include <cmath>

int main() {
    long long N;
    std::cin >> N;

    long long ans = 0;
    for(long long i = 2; i <= N; ++i) {
        ans += i - 1;
    }

    std::cout << ans << std::endl;

    return 0;
}