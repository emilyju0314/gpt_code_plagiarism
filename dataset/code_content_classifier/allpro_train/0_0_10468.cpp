#include <iostream>
#include <vector>

struct Point {
    int x, y;
};

bool sameShape(const std::vector<Point>& templateLine, const std::vector<Point>& polygonalLine) {
    if (templateLine.size() != polygonalLine.size()) {
        return false;
    }

    int dx = templateLine[0].x - polygonalLine[0].x;
    int dy = templateLine[0].y - polygonalLine[0].y;

    for (int i = 0; i < templateLine.size(); ++i) {
        if (templateLine[i].x - polygonalLine[i].x != dx || templateLine[i].y - polygonalLine[i].y != dy) {
            return false;
        }
    }

    return true;
}

int main() {
    int n;
    int dataset = 1;

    while (std::cin >> n && n != 0) {
        std::vector<Point> templateLine(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> templateLine[i].x >> templateLine[i].y;
        }

        int m;
        std::vector<std::vector<Point>> polygonalLines;

        std::cout << "DATASET " << dataset++ << std::endl;

        while (std::cin >> m && m != 0) {
            std::vector<Point> polygonalLine(m);
            for (int i = 0; i < m; ++i) {
                std::cin >> polygonalLine[i].x >> polygonalLine[i].y;
            }

            if (sameShape(templateLine, polygonalLine)) {
                std::cout << polygonalLines.size() + 1 << std::endl;
            }

            std::cout << "++" << std::endl;
        }
    }

    return 0;
}