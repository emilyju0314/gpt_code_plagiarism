#include <iostream>
#include <vector>
#include <algorithm>

struct Team {
    int referenceNumber;
    int correctAnswers;
};

bool compareTeams(const Team& team1, const Team& team2) {
    return team1.correctAnswers > team2.correctAnswers;
}

int main() {
    std::vector<Team> teams;
    
    int referenceNumber, correctAnswers;
    while (true) {
        std::cin >> referenceNumber >> correctAnswers;
        if (referenceNumber == 0 && correctAnswers == 0) {
            break;
        }
        teams.push_back({referenceNumber, correctAnswers});
    }
    
    std::sort(teams.begin(), teams.end(), compareTeams);
    
    int inquiry;
    while (std::cin >> inquiry) {
        int rank = 1;
        for (const Team& team : teams) {
            if (team.referenceNumber == inquiry) {
                std::cout << rank << std::endl;
                break;
            }
            rank++;
        }
    }

    return 0;
}