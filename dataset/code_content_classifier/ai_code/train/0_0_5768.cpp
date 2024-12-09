#include <iostream>

int main() {
    int h, m, s, t1, t2;
    std::cin >> h >> m >> s >> t1 >> t2;

    h = (h == 12) ? 0 : h;
    t1 = (t1 == 12) ? 0 : t1;
    t2 = (t2 == 12) ? 0 : t2;

    bool canPrepareContest = true;

    if ((t1 < h && h < t2) || (t1 < m / 5 && m / 5 < t2) || (t1 < s / 5 && s / 5 < t2)) {
        canPrepareContest = false;
    }
    if ((t2 < h && h < t1) || (t2 < m / 5 && m / 5 < t1) || (t2 < s / 5 && s / 5 < t1)) {
        canPrepareContest = false;
    }

    if (canPrepareContest) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }

    return 0;
}