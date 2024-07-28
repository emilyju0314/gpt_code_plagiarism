#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int N, M;
        scanf("%d %d", &N, &M);

        vector<pair<int, int>> corners;
        for (int i = 0; i < N; ++i) {
            int x, y;
            scanf("%d %d", &x, &y);
            corners.push_back({x, y});
        }

        vector<pair<int, int>> fence;
        for (int i = 0; i < M; ++i) {
            int x, y;
            scanf("%d %d", &x, &y);
            fence.push_back({x, y});
        }

        double maxDistance = 0;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                double distance = hypot(corners[i].first - fence[j].first, corners[i].second - fence[j].second);
                maxDistance = max(maxDistance, distance);
            }
        }

        printf("%.6f\n", maxDistance);
    }
    return 0;
}
