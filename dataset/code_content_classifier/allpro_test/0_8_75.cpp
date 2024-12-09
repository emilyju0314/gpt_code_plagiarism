#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    int left = 0, right = N - 1;
    int last = 0;
    std::string winner;

    while (left <= right) {
        int picked;
        if (A[left] <= A[right]) {
            picked = A[left];
            left++;
        } else {
            picked = A[right];
            right--;
        }

        if (picked > last) {
            last = picked;
            winner = winner == "Alice" ? "Bob" : "Alice";
        }
    }

    std::cout << winner << std::endl;

    return 0;
}