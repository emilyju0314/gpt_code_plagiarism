#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <iomanip>

struct Segment {
    int x1, y1, x2, y2;
};

int main() {
    int W, H;
    std::cin >> W >> H;

    int n;
    std::cin >> n;

    std::vector<Segment> segments(n);

    for (int i = 0; i < n; i++) {
        std::cin >> segments[i].x1 >> segments[i].y1 >> segments[i].x2 >> segments[i].y2;
    }

    int m;
    std::cin >> m;

    std::map<std::string, double> colors;

    for (int i = 0; i < m; i++) {
        int x, y;
        std::string color;
        std::cin >> x >> y >> color;

        bool isSegment = false;
        for (const Segment& segment : segments) {
            if ((x >= std::min(segment.x1, segment.x2) && x < std::max(segment.x1, segment.x2)) &&
                    (y >= std::min(segment.y1, segment.y2) && y < std::max(segment.y1, segment.y2))) {
                isSegment = true;
                break;
            }
        }

        if (!isSegment) {
            colors[color] += 1;
        }
    }

    colors["white"] = (double)W * H;

    for (const auto& color : colors) {
        std::cout << color.first << " " << std::fixed << std::setprecision(8) << color.second << std::endl;
    }

    return 0;
}