#include <iostream>
#include <vector>

struct Laptop {
    int speed, ram, hdd, cost, index;
};

bool isOutdated(const Laptop& a, const Laptop& b) {
    return (a.speed < b.speed && a.ram < b.ram && a.hdd < b.hdd);
}

int main() {
    int n;
    std::cin >> n;

    std::vector<Laptop> laptops(n);

    for (int i = 0; i < n; i++) {
        std::cin >> laptops[i].speed >> laptops[i].ram >> laptops[i].hdd >> laptops[i].cost;
        laptops[i].index = i + 1;
    }

    int minCost = 1001;
    int chosenLaptop = -1;

    for (int i = 0; i < n; i++) {
        bool outdated = false;
        for (int j = 0; j < n; j++) {
            if (i != j && isOutdated(laptops[j], laptops[i])) {
                outdated = true;
                break;
            }
        }
        if (!outdated && laptops[i].cost < minCost) {
            minCost = laptops[i].cost;
            chosenLaptop = laptops[i].index;
        }
    }

    std::cout << chosenLaptop;

    return 0;
}