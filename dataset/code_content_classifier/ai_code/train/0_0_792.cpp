#include <iostream>
#include <cmath>

int main() {
    int t1, t2, x1, x2, t0;
    std::cin >> t1 >> t2 >> x1 >> x2 >> t0;

    int y1 = 0, y2 = 0;
    int best_time = INT_MAX;

    for(int i = 0; i <= x1; i++) {
        for(int j = 0; j <= x2; j++) {
            int temp = (t1 * i + t2 * j) / (i + j);
            if(temp >= t0 && temp <= best_time) {
                best_time = temp;
                y1 = i;
                y2 = j;
            }
        }
    }

    std::cout << y1 << " " << y2 << std::endl;

    return 0;
}