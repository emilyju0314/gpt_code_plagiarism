#include <iostream>
#include <vector>
#include <algorithm>

struct Tent {
    int x, y, weight;
};

bool isImportant(int x, int y) {
    return x % 2 == 0 && y % 2 == 0;
}

bool isForbidden(int x1, int y1, int x2, int y2, int x3, int y3) {
    return (abs(x1 - x2) <= 1 && abs(y1 - y2) <= 1 &&
            abs(x1 - x3) <= 1 && abs(y1 - y3) <= 1 &&
            (x1 - x2) * (y1 - y3) == (y1 - y2) * (x1 - x3));
}

int main() {
    int n;
    std::cin >> n;

    std::vector<Tent> tents(n);
    for (int i = 0; i < n; i++) {
        std::cin >> tents[i].x >> tents[i].y >> tents[i].weight;
    }

    int maxWeight = 0;
    for (int i = 0; i < n; i++) {
        if (!isImportant(tents[i].x, tents[i].y)) {
            continue;
        }

        int currentWeight = tents[i].weight;
        for (int j = i + 1; j < n; j++) {
            if (!isImportant(tents[j].x, tents[j].y)) {
                continue;
            }

            bool valid = true;
            for (int k = 0; k < n; k++) {
                if (k != i && k != j && isImportant(tents[k].x, tents[k].y)) {
                    if (isForbidden(tents[i].x, tents[i].y, tents[j].x, tents[j].y, tents[k].x, tents[k].y)) {
                        valid = false;
                        break;
                    }
                }
            }

            if (valid) {
                currentWeight += tents[j].weight;
            }
        }

        maxWeight = std::max(maxWeight, currentWeight);
    }

    std::cout << maxWeight << std::endl;

    return 0;
}