#include <iostream>
#include <vector>
#include <cstdlib>

std::string generateWord(int n, std::vector<std::string> bigrams) {
    std::string word = "";
    word += bigrams[0][0];
    for(int i = 0; i < n - 2; i++) {
        word += bigrams[i][1];
    }
    word += bigrams[n-3][1];
    
    return word;
}

int main() {
    int t;
    std::cin >> t;
    
    while(t--) {
        int n;
        std::cin >> n;
        
        std::vector<std::string> bigrams(n-2);
        for(int i = 0; i < n-2; i++) {
            std::cin >> bigrams[i];
        }
        
        std::string word = generateWord(n, bigrams);
        std::cout << word << std::endl;
    }
    
    return 0;
}