#include <iostream>
#include <vector>
#include <algorithm>

struct Mirror {
    int v; // score
    char c; // position: 'T' (ceiling) or 'F' (floor)
    int a; // x-coordinate beginning
    int b; // x-coordinate end
};

int hl, hr, n;
std::vector<Mirror> mirrors;
int maxScore = 0;

void shootLaser(int idx, int score) {
    if (idx == n) {
        maxScore = std::max(maxScore, score);
        return;
    }

    int vp = mirrors[idx].v; // score of current mirror
    char cp = mirrors[idx].c; // position of current mirror
    int ap = mirrors[idx].a; // x-coordinate beginning of current mirror
    int bp = mirrors[idx].b; // x-coordinate end of current mirror

    int msl = hl; // height of laser beam entering the mirror
    int msr = hr; // height of laser beam exiting the mirror

    if (cp == 'T') {
        msl = hr;
        msr = hl;
    }

    int newScore = score + vp;
    bool hit = false;
    for (int i = idx + 1; i < n; i++) {
        if (mirrors[i].c == cp && mirrors[i].a <= bp && mirrors[i].b >= ap) {
            hit = true;
            break;
        }
    }

    if (!hit) {
        shootLaser(idx + 1, newScore);
    }

    hit = false;
    for (int i = idx + 1; i < n; i++) {
        if (mirrors[i].c == cp && mirrors[i].a <= ap && mirrors[i].b >= bp) {
            hit = true;
            break;
        }
    }

    if (!hit) {
        shootLaser(idx + 1, newScore);
    }

    return;
}

int main() {
    std::cin >> hl >> hr >> n;

    mirrors.resize(n);
    for (int i = 0; i < n; i++) {
        std::cin >> mirrors[i].v >> mirrors[i].c >> mirrors[i].a >> mirrors[i].b;
    }

    shootLaser(0, 0);

    std::cout << maxScore << std::endl;

    return 0;
}