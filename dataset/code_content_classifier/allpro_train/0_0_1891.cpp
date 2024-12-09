#include <iostream>
#include <vector>
#include <algorithm>

struct Team {
    char name;
    int wins;
    int losses;
};

bool compareTeams(Team t1, Team t2) {
    if (t1.wins > t2.wins) {
        return true;
    } else if (t1.wins == t2.wins && t1.losses < t2.losses) {
        return true;
    } else {
        return false;
    }
}

int main() {
    int n;
    
    while (std::cin >> n && n != 0) {
        std::vector<Team> teams(n);
        
        for (int i = 0; i < n; i++) {
            teams[i].wins = 0;
            teams[i].losses = 0;
            std::cin >> teams[i].name;
            for (int j = 0; j < n - 1; j++) {
                int result;
                std::cin >> result;
                if (result == 0) {
                    teams[i].wins++;
                } else if (result == 1) {
                    teams[i].losses++;
                }
            }
        }
        
        std::sort(teams.begin(), teams.end(), compareTeams);
        
        for (int i = 0; i < n; i++) {
            std::cout << teams[i].name << std::endl;
        }
    }
    
    return 0;
}