#include <iostream>
#include <string>
#include <vector>

int main() {
    std::string s;
    std::cin >> s;

    int num_a = 0, num_b = 0;
    std::vector<int> prefixes_to_reverse;

    for(int i = 0; i < s.length(); i++) {
        if(s[i] == 'a') {
            num_a++;
        } else {
            num_b++;
        }

        if(num_b > num_a) {
            prefixes_to_reverse.push_back(1);
            std::swap(num_a, num_b);
        } else {
            prefixes_to_reverse.push_back(0);
        }
    }

    for(int i = 0; i < prefixes_to_reverse.size(); i++) {
        std::cout << prefixes_to_reverse[i] << " ";
    }

    return 0;
}