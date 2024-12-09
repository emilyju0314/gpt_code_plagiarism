#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Team {
    int id, total_time;
};

bool compareTeams(Team t1, Team t2) {
    return t1.total_time < t2.total_time;
}

int main() {
    int n;
    
    while (cin >> n) {
        if (n == 0) {
            break;
        }
        
        vector<Team> teams(n);
        
        for (int i = 0; i < n; i++) {
            cin >> teams[i].id;
            int m1, s1, m2, s2, m3, s3, m4, s4;
            cin >> m1 >> s1 >> m2 >> s2 >> m3 >> s3 >> m4 >> s4;
            teams[i].total_time = m1 * 60 + s1 + m2 * 60 + s2 + m3 * 60 + s3 + m4 * 60 + s4;
        }
        
        sort(teams.begin(), teams.end(), compareTeams);
        
        cout << teams[n-1].id << endl; // Winner
        cout << teams[n-2].id << endl; // Runner-up
        cout << teams[1].id << endl; // Booby Award
    }
    
    return 0;
}