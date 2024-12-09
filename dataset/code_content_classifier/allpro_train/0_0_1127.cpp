#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

struct Player {
    int frame;
    int number;
    int team;
    int x;
    int y;
};

double computeDistance(int x1, int y1, int x2, int y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

int main() {
    int N;
    std::cin >> N;

    std::vector<Player> players(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> players[i].frame >> players[i].number >> players[i].team >> players[i].x >> players[i].y;
    }

    double maxDistanceA = -1, maxDistanceB = -1;
    double timeA = -1, timeB = -1;

    for (int i = 0; i < N; ++i) {
        if (players[i].team == 0) {
            for (int j = i + 1; j < N; ++j) {
                if (players[j].team == 0 && players[i].number != players[j].number) {
                    double distance = computeDistance(players[i].x, players[i].y, players[j].x, players[j].y);
                    double timeTaken = (players[j].frame - players[i].frame) / 60.0;

                    if (distance > maxDistanceA || (distance == maxDistanceA && timeTaken < timeA)) {
                        maxDistanceA = distance;
                        timeA = timeTaken;
                    }
                }
            }
        } else {
            for (int j = i + 1; j < N; ++j) {
                if (players[j].team == 1 && players[i].number != players[j].number) {
                    double distance = computeDistance(players[i].x, players[i].y, players[j].x, players[j].y);
                    double timeTaken = (players[j].frame - players[i].frame) / 60.0;

                    if (distance > maxDistanceB || (distance == maxDistanceB && timeTaken < timeB)) {
                        maxDistanceB = distance;
                        timeB = timeTaken;
                    }
                }
            }
        }
    }

    if (maxDistanceA == -1) {
        std::cout << -1 << " " << -1 << std::endl;
    } else {
        std::cout << std::fixed;
        std::cout.precision(10);
        std::cout << maxDistanceA << " " << timeA << std::endl;
    }

    if (maxDistanceB == -1) {
        std::cout << -1 << " " << -1 << std::endl;
    } else {
        std::cout << std::fixed;
        std::cout.precision(10);
        std::cout << maxDistanceB << " " << timeB << std::endl;
    }

    return 0;
}