#include <iostream>
#include <vector>
#include <cmath>

int main() {
    int n;
    std::cin >> n;
    
    std::vector<int> lights(2*pow(2,n)-2);
    for (int i = 0; i < 2*pow(2,n)-2; i++) {
        std::cin >> lights[i];
    }

    int total_lights = 0;
    for (int i = n-1; i >= 0; i--) {
        int level_start = pow(2, i) - 1;
        int level_end = pow(2, i+1) - 2;
        for (int j = level_start; j <= level_end; j+=2) {
            int diff = std::abs(lights[j] - lights[j+1]);
            total_lights += diff;
            lights[j] = lights[j+1] = std::max(lights[j], lights[j+1]);
        }
    }

    std::cout << total_lights << std::endl;

    return 0;
}