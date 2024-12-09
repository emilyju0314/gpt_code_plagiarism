#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

struct Team {
    string name;
    int points;
    int goals_scored;
    int goals_missed;
};

int compareTeams(const Team& t1, const Team& t2) {
    if (t1.points == t2.points) {
        if ((t1.goals_scored - t1.goals_missed) == (t2.goals_scored - t2.goals_missed)) {
            if (t1.goals_scored == t2.goals_scored) {
                return t1.name.compare(t2.name) > 0;
            }
            return t1.goals_scored < t2.goals_scored;
        }
        return (t1.goals_scored - t1.goals_missed) < (t2.goals_scored - t2.goals_missed);
    }
    return t1.points < t2.points;
}

int main() {
    vector<Team> teams;
    map<string, Team> teamMap;
    
    for (int i = 0; i < 5; i++) {
        string team1, team2, result;
        cin >> team1 >> team2 >> result;
        
        int sep = result.find(':');
        int goals1 = stoi(result.substr(0, sep));
        int goals2 = stoi(result.substr(sep + 1));
        
        // Update team 1
        if (teamMap.find(team1) == teamMap.end()) {
            Team t;
            t.name = team1;
            t.points = 0;
            t.goals_scored = 0;
            t.goals_missed = 0;
            teamMap[team1] = t;
        }
        teamMap[team1].goals_scored += goals1;
        teamMap[team1].goals_missed += goals2;
        if (goals1 > goals2) teamMap[team1].points += 3;
        else if (goals1 == goals2) teamMap[team1].points += 1;
        
        // Update team 2
        if (teamMap.find(team2) == teamMap.end()) {
            Team t;
            t.name = team2;
            t.points = 0;
            t.goals_scored = 0;
            t.goals_missed = 0;
            teamMap[team2] = t;
        }
        teamMap[team2].goals_scored += goals2;
        teamMap[team2].goals_missed += goals1;
        if (goals2 > goals1) teamMap[team2].points += 3;
        else if (goals2 == goals1) teamMap[team2].points += 1;
    }
    
    for (auto const& tm : teamMap) {
        teams.push_back(tm.second);
    }
    
    sort(teams.begin(), teams.end(), compareTeams);
    
    Team berland = teamMap["BERLAND"];
    
    int max_score_diff = -1;
    pair<int, int> best_score = {-1, -1};
    
    for (int i = 1; i <= 9; i++) {
        for (int j = 0; j < i; j++) {
            berland.goals_scored += i;
            berland.goals_missed += j;
            
            int current_score_diff = berland.goals_scored - berland.goals_missed;
            if (current_score_diff > max_score_diff && (current_score_diff > 0 || i - j > 0)) {
                vector<Team> tempTeams = teams;
                tempTeams.push_back(berland);
                
                sort(tempTeams.begin(), tempTeams.end(), compareTeams);
                
                if (tempTeams[tempTeams.size() - 1].name == berland.name || tempTeams[tempTeams.size() - 2].name == berland.name) {
                    max_score_diff = current_score_diff;
                    best_score = {i, j};
                }
            }
            
            berland.goals_scored -= i;
            berland.goals_missed -= j;
        }
    }
    
    if (best_score.first == -1) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        cout << best_score.first << ":" << best_score.second << endl;
    }
    
    return 0;
}