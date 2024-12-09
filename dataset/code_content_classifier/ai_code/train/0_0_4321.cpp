#include <iostream>
#include <vector>
#include <algorithm>

struct Frame {
    int x0, y0, x1, y1, order;

    bool operator<(const Frame& other) const {
        if (y1 == other.y1) {
            return x0 < other.x0;
        } else {
            return y1 > other.y1;
        }
    }
};

int main() {
    int n;
    int datasetCount = 0;

    while (true) {
        datasetCount++;
        std::cin >> n;

        if (n == 0) {
            break;
        }

        std::vector<Frame> frames(n);
        
        for (int i = 0; i < n; i++) {
            std::cin >> frames[i].x0 >> frames[i].y0 >> frames[i].x1 >> frames[i].y1;
            frames[i].order = i + 1;
        }

        std::sort(frames.begin(), frames.end());

        for (int i = 0; i < n; i++) {
            std::cout << frames[i].order << std::endl;
        }

        if (datasetCount > 1) {
            std::cout << std::endl;
        }
    }

    return 0;
}