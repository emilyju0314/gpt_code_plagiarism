#include <iostream>
#include <string>

int main() {
    int s1A, s2A, s1B, s2B, s1C, s2C, s1D, s2D, s1E, s2E;
    int maxTotal = 0;
    std::string storeName = "";
    
    while (true) {
        std::cin >> s1A >> s2A;
        if (s1A == 0 && s2A == 0) {
            break;
        }
        
        std::cin >> s1B >> s2B >> s1C >> s2C >> s1D >> s2D >> s1E >> s2E;
        
        int totalA = s1A + s2A;
        int totalB = s1B + s2B;
        int totalC = s1C + s2C;
        int totalD = s1D + s2D;
        int totalE = s1E + s2E;
        
        int maxDailyTotal = std::max(totalA, std::max(totalB, std::max(totalC, std::max(totalD, totalE))));
        if (maxDailyTotal > maxTotal) {
            maxTotal = maxDailyTotal;
            if (maxDailyTotal == totalA) {
                storeName = "A";
            } else if (maxDailyTotal == totalB) {
                storeName = "B";
            } else if (maxDailyTotal == totalC) {
                storeName = "C";
            } else if (maxDailyTotal == totalD) {
                storeName = "D";
            } else {
                storeName = "E";
            }
        }
        
        std::cout << storeName << " " << maxTotal << std::endl;
    }
    
    return 0;
}