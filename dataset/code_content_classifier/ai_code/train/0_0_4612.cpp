#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    
    std::vector<std::pair<int, int>> players;
    for (int i = 0; i < n; ++i) {
        int skill;
        std::cin >> skill;
        players.push_back({skill, i+1});
    }
    
    std::sort(players.begin(), players.end(), std::greater<std::pair<int, int>>());
    
    int team_size = (n + 1) / 2;
    
    std::vector<int> team1, team2;
    for (int i = 0; i < n; ++i) {
        if (i < team_size) {
            team1.push_back(players[i].second);
        } else {
            team2.push_back(players[i].second);
        }
    }
    
    std::cout << team1.size() << std::endl;
    for (int player : team1) {
        std::cout << player << " ";
    }
    std::cout << std::endl;
    
    std::cout << team2.size() << std::endl;
    for (int player : team2) {
        std::cout << player << " ";
    }
    std::cout << std::endl;
    
    return 0;
}