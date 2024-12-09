#include <iostream>
#include <string>
#include <unordered_set>

int main() {
    std::string sentence;
    std::unordered_set<std::string> forbiddenPairs;
    
    std::cin >> sentence;
    
    int k;
    std::cin >> k;
    
    for (int i = 0; i < k; i++) {
        std::string pair;
        std::cin >> pair;
        forbiddenPairs.insert(pair);
    }
    
    int removals = 0;
    
    for (int i = 0; i < sentence.length() - 1; i++) {
        if (forbiddenPairs.count(sentence.substr(i, 2)) > 0) {
            removals++;
            i++;
        }
    }
    
    std::cout << removals << std::endl;

    return 0;
}