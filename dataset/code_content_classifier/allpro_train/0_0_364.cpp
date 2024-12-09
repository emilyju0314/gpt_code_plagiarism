#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    
    std::vector<int> chairs(n);
    for(int i = 0; i < n; i++) {
        std::cin >> chairs[i];
    }
    
    int occupied = 0;
    int total_time = 0;
    
    for(int i = 0; i < n; i++) {
        if(chairs[i] == 1) {
            int j = i+1;
            while(j < n && chairs[j] == 0) {
                j++;
            }
            int time = j - i;
            total_time += time;
            std::swap(chairs[i], chairs[j]);
        }
    }
    
    std::cout << total_time << std::endl;
    
    return 0;
}