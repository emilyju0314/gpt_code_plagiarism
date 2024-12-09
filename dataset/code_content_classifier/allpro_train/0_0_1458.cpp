#include <iostream>

int main() {
    long long K, A, B;
    std::cin >> K >> A >> B;

    if (A >= K) {
        std::cout << 1 << std::endl;
    } else if (A <= B) {
        std::cout << -1 << std::endl;
    } else {
        long long diff = A - B;
        long long cnt = 2; // Starting from the second contest
        long long rating = A;
        while (true) {
            if (rating >= K) {
                std::cout << cnt << std::endl;
                break;
            }
            rating += diff;
            cnt++;
        }
    }

    return 0;
}