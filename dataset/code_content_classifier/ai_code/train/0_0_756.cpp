#include <iostream>
#include <vector>
#include <cmath>

int main() {
    int N;
    std::cin >> N;
    
    std::vector<int> frames(N);
    int total = 0;
    
    for(int i = 0; i < N; i++) {
        std::cin >> frames[i];
        total += frames[i];
    }
    
    int average = total / N;
    int min_diff = INT_MAX;
    int index = 0;
    
    for(int i = 0; i < N; i++) {
        int diff = abs(frames[i] - average);
        if(diff < min_diff || (diff == min_diff && i < index)) {
            min_diff = diff;
            index = i;
        }
    }
    
    std::cout << index << std::endl;
    
    return 0;
}