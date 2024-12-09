#include <iostream>
#include <cmath>

int main() {
    int n, a;
    std::cin >> n >> a;
    
    // Calculate the minimum time to reach house a
    int distance_from_start = std::min(a, n - a);
    int distance_from_end = (n - distance_from_start) / 2;
    
    // Add the time taken to drive from the start to house a
    int min_time = distance_from_start + distance_from_end + 1;
    
    std::cout << min_time << std::endl;
    
    return 0;
}