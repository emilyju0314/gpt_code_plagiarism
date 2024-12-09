#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct CatGroup {
    int x;
    int y;
    int c;
};

int main() {
    int N, M;

    while (true) {
        cin >> N >> M;

        if (N == 0 && M == 0) {
            break;
        }

        vector<CatGroup> catGroups(N);
        vector<int> baitPositions(M);
        vector<int> catsInBowl(M, 0);

        // Read cat group positions
        for (int i = 0; i < N; i++) {
            cin >> catGroups[i].x >> catGroups[i].y >> catGroups[i].c;
        }

        // Read bait positions
        for (int i = 0; i < M; i++) {
            cin >> baitPositions[i];
        }

        // Calculate distance between cat group and bait
        for (int i = 0; i < N; i++) {
            int closestBaitIndex = 0;
            double minDistance = 10000000; // Initialize to a large value

            for (int j = 0; j < M; j++) {
                double distance = sqrt(pow(catGroups[i].x - baitPositions[j], 2) + pow(catGroups[i].y, 2));
                if (distance < minDistance) {
                    minDistance = distance;
                    closestBaitIndex = j;
                } else if (distance == minDistance) {
                    closestBaitIndex = min(closestBaitIndex, j);
                }
            }

            catsInBowl[closestBaitIndex] += catGroups[i].c;
        }

        // Find the feeding bowl with the most cats
        int maxCatsInBowl = 0;
        for (int i = 0; i < M; i++) {
            maxCatsInBowl = max(maxCatsInBowl, catsInBowl[i]);
        }

        cout << maxCatsInBowl << endl;
    }

    return 0;
}