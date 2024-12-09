#include <iostream>
#include <cmath>

int main() {
    int l, d, v, g, r;
    std::cin >> l >> d >> v >> g >> r;

    int green_cycle = g + r;
    double time = (double)d / v;
    
    int full_cycles = (int)floor(time / green_cycle);
    double remain_time = time - full_cycles * green_cycle;

    double result = 0;
    if (remain_time <= g) {
        result = (double)(l - d) / v;
    } else {
        result = (double)(green_cycle - remain_time + l - d) / v;
    }
    
    result += full_cycles * green_cycle;
    std::cout << result << std::endl;

    return 0;
}