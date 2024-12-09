#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int t;
    std::cin >> t;

    while(t--) {
        int n;
        std::cin >> n;

        std::vector<int> segments(n);
        for(int i = 0; i < n; i++) {
            std::cin >> segments[i];
        }

        int current_start = 0;
        int current_end = 0;
        int total_length = 0;

        for(int i = 0; i < n; i++) {
            if(i == 0) {
                current_end = segments[i];
                total_length = current_end;
            } else {
                if(segments[i] > 0) {
                    current_end += segments[i];
                    total_length = std::max(total_length, current_end);
                } else {
                    current_end += segments[i];
                    total_length = std::max(total_length, -current_end);
                }
            }
        }

        std::cout << total_length << std::endl;
    }

    return 0;
}