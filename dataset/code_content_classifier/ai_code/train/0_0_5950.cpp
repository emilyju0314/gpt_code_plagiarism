#include <iostream>
#include <algorithm>

int main() {
    int N, A, B;
    std::cin >> N >> A >> B;

    int max_both = std::min(A, B);
    int min_both = std::max(0, A + B - N);

    std::cout << max_both << " " << min_both << std::endl;

    return 0;
}