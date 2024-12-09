#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int N;
    std::cin >> N;

    std::vector<int> intervals(N);
    for (int i = 0; i < N; i++) {
        std::cin >> intervals[i];
    }

    // Sort the intervals in ascending order
    std::sort(intervals.begin(), intervals.end());

    // Calculate the minimum value of the sum of all d_i
    int min_sum = 0;
    for (int i = 0; i < N - 1; i++) {
        min_sum += intervals[i + 1] - intervals[i] - 1;
    }

    std::cout << min_sum << std::endl;

    return 0;
}