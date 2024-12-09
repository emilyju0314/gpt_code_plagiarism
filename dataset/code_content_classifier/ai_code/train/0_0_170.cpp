#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, s;
    std::cin >> n >> s;

    std::vector<int> a(n);
    for(int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    std::sort(a.begin(), a.end());

    int operations = 0;
    // Find the position of the median
    int median_pos = n / 2;

    // Calculate the number of operations needed to make the median equal to s
    if(a[median_pos] < s) {
        for(int i = median_pos; i < n; i++) {
            if(a[i] < s) {
                operations += s - a[i];
            } else {
                break;
            }
        }
    } else if(a[median_pos] > s) {
        for(int i = median_pos; i >= 0; i--) {
            if(a[i] > s) {
                operations += a[i] - s;
            } else {
                break;
            }
        }
    }

    std::cout << operations << std::endl;

    return 0;
}