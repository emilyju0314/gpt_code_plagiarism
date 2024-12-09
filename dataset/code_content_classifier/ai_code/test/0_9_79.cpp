#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    
    std::vector<int> height(n);
    for(int i = 0; i < n; i++) {
        std::cin >> height[i];
    }

    std::vector<int> slip(n);
    for(int i = 0; i < n; i++) {
        std::cin >> slip[i];
    }

    std::vector<int> jumps(n, -1);
    jumps[0] = 0;
    for(int i = 0; i < n; i++) {
        if(jumps[i] == -1) continue;
        for(int j = height[i]; j >= 0; j--) {
            int new_height = i + j - slip[i + j];
            if(new_height < 0) continue;
            if(jumps[new_height] == -1 || jumps[new_height] > jumps[i] + 1) {
                jumps[new_height] = jumps[i] + 1;
            }
        }
    }

    if(jumps[0] == -1) {
        std::cout << -1 << std::endl;
    } else {
        int curr_height = 0;
        std::vector<int> result;
        while(curr_height != 0) {
            result.push_back(curr_height);
            for(int j = height[curr_height]; j >= 0; j--) {
                int new_height = curr_height + j - slip[curr_height + j];
                if(new_height >= 0 && jumps[new_height] == jumps[curr_height] - 1) {
                    curr_height = new_height;
                    break;
                }
            }
        }
        result.push_back(0);
        std::cout << jumps[0] << std::endl;
        for(int i = result.size() - 1; i >= 0; i--) {
            std::cout << result[i] << " ";
        }
    }

    return 0;
}