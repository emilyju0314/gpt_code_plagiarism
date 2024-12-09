#include <iostream>
#include <string>

int main() {
    int n;
    std::cin >> n;

    std::string s, t;
    std::cin >> s >> t;

    int hamming_dist = 0;
    int diff_count = 0;
    int diff_pos_a = -1, diff_pos_b = -1;

    for(int i = 0; i < n; i++) {
        if(s[i] != t[i]) {
            hamming_dist++;
            if(diff_count == 0) {
                diff_pos_a = i;
            } else if(diff_count == 1) {
                diff_pos_b = i;
            }
            diff_count++;
        }
    }

    std::cout << hamming_dist << std::endl;

    if(hamming_dist == 0) {
        std::cout << "-1 -1" << std::endl;
    } else if(hamming_dist == 2 && s[diff_pos_a] == t[diff_pos_b] && s[diff_pos_b] == t[diff_pos_a]) {
        std::cout << diff_pos_a+1 << " " << diff_pos_b+1 << std::endl;
    } else {
        for(int i = 0; i < n; i++) {
            if(s[i] != t[i]) {
                for(int j = 0; j < n; j++) {
                    if(s[j] == t[i] && s[i] == t[j]) {
                        std::cout << i+1 << " " << j+1 << std::endl;
                        return 0;
                    }
                }
            }
        }
    }

    return 0;
}