#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int N;
    std::cin >> N;

    std::vector<std::pair<int, int>> balls;

    for(int i = 0; i < N; i++) {
        int x, y;
        std::cin >> x >> y;
        balls.push_back({x, y});
    }

    std::sort(balls.begin(), balls.end());
    
    long long R_max = balls[N - 1].first;
    long long R_min = balls[0].first;
    
    std::sort(balls.begin(), balls.end(), [](std::pair<int, int> a, std::pair<int, int> b){
        return a.second < b.second;
    });
    
    long long B_max = balls[N - 1].second;
    long long B_min = balls[0].second;

    long long result = (R_max - R_min) * (B_max - B_min);
    
    std::cout << result << std::endl;

    return 0;
}