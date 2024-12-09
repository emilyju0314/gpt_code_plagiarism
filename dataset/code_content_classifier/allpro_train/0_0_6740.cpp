#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

int main() {
    int n;
    while(std::cin >> n) {
        if(n == 0) break;
        
        std::string word;
        std::vector<std::string> words;
        std::map<std::string, int> freq;
        
        for(int i = 0; i < n; i++) {
            std::cin >> word;
            words.push_back(word);
            freq[word]++;
        }
        
        std::sort(words.begin(), words.end());
        
        char k;
        std::cin >> k;
        
        std::vector<std::pair<int, std::string>> candidates;
        for(const auto& w : words) {
            if(w[0] == k) {
                candidates.push_back({-freq[w], w});
            }
        }
        
        if(candidates.empty()) {
            std::cout << "NA" << std::endl;
        } else {
            std::sort(candidates.begin(), candidates.end());
            for(int i = 0; i < std::min(5, (int)candidates.size()); i++) {
                std::cout << candidates[i].second << " ";
            }
            std::cout << std::endl;
        }
    }
    
    return 0;
}