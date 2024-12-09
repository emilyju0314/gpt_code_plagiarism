#include <iostream>
#include <vector>
#include <algorithm>

struct Team {
    std::string name;
    int wins;
    int losses;
    int draws;
    int points;
};

bool compareTeams(const Team& team1, const Team& team2) {
    if (team1.points != team2.points) {
        return team1.points > team2.points; // Sort by points in descending order
    } else {
        return false; // Maintain order of input when points are tied
    }
}

int main() {
    int n;
    while (std::cin >> n && n != 0) {
        std::cin.ignore(); // Ignore newline character
        std::vector<Team> teams(n);
        
        for (int i = 0; i < n; i++) {
            Team team;
            std::cin >> team.name >> team.wins >> team.losses >> team.draws;
            team.points = team.wins * 3 + team.draws;
            teams[i] = team;
        }
        
        std::sort(teams.begin(), teams.end(), compareTeams);
        
        for (const Team& team : teams) {
            std::cout << team.name << "," << team.points << std::endl;
        }
        
        std::cout << std::endl; // Print blank line between datasets
    }
    
    return 0;
}