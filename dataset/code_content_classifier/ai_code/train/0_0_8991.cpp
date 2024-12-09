#include <iostream>
#include <vector>
#include <set>

struct Point {
    int x, y;
};

bool checkOverlap(Point A, Point B, Point C, Point D) {
    if (A.x >= C.x && B.x <= D.x && A.y >= C.y && B.y <= D.y) {
        return true;
    }
    if (C.x >= A.x && D.x <= B.x && C.y >= A.y && D.y <= B.y) {
        return true;
    }
    return false;
}

int main() {
    int N;
    std::cin >> N;

    while (N != 0) {
        for (int i = 0; i < N; i++) {
            int M;
            std::cin >> M;

            std::vector<std::vector<Point>> rectangles(M);
            std::set<std::pair<int, int>> groups;

            for (int j = 0; j < M; j++) {
                Point A, B, C, D;
                std::cin >> A.x >> A.y >> B.x >> B.y >> C.x >> C.y >> D.x >> D.y;

                bool foundGroup = false;
                int groupId = 0;

                for (const auto& group : groups) {
                    if (checkOverlap(rectangles[group.first][group.second], rectangles[group.first][group.second + 1], A, B) ||
                        checkOverlap(rectangles[group.first][group.second], rectangles[group.first][group.second + 1], B, C) ||
                        checkOverlap(rectangles[group.first][group.second], rectangles[group.first][group.second + 1], C, D) ||
                        checkOverlap(rectangles[group.first][group.second], rectangles[group.first][group.second + 1], D, A)) {
                        foundGroup = true;
                        groupId = group.first;
                        break;
                    }
                }
                if (!foundGroup) {
                    groups.insert({j, 0});
                } else {
                    if (rectangles[groupId].size() == 2 * (groups.find({groupId, 0})->second + 1)) {
                        groups.erase({groupId, 0});
                        groups.insert({groupId, groups.find({groupId, 0})->second + 1});
                    }
                }

                rectangles[j] = {A, B, C, D};
            }

            std::cout << groups.size() << std::endl;
        }

        std::cin >> N;
    }
    
    return 0;
}