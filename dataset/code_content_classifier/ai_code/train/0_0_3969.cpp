#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <unordered_map>

int main() {
    int N, Q;
    std::cin >> N;
    
    std::vector<std::string> strings(N);
    std::unordered_map<char, char> perm;
    for (int i = 0; i < N; ++i) {
        std::cin >> strings[i];
    }
    
    std::cin >> Q;
    
    for (int i = 0; i < Q; ++i) {
        int k;
        std::string p;
        std::cin >> k >> p;
        
        for (int j = 0; j < 26; ++j) {
            perm['a' + j] = p[j];
        }
        
        std::string target = strings[k - 1];
        std::transform(target.begin(), target.end(), target.begin(), [&](char c){ return perm[c]; });
        
        std::sort(strings.begin(), strings.end());
        int index = std::find(strings.begin(), strings.end(), target) - strings.begin();
        
        std::cout << index + 1 << std::endl;
    }
    
    return 0;
}