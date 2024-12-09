#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> dice(6);
    
    for (int i = 0; i < 6; ++i) {
        std::cin >> dice[i];
    }
    
    int q;
    std::cin >> q;
    
    std::vector<std::pair<int, int>> questions(q);
    
    for (int i = 0; i < q; ++i) {
        std::cin >> questions[i].first >> questions[i].second;
    }
    
    std::vector<int> right_face = {2, 4, 3, 1};
    
    for(auto& q : questions) {
        int top_face = q.first;
        int front_face = q.second;
        
        int top_pos = std::find(dice.begin(), dice.end(), top_face) - dice.begin();
        int front_pos = std::find(dice.begin(), dice.end(), front_face) - dice.begin();
        
        // Find the position of the right face
        int right_pos;
        for (int i = 0; i < 4; ++i) {
            if (top_pos == i || top_pos == (i + 3) % 4) {
                int diff = (front_pos - i + 4) % 4;
                right_pos = right_face[diff];
                break;
            }
        }
        
        std::cout << dice[right_pos] << std::endl;
    }
    
    return 0;
}