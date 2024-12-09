#include <iostream>

int main() {
    int W, H, N;
    std::cin >> W >> H >> N;

    int left = 0, right = W, top = H, bottom = 0;
    for (int i = 0; i < N; i++) {
        int x, y, a;
        std::cin >> x >> y >> a;
        if (a == 1) {
            left = std::max(left, x);
        } else if (a == 2) {
            right = std::min(right, x);
        } else if (a == 3) {
            bottom = std::max(bottom, y);
        } else if (a == 4) {
            top = std::min(top, y);
        }
    }

    int white_area = (right - left) * (top - bottom);
    int black_area = (right - left) * H + (top - bottom) * W - white_area;

    std::cout << white_area << std::endl;

    return 0;
}