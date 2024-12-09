#include <iostream>
#include <vector>

int main() {
    int n, k;
    std::cin >> n >> k;
    
    std::vector<int> videos(n);
    for (int i = 0; i < n; i++) {
        std::cin >> videos[i];
    }
    
    int total_duration = 0;
    for (int video_duration : videos) {
        total_duration += video_duration;
    }
    
    if (total_duration % k != 0) {
        std::cout << "No" << std::endl;
        return 0;
    }
    
    int target_duration = total_duration / k;
    
    int current_duration = 0;
    std::vector<int> post_sizes;
    int current_post_size = 0;
    
    for (int i = 0; i < n; i++) {
        current_duration += videos[i];
        current_post_size++;
        
        if (current_duration == target_duration) {
            post_sizes.push_back(current_post_size);
            current_post_size = 0;
            current_duration = 0;
        } else if (current_duration > target_duration) {
            std::cout << "No" << std::endl;
            return 0;
        }
    }
    
    if (post_sizes.size() != k) {
        std::cout << "No" << std::endl;
    } else {
        std::cout << "Yes" << std::endl;
        for (int post_size : post_sizes) {
            std::cout << post_size << " ";
        }
        std::cout << std::endl;
    }
    
    return 0;
}