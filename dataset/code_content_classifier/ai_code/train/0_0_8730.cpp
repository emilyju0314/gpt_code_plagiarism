#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

struct Food {
    std::string name;
    int weight;
    int endurance;
};

bool compare(Food a, Food b) {
    return a.endurance < b.endurance;
}

int main() {
    int n;
    while (std::cin >> n && n != 0) {
        std::vector<Food> foods(n);
        int total_weight = 0;

        for (int i = 0; i < n; i++) {
            std::cin >> foods[i].name >> foods[i].weight >> foods[i].endurance;
            total_weight += foods[i].weight;
        }

        std::sort(foods.begin(), foods.end(), compare);

        std::vector<std::string> stacked_foods;
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                if (foods[j].endurance < foods[i].weight) {
                    std::swap(foods[i], foods[j]);
                }
            }
            stacked_foods.push_back(foods[i].name);
        }

        for (int i = n-1; i >= 0; i--) {
            std::cout << stacked_foods[i] << std::endl;
        }
    }

    return 0;
}