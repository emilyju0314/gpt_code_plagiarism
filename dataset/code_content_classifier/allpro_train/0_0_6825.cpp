#include <iostream>
#include <cmath>

struct UFO {
    int x, y, r, v;
};

int main() {
    while (true) {
        int R, N;
        std::cin >> R >> N;

        if (R == 0 && N == 0) {
            break;
        }

        int count = 0;

        for (int i = 0; i < N; i++) {
            UFO ufo;
            std::cin >> ufo.x >> ufo.y >> ufo.r >> ufo.v;

            int dist = sqrt(ufo.x * ufo.x + ufo.y * ufo.y);
            int max_dist = R + ufo.r + ufo.v;

            if (dist > max_dist) {
                count++;
            }
        }

        std::cout << count << std::endl;
    }

    return 0;
}