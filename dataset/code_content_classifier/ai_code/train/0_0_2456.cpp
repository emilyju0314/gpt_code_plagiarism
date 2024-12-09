#include <iostream>
#include <vector>
#include <algorithm>

struct Lemming {
    int weight;
    int speed;
    int index;
};

bool compare(const Lemming &lem1, const Lemming &lem2) {
    return lem1.weight < lem2.weight;
}

int main() {
    int n, k, h;
    std::cin >> n >> k >> h;

    std::vector<Lemming> lemmings(n);
    for (int i = 0; i < n; i++) {
        std::cin >> lemmings[i].weight;
        lemmings[i].index = i + 1;
    }

    for (int i = 0; i < n; i++) {
        std::cin >> lemmings[i].speed;
    }

    std::sort(lemmings.begin(), lemmings.end(), compare);

    int t = 0;
    for (int i = 0; i < k; i++) {
        t = std::max(t, (i+1)*h/lemmings[i].speed);
    }

    for (int i = 0; i < k; i++) {
        std::cout << lemmings[i].index << " ";
    }

    return 0;
}