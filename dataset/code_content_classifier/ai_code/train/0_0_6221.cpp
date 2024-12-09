#include <iostream>
#include <algorithm>

int rearrangeInt(int num, int numDigits) {
    std::string numStr = std::to_string(num);
    if (numStr.length() < numDigits) {
        numStr = std::string(numDigits - numStr.length(), '0') + numStr;
    }
    
    std::sort(numStr.begin(), numStr.end());
    std::string smallestStr = numStr;
    std::string largestStr = numStr;
    std::reverse(largestStr.begin(), largestStr.end());
    
    int smallest = std::stoi(smallestStr);
    int largest = std::stoi(largestStr);
    
    return largest - smallest;
}

int main() {
    int a0, L;
    while (std::cin >> a0 >> L) {
        if (a0 == 0 && L == 0) {
            break;
        }
        
        int i = 0;
        int aj = a0;
        int ai = rearrangeInt(aj, L);
        std::vector<int> seen;
        
        while (std::find(seen.begin(), seen.end(), ai) == seen.end()) {
            seen.push_back(ai);
            i++;
            aj = ai;
            ai = rearrangeInt(aj, L);
        }
        
        int j = std::find(seen.begin(), seen.end(), ai) - seen.begin();
        
        std::cout << j << " " << ai << " " << i - j << std::endl;
    }
    
    return 0;
}