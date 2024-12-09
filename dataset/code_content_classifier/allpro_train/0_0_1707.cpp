#include <iostream>

int main() {
    int A, V, B, W, T;
    std::cin >> A >> V >> B >> W >> T;

    int dist = abs(A - B);
    int relative_speed = V - W;

    if (relative_speed <= 0) {
        std::cout << "NO" << std::endl;
    } else {
        int time_needed = (dist + relative_speed - 1) / relative_speed; // ceil function
        if (time_needed <= T) {
            std::cout << "YES" << std::endl;
        } else {
            std::cout << "NO" << std::endl;
        }
    }

    return 0;
}