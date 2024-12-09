#include <iostream>
#include <string>

std::string getDogName(long long N) {
    std::string name;
    const int alphaSize = 26;
    
    // Calculate the length of the name
    int len = 0;
    long long range = alphaSize;
    while (N > range) {
        N -= range;
        range *= alphaSize;
        len++;
    }
    
    // Build the name for the dog numbered N
    while (len >= 0) {
        int offset = (N - 1) % alphaSize;
        char c = 'a' + offset;
        name += c;
        
        N = (N - 1) / alphaSize;
        len--;
    }
    
    // Reverse the name since we built it from right to left
    std::reverse(name.begin(), name.end());
    
    return name;
}

int main() {
    long long N;
    std::cin >> N;
    
    std::string dogName = getDogName(N);
    
    std::cout << dogName << std::endl;
    
    return 0;
}