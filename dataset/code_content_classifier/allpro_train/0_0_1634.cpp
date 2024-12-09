#include <iostream>
#include <vector>

int main() {
    int N, k;
    
    while (std::cin >> N && N != 0) {
        std::vector<int> prizes(N);
        int min_challenges = -1;
        
        for (int i = 0; i < N; i++) {
            std::cin >> prizes[i];
            if (prizes[i] >= 2) {
                if (min_challenges == -1) {
                    min_challenges = 2;
                } else {
                    min_challenges = std::min(min_challenges, 2);
                }
            }
        }
        
        std::cout << (min_challenges == -1 ? "NA" : std::to_string(min_challenges)) << std::endl;
    }
    
    return 0;
}