#include <iostream>
#include <algorithm>

int main() {
    int h[6], w[6];

    for (int i = 0; i < 6; i++) {
        std::cin >> h[i] >> w[i];
    }

    std::sort(h, h + 6);
    std::sort(w, w + 6);

    if (h[0] == h[1] && h[1] == h[2] && w[0] == w[1] && w[1] == w[4] && w[4] == w[5] && w[2] == w[3]) {
        std::cout << "yes" << std::endl;
    } else {
        std::cout << "no" << std::endl;
    }

    return 0;
}