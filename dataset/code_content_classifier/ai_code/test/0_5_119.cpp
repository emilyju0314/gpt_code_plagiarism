#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n;
        std::cin >> n;
        std::vector<int> heights(n);

        for (int i = 0; i < n; ++i) {
            std::cin >> heights[i];
        }

        int min_height = *min_element(heights.begin(), heights.end());
        int max_height = *max_element(heights.begin(), heights.end());

        int min_ugliness = max_height - min_height;

        std::cout << min_ugliness << std::endl;
    }

    return 0;
}