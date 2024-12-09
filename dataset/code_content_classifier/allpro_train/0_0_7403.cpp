#include <iostream>
#include <vector>

int getSegments(int num) {
    std::vector<int> segments = { 6, 2, 5, 5, 4, 5, 6, 3, 7, 6 };
    int totalSegments = 0;
    
    while(num > 0) {
        totalSegments += segments[num % 10];
        num /= 10;
    }
    
    return totalSegments;
}

int main() {
    int a, b;
    std::cin >> a >> b;
    
    int totalSegments = 0;
    for(int i = a; i <= b; i++) {
        totalSegments += getSegments(i);
    }
    
    std::cout << totalSegments << std::endl;
    
    return 0;
}