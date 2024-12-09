#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    
    while (true) {
        std::cin >> n;
        if (n == 0) {
            break;
        }
        
        std::vector<int> scores;
        for (int i = 0; i < n; i++) {
            int score;
            std::cin >> score;
            scores.push_back(score);
        }
        
        std::sort(scores.begin(), scores.end());
        
        int total_score = 0;
        for (int i = 1; i < n - 1; i++) {
            total_score += scores[i];
        }
        
        int final_score = total_score / (n - 2);
        std::cout << final_score << std::endl;
    }
    
    return 0;
}