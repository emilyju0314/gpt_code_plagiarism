#include <iostream>
#include <vector>

int main() {
    int N;
    std::cin >> N;
    
    std::vector<int> slimes(N);
    
    for (int i = 0; i < N; i++) {
        std::cin >> slimes[i];
    }
    
    long long total_cost = 0;
    
    while (slimes.size() > 1) {
        int min1 = 0, min2 = 1;
        
        if (slimes[min1] > slimes[min2]) {
            std::swap(min1, min2);
        }
        
        for (int i = 2; i < slimes.size(); i++) {
            if (slimes[i] < slimes[min1]) {
                min2 = min1;
                min1 = i;
            } else if (slimes[i] < slimes[min2]) {
                min2 = i;
            }
        }
        
        total_cost += slimes[min1] + slimes[min2];
        
        slimes[min1] += slimes[min2];
        slimes.erase(slimes.begin() + min2);
    }
    
    std::cout << total_cost << std::endl;
    
    return 0;
}