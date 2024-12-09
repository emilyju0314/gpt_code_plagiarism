#include <iostream>
#include <vector>
#include <cmath>

struct Sector {
    int x, y, r, s, t;
};

bool isOverlap(const Sector& a, const Sector& b) {
    int dx = b.x - a.x;
    int dy = b.y - a.y;
    int distance = sqrt(dx*dx + dy*dy);

    if (distance > a.r + b.r) {
        return false;
    }

    int angle_diff = std::min(abs(b.s - a.t), abs(a.s - b.t));
    
    if (distance <= a.r - b.r && angle_diff <= 180) {
        return true;
    }

    return false;
}

int countOverlaps(const std::vector<Sector>& sectors) {
    int maxOverlaps = 0;

    for (int i = 0; i < sectors.size(); i++) {
        int overlaps = 1;

        for (int j = 0; j < sectors.size(); j++) {
            if (i != j && isOverlap(sectors[i], sectors[j])) {
                overlaps++;
            }
        }

        if (overlaps > maxOverlaps) {
            maxOverlaps = overlaps;
        }
    }

    return maxOverlaps;
}

int main() {
    int n;
    std::cin >> n;

    for (int i = 0; i < n; i++) {
        int m;
        std::cin >> m;

        std::vector<Sector> sectors(m);
        for (int j = 0; j < m; j++) {
            Sector sector;
            std::cin >> sector.x >> sector.y >> sector.r >> sector.s >> sector.t;
            sectors[j] = sector;
        }

        int maxOverlaps = countOverlaps(sectors);
        std::cout << maxOverlaps << std::endl;
    }

    return 0;
}