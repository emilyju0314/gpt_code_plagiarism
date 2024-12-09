#include <iostream>
#include <vector>
#include <map>

int main() {
    int q;
    std::cin >> q;

    for (int i = 0; i < q; i++) {
        int n;
        std::cin >> n;

        std::map<int, int> candy_counts;
        std::map<int, int> f_counts;

        for (int j = 0; j < n; j++) {
            int a, f;
            std::cin >> a >> f;

            candy_counts[a]++;
            if (f == 1) {
                f_counts[a]++;
            }
        }

        std::vector<int> candies;
        for (auto it = candy_counts.begin(); it != candy_counts.end(); it++) {
            candies.push_back(it->second);
        }

        int max_candies = 0, max_f_candies = 0;
        for (int j = 0; j < candies.size(); j++) {
            if (2 * candies[j] - f_counts[candies[j]] > max_candies) {
                max_candies = 2 * candies[j] - f_counts[candies[j]];
                max_f_candies = candies[j];
            } else if (2 * candies[j] - f_counts[candies[j]] == max_candies) {
                max_f_candies = std::max(max_f_candies, candies[j]);
            }
        }

        std::cout << max_candies << " " << max_f_candies << std::endl;

    }

    return 0;
}