#include <iostream>
#include <stack>

int main() {
    int n;
    std::cin >> n;
    
    int left_count = 0, pairs = 0;
    std::stack<int> s;
    
    for (int i = 0; i < n; i++) {
        std::string sequence;
        std::cin >> sequence;
        
        int seq_length = sequence.length();
        
        for (int j = 0; j < seq_length; j++) {
            if (sequence[j] == '(') {
                s.push(j);
            } else {
                if (!s.empty()) {
                    s.pop();
                } else {
                    left_count++;
                }
            }
        }
        
        if (s.empty()) {
            if (left_count % 2 == 0) {
                pairs += left_count / 2;
            } else {
                pairs += left_count / 2 + 1;
            }
            left_count = 0;
        }
    }
    
    std::cout << pairs << std::endl;
    
    return 0;
}