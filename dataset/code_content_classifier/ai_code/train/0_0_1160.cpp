#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

struct Team {
    string name;
    int points;
    int goals_scored;
    int goals_conceded;
};

bool comparator(const Team& t1, const Team& t2) {
    if (t1.points != t2.points) {
        return t1.points > t2.points;
    }
    if (t1.goals_scored - t1.goals_conceded != t2.goals_scored - t2.goals_conceded) {
        return t1.goals_scored - t1.goals_conceded > t2.goals_scored - t2.goals_conceded;
    }
    return t1.goals_scored > t2.goals_scored;
}

int main() {
    int n;
    cin >> n;
    
    vector<Team> teams(n);
    map<string, int> team_index;
    
    for (int i = 0; i < n; i++) {
        cin >> teams[i].name;
        teams[i].points = 0;
        teams[i].goals_scored = 0;
        teams[i].goals_conceded = 0;
        team_index[teams[i].name] = i;
    }
    
    for (int i = 0; i < n * (n - 1) / 2; i++) {
        string team1, team2;
        char dash;
        int score1, score2;
        cin >> team1 >> dash >> team2 >> score1 >> dash >> score2;
        
        int index1 = team_index[team1];
        int index2 = team_index[team2];
        
        teams[index1].goals_scored += score1;
        teams[index1].goals_conceded += score2;
        teams[index2].goals_scored += score2;
        teams[index2].goals_conceded += score1;
        
        if (score1 > score2) {
            teams[index1].points += 3;
        } else if (score1 < score2) {
            teams[index2].points += 3;
        } else {
            teams[index1].points += 1;
            teams[index2].points += 1;
        }
    }
    
    sort(teams.begin(), teams.end(), comparator);
    
    for (int i = 0; i < n / 2; i++) {
        cout << teams[i].name << endl;
    }
    
    return 0;
}