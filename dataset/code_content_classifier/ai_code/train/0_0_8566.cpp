#include <iostream>

int main() {
    int datasets;
    std::cin >> datasets;

    for (int i = 0; i < datasets; i++) {
        int X, Y, W, H;
        std::cin >> X >> Y >> W >> H;

        int N;
        std::cin >> N;

        int count = 0;
        for (int j = 0; j < N; j++) {
            int x, y;
            std::cin >> x >> y;

            if (x >= X && x <= X + W && y >= Y && y <= Y + H) {
                count++;
            }
        }

        std::cout << count << std::endl;
    }

    return 0;
}