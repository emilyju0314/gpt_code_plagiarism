#include <iostream>
#include <vector>

int main() {
    int n, k;
    std::cin >> n >> k;

    std::vector<int> participation(n);
    for (int i = 0; i < n; i++) {
        std::cin >> participation[i];
    }

    int teams = 0;
    std::vector<int> team_count(6, 0);

    for (int i = 0; i < n; i++) {
        team_count[participation[i]]++;
    }

    for (int i = 0; i < 6; i++) {
        teams += team_count[i] / 3;
    }

    int final_teams = teams;

    for (int i = 0; i < 6; i++) {
        if (team_count[i] >= k) {
            int temp_teams = (team_count[i] - k) / 3;
            if (temp_teams <= teams) {
                final_teams += temp_teams;
            }
        }
    }

    std::cout << final_teams << std::endl;

    return 0;
}