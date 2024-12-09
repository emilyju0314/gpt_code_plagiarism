#include <iostream>
#include <string>
#include <unordered_map>

int main() {
    int N;
    std::cin >> N;
    
    std::unordered_map<std::string, int> count;
    long long ans = 0;
    
    for (int i = 0; i < N; i++) {
        std::string s;
        std::cin >> s;
        
        std::string sorted = s;
        std::sort(sorted.begin(), sorted.end());
        
        ans += count[sorted];
        
        for (int j = 0; j < 10; j++) {
            std::string key = sorted;
            key[j] = '*';
            count[key]++;
        }
    }
    
    std::cout << ans << std::endl;
    
    return 0;
}