#include <iostream>
#include <climits>

int main() {
    int n;
    
    while (std::cin >> n && n != 0) {
        int highest = INT_MIN;
        int lowest = INT_MAX;
        
        for (int i = 0; i < n; i++) {
            int s1, s2, s3, s4, s5;
            std::cin >> s1 >> s2 >> s3 >> s4 >> s5;
            
            int total = s1 + s2 + s3 + s4 + s5;
            highest = std::max(highest, total);
            lowest = std::min(lowest, total);
        }
        
        std::cout << highest << " " << lowest << std::endl;
    }
    
    return 0;
}