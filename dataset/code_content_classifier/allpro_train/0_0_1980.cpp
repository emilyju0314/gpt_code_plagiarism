#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int N;
    while (std::cin >> N && N != 0) {
        std::vector<int> colors(N);
        for (int i = 0; i < N; i++) {
            std::cin >> colors[i];
        }
        
        int min_remaining = N;
        for (int i = 0; i < N; i++) {
            std::vector<int> temp_colors = colors;
            int current_color = temp_colors[i];
            int count = 1;
            bool change_made = false;
            for (int j = i + 1; j < N; j++) {
                if (temp_colors[j] == current_color) {
                    count++;
                } else {
                    count = 1;
                    current_color = temp_colors[j];
                }
                
                if (count >= 4) {
                    if (!change_made || (j + 1 == N) || (j + 1 < N && temp_colors[j + 1] != current_color)) {
                        min_remaining = std::min(min_remaining, N - count);
                        break;
                    } else {
                        change_made = false;
                        count = 1;
                    }
                }
                
                if (!change_made) {
                    temp_colors[j] = current_color;
                    change_made = true;
                }
            }
        }
        
        std::cout << min_remaining << std::endl;
    }
    
    return 0;
}