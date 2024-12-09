#include <iostream>
#include <string>
#include <algorithm>

int findMinK(const std::string& x, const std::string& y) {
    int lengthDiff = x.size() - y.size();
    int minK = lengthDiff;
    
    for (int i = lengthDiff; i < x.size(); i++) {
        if (x[i] == '1' && y[i - lengthDiff] == '1') {
            minK = i;
            break;
        }
    }
    
    return minK;
}

int main() {
    int T;
    std::cin >> T;
    
    for (int t = 0; t < T; t++) {
        std::string x, y;
        std::cin >> x >> y;
        
        std::reverse(x.begin(), x.end());
        std::reverse(y.begin(), y.end());
        
        int minK = findMinK(x, y);

        std::cout << minK << std::endl;
    }
    
    return 0;
}