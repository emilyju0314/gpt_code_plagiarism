#include <iostream>
#include <string>
#include <algorithm>

int main() {
    int n, x, y;
    std::string a;
    std::cin >> n >> x >> y;
    std::cin >> a;

    int num_zeros = 0;
    for(char c : a) {
        if(c == '0') {
            num_zeros++;
        }
    }

    int total_cost = 0;
    if(num_zeros > 0) {
        int num_changes = 0;
        for(int i = 0; i < n; i++) {
            if(a[i] == '0' && (i == 0 || a[i-1] == '1')) {
                num_changes++;
            }
        }
        
        if(y >= x) {
            total_cost = num_changes * x;
        } else {
            total_cost = y + num_changes * x;
        }
    }

    std::cout << total_cost << std::endl;

    return 0;
}