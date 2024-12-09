#include <iostream>
#include <string>
#include <vector>

int main() {
    int N;
    std::string S;
    
    // Input N and S
    std::cin >> N >> S;
    
    int count = 0;
    
    // Iterate through all possible ways to color each character
    for (int i = 0; i < (1 << 2*N); i++) {
        std::string red, blue;
        int redIdx = 0, blueIdx = 2*N-1;
        
        // Assign each character to red or blue based on current bitmask
        for (int j = 0; j < 2*N; j++) {
            if ((i >> j) & 1)
                red += S[j];
            else
                blue += S[j];
        }
        
        // Check if red string equals reverse of blue string
        if (red == std::string(blue.rbegin(), blue.rend()))
            count++;
    }
    
    std::cout << count << std::endl;

    return 0;
}