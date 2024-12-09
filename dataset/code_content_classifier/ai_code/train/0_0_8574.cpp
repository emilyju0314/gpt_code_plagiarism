#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    
    std::string a, b;
    std::cin >> a >> b;
    
    int preprocess_moves = 0;
    std::vector<int> chars_a(26, 0), chars_b(26, 0);
    for(int i = 0; i < n; i++) {
        chars_a[a[i] - 'a']++;
        chars_b[b[i] - 'a']++;
        
        if(a[i] != b[i]) {
            preprocess_moves++;
        }
    }

    int changes = 0;
    for(int i = 0; i < 26; i++) {
        if((chars_a[i] + chars_b[i]) % 2 != 0) {
            std::cout << -1 << std::endl;
            return 0;
        }
        
        changes += std::min(chars_a[i], chars_b[i]);
    }

    std::cout << preprocess_moves + changes/2 << std::endl;

    return 0;
}