#include <iostream>

int main() {
    int n;
    std::cin >> n;
    
    int groups[5] = {0}; // Initialize an array to store count of each group size
    
    for(int i = 0; i < n; i++) {
        int s;
        std::cin >> s;
        groups[s]++;
    }
    
    // Calculate the minimum number of cars needed
    int cars = groups[4];
    cars += groups[3];
    cars += groups[2] / 2;
    groups[1] -= groups[3]; // Take care of leftover groups of 1 and 2
    if(groups[2] % 2 != 0) {
        cars++;
        groups[1] -= 2;
    }
    if(groups[1] > 0) {
        cars += (groups[1] + 3) / 4;
    }
    
    std::cout << cars << std::endl;
    
    return 0;
}