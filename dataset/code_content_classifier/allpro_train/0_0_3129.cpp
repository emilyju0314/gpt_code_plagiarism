#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::string s;
    std::cin >> s;

    std::vector<int> color(n, 0);
    
    // Check if the string is already sorted
    if(std::is_sorted(s.begin(), s.end())) {
        std::cout << "YES" << std::endl;
        for(int i = 0; i < n; i++) {
            std::cout << color[i];
        }
    } else {
        // Color the string alternating between 0 and 1
        int current_color = 0;
        for(int i = 0; i < n-1; i++) {
            color[i] = current_color;
            if(s[i] > s[i+1]) {
                current_color = 1 - current_color;
            }
        }
        color[n-1] = current_color;

        // Check if the coloring results in a sorted string
        std::string temp = s;
        for(int i = 0; i < n; i++) {
            if(color[i] == 1) {
                std::swap(temp[i], temp[i+1]);
            }
        }

        if(std::is_sorted(temp.begin(), temp.end())) {
            std::cout << "YES" << std::endl;
            for(int i = 0; i < n; i++) {
                std::cout << color[i];
            }
        } else {
            std::cout << "NO" << std::endl;
        }
    }

    return 0;
}