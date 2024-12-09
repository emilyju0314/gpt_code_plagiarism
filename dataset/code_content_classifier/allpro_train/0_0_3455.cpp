#include <iostream>
#include <vector>

struct Line {
    int xs, ys, xt, yt, o, l;
};

int main() {
    int datasets;
    std::cin >> datasets;

    for (int i = 0; i < datasets; i++) {
        int xa, ya, xb, yb;
        std::cin >> xa >> ya >> xb >> yb;

        int n;
        std::cin >> n;

        std::vector<Line> existingRoutes(n);
        for (int j = 0; j < n; j++) {
            std::cin >> existingRoutes[j].xs >> existingRoutes[j].ys >> existingRoutes[j].xt >> existingRoutes[j].yt >> existingRoutes[j].o >> existingRoutes[j].l;
        }

        // Add your logic to determine the minimum number of doorways needed

        // Output the minimum number of doorways needed for this dataset
    }

    return 0;
}