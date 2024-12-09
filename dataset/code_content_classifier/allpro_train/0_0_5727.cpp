#include <iostream>

int main() {
    int t1, t2, x1, x2, t0;
    std::cin >> t1 >> t2 >> x1 >> x2 >> t0;
    
    int y1 = 0, y2 = 0;
    int best_diff = abs(t1 - t0);
    
    for (int i = 0; i <= x1; i++) {
        for (int j = 0; j <= x2; j++) {
            int temp = (i * t1 + j * t2) / (i + j);
            int diff = abs(temp - t0);
            if (diff < best_diff || (diff == best_diff && i + j < y1 + y2)) {
                y1 = i;
                y2 = j;
                best_diff = diff;
            }
        }
    }
    
    std::cout << y1 << " " << y2 << std::endl;
    
    return 0;
}