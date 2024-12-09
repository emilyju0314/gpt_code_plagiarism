#include <iostream>
#include <vector>

int main() {
    int n, k;
    std::cin >> n >> k;

    std::vector<int> marks(n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        std::cin >> marks[i];
        sum += marks[i];
    }

    int average = (sum + n) / (n + 1); // Calculate the average by rounding up
    int additionalMarks = std::max(0, k * (n + 1) - sum - n); // Calculate the minimum number of additional marks needed

    std::cout << additionalMarks << std::endl;

    return 0;
}