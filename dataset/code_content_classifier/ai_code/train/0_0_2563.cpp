#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, p, s;
    std::cin >> n >> p >> s;

    std::vector<std::pair<int, int>> students(n);
    for(int i = 0; i < n; i++) {
        std::cin >> students[i].first;
    }

    for(int i = 0; i < n; i++) {
        std::cin >> students[i].second;
    }

    std::sort(students.begin(), students.end(), [&](const std::pair<int, int>& a, const std::pair<int, int>& b){
        return a.first > b.first;
    });

    int programmingStrength = 0;
    int sportsStrength = 0;

    std::vector<int> programmingTeam;
    for(int i = 0; i < p; i++) {
        programmingStrength += students[i].first;
        programmingTeam.push_back(students[i].second);
    }

    std::sort(programmingTeam.begin(), programmingTeam.end());

    std::vector<int> sportsTeam;
    for(int i = p; i < n; i++) {
        sportsTeam.push_back(students[i].second);
    }

    std::sort(sportsTeam.begin(), sportsTeam.end());

    for(int i = 0; i < s; i++) {
        sportsStrength += sportsTeam[i];
    }

    std::cout << programmingStrength + sportsStrength << std::endl;
    for(int student : programmingTeam) {
        std::cout << student << " ";
    }
    std::cout << std::endl;

    for(int student : sportsTeam) {
        std::cout << student << " ";
    }
    std::cout << std::endl;

    return 0;
}