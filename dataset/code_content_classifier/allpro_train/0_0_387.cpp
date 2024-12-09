#include <iostream>
#include <vector>
#include <unordered_set>

struct Point {
    int x, y;
};

int main() {
    int k, n;
    std::cin >> k >> n;

    std::vector<Point> teleportationStones(k);
    std::vector<Point> monsters(n);

    for (int i = 0; i < k; ++i) {
        std::cin >> teleportationStones[i].x >> teleportationStones[i].y;
    }

    for (int i = 0; i < n; ++i) {
        std::cin >> monsters[i].x >> monsters[i].y;
    }

    std::unordered_set<int> afraidMonsters;

    for (const auto& monster : monsters) {
        bool isAfraid = false;
        for (const auto& stone : teleportationStones) {
            int dx = stone.x - monster.x;
            int dy = stone.y - monster.y;

            bool canHit = true;
            for (const auto& otherMonster : monsters) {
                if (otherMonster.x == monster.x && otherMonster.y == monster.y) {
                    continue;
                }

                int dx2 = otherMonster.x - monster.x;
                int dy2 = otherMonster.y - monster.y;

                if (dx * dy2 == dx2 * dy) {
                    canHit = false;
                    break;
                }
            }

            if (canHit) {
                isAfraid = true;
                break;
            }
        }

        if (isAfraid) {
            afraidMonsters.insert(monster.x * 1000000 + monster.y);
        }
    }

    std::cout << afraidMonsters.size() << std::endl;

    return 0;
}