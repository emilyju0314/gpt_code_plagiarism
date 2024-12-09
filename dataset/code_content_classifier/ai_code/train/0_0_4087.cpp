#include <iostream>
#include <vector>

int main() {
    int N, S;
    std::cin >> N >> S;

    if (N == 1) {
        if (S % 2 == 0) {
            std::cout << "YES" << std::endl;
            std::cout << S / 2 << std::endl;
        } else {
            std::cout << "NO" << std::endl;
        }
    } else {
        std::vector<int> arr(N, 1);
        int sum = N;

        while (sum < S) {
            arr[N-1]++;
            sum++;
        }

        std::cout << "YES" << std::endl;
        for (int i = 0; i < N; i++) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
        std::cout << N - 1 << std::endl;
    }

    return 0;
}