#include <iostream>
#include <vector>

struct Point {
    int x, y, h;
};

int main() {
    int N;
    std::cin >> N;

    std::vector<Point> points(N);
    for (int i = 0; i < N; i++) {
        std::cin >> points[i].x >> points[i].y >> points[i].h;
    }

    int C_X = -1, C_Y = -1, H = -1;

    for (int x = 0; x <= 100; x++) {
        for (int y = 0; y <= 100; y++) {
            int min_h = -1;
            bool valid = true;
            for (int i = 0; i < N; i++) {
                int h = points[i].h + abs(x - points[i].x) + abs(y - points[i].y);
                if (min_h == -1) {
                    min_h = h;
                } else if (h != min_h) {
                    valid = false;
                    break;
                }
            }
            if (valid) {
                H = min_h;
                C_X = x;
                C_Y = y;
                break;
            }
        }
        if (H != -1) {
            break;
        }
    }

    std::cout << C_X << " " << C_Y << " " << H << std::endl;

    return 0;
}