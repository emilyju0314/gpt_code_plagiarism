#include <iostream>
#include <cmath>

int main() {
    long long N;
    std::cin >> N;

    long long sum = 0;
    for(long long m = 1; m*m <= N; m++) {
        if(N % m == 0 && (N/m - 1) % m == 0) {
            sum += m;
            if(m*m != N) {
                sum += N/m;
            }
        }
    }

    std::cout << sum << std::endl;

    return 0;
}