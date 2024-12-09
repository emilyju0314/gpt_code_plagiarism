#include <iostream>
#include <vector>

int main() {
    int A, B;
    std::cin >> A >> B;

    int N = A + B + 1;
    std::vector<int> heights;

    for (int i = 1; i <= N; i++) {
        heights.push_back(i);
    }

    // Now constructing the possible stop heights
    std::vector<int> possible_heights;
    int up = 0;
    int down = B;

    while (up <= A && down >= 0) {
        if (up < A) {
            possible_heights.push_back(heights[A - up - 1]);
            up++;
        }
        possible_heights.push_back(heights[N - down]);
        down--;
    }

    for (int height : possible_heights) {
        std::cout << height << " ";
    }

    return 0;
}