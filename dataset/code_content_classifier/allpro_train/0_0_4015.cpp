#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, k;
    std::cin >> n >> k;

    std::vector<int> skills(n);
    for (int i = 0; i < n; i++) {
        std::cin >> skills[i];
    }

    std::sort(skills.begin(), skills.end());

    std::vector<std::pair<int, int>> changes;
    for (int i = 0; i < k; i++) {
        int a, b;
        std::cin >> a >> b;
        changes.push_back({a, b});
    }

    long long count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            int lower = 0, higher = n-1;
            for (auto change : changes) {
                if (change.first <= skills[i] && change.second >= skills[j]) {
                    lower++;
                }
                if (change.first < skills[i] && change.second >= skills[j]) {
                    higher--;
                }
            }
            count += (lower + higher) * (n - lower - higher - 1);
        }
    }

    std::cout << count << std::endl;

    return 0;
}