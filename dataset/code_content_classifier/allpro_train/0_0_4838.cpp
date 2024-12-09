#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

struct Submission {
    int elapsed_time;
    int team_number;
    int problem_number;
    int judgment;
};

bool compareTeams(const std::pair<int, int>& team1, const std::pair<int, int>& team2, const std::unordered_map<int, int>& solved_problems, const std::unordered_map<int, std::vector<Submission>>& submissions) {
    int solved_problems_team1 = solved_problems.at(team1.second);
    int solved_problems_team2 = solved_problems.at(team2.second);

    if (solved_problems_team1 != solved_problems_team2) {
        return solved_problems_team1 > solved_problems_team2;
    }

    int total_time_team1 = 0;
    int total_time_team2 = 0;
    for (const auto& sub : submissions.at(team1.second)) {
        total_time_team1 += (sub.judgment == 0) ? sub.elapsed_time : 20;
    }
    for (const auto& sub : submissions.at(team2.second)) {
        total_time_team2 += (sub.judgment == 0) ? sub.elapsed_time : 20;
    }

    if (total_time_team1 != total_time_team2) {
        return total_time_team1 < total_time_team2;
    }

    return team1.second < team2.second;
}

int main() {
    int M, T, P, R;
    while (std::cin >> M >> T >> P >> R, M || T || P || R) {
        std::unordered_map<int, std::vector<Submission>> submissions;
        std::unordered_map<int, int> solved_problems;

        for (int i = 0; i < R; ++i) {
            Submission sub;
            std::cin >> sub.elapsed_time >> sub.team_number >> sub.problem_number >> sub.judgment;
            submissions[sub.team_number].push_back(sub);

            if (sub.judgment == 0) {
                solved_problems[sub.team_number]++;
            }
        }

        std::vector<std::pair<int, int>> teams;
        for (const auto& entry : solved_problems) {
            teams.push_back({entry.second, entry.first});
        }

        std::sort(teams.begin(), teams.end(), [&](const std::pair<int, int>& team1, const std::pair<int, int>& team2) {
            return compareTeams(team1, team2, solved_problems, submissions);
        });

        for (auto it = teams.begin(); it != teams.end(); ++it) {
            std::cout << it->second;
            if (std::next(it) != teams.end()) {
                std::cout << ",";
            } else {
                std::cout << std::endl;
            }
        }
    }

    return 0;
}