#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> potential(n);
    vector<int> club(n);
    vector<vector<int>> remaining_students(m+1);
    vector<set<int>> club_potentials(m+1);

    for(int i = 0; i < n; i++) {
        cin >> potential[i];
    }

    for(int i = 0; i < n; i++) {
        cin >> club[i];
        club_potentials[club[i]].insert(potential[i]);
        remaining_students[club[i]].push_back(i);
    }

    int d;
    cin >> d;

    for(int i = 0; i < d; i++) {
        int leaving_student;
        cin >> leaving_student;

        int club_idx = club[leaving_student - 1];
        club_potentials[club_idx].erase(potential[leaving_student - 1]);

        for(auto idx : remaining_students[club_idx]) {
            if(idx == leaving_student - 1) {
                remaining_students[club_idx].erase(find(remaining_students[club_idx].begin(), remaining_students[club_idx].end(), idx));
                break;
            }
        }

        if(club_potentials[club_idx].empty()) {
            for(auto idx : remaining_students[club_idx]) {
                club_potentials[club_idx].insert(potential[idx]);
            }
        }

        int max_team_strength = -1;
        for(int j = 1; j <= m; j++) {
            if(!club_potentials[j].empty()) {
                int mex = 0;
                for(auto it : club_potentials[j]) {
                    if(it == mex) {
                        mex++;
                    } else {
                        break;
                    }
                }
                max_team_strength = max(max_team_strength, mex);
            }
        }

        cout << max_team_strength << endl;
    }

    return 0;
}