#include <iostream>
#include <vector>
#include <algorithm>

struct Team {
    int id;
    int affiliation;
    int correct_answers;
    int penalty;
};

bool compare(Team t1, Team t2) {
    if (t1.correct_answers == t2.correct_answers) {
        if (t1.penalty == t2.penalty) {
            return t1.id < t2.id;
        }
        return t1.penalty < t2.penalty;
    }
    return t1.correct_answers > t2.correct_answers;
}

int main() {
    int n;
    while (std::cin >> n && n != 0) {
        std::vector<Team> teams(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> teams[i].id >> teams[i].affiliation >> teams[i].correct_answers >> teams[i].penalty;
        }

        std::sort(teams.begin(), teams.end(), compare);

        int selected_teams = 0;
        std::vector<int> selected_ids;
        for (int i = 0; i < n; ++i) {
            if (selected_teams < 10) {
                if (std::count_if(selected_ids.begin(), selected_ids.end(), [teams, i](int id) { return teams[i].affiliation == teams[id - 1].affiliation; }) < 3) {
                    selected_ids.push_back(teams[i].id);
                    selected_teams++;
                }
            } else if (selected_teams < 20) {
                if (std::count_if(selected_ids.begin(), selected_ids.end(), [teams, i](int id) { return teams[i].affiliation == teams[id - 1].affiliation; }) < 2) {
                    selected_ids.push_back(teams[i].id);
                    selected_teams++;
                }
            } else if (selected_teams < 26) {
                if (std::count_if(selected_ids.begin(), selected_ids.end(), [teams, i](int id) { return teams[i].affiliation == teams[id - 1].affiliation; }) == 0) {
                    selected_ids.push_back(teams[i].id);
                    selected_teams++;
                }
            }
        }

        for (int id : selected_ids) {
            std::cout << id << std::endl;
        }
    }

    return 0;
}