#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int n, e;
    cin >> n >> e;

    vector<pair<int, int>> hate_pairs;
    for (int i = 0; i < e; i++) {
        int a, b;
        cin >> a >> b;
        hate_pairs.push_back({a, b});
    }

    vector<int> team_assignment(n);
    vector<int> conference_assignment(n, -1);

    for (int i = 0; i < n; i++) {
        int wish_list_size;
        cin >> wish_list_size;
        set<int> wish_list;
        for (int j = 0; j < wish_list_size; j++) {
            int team;
            cin >> team;
            wish_list.insert(team);
        }

        for (int team : wish_list) {
            bool assigned = false;

            for (int j = 0; j < n; j++) {
                if (team_assignment[j] == 0) {
                    if (conference_assignment[team - 1] == -1 || conference_assignment[team - 1] == 1) {
                        conference_assignment[team - 1] = 1;
                        assigned = true;
                    } else {
                        conference_assignment[team - 1] = 2;
                        assigned = true;
                    }
                    team_assignment[j] = team;
                    break;
                }
            }
            if (assigned) {
                break;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << team_assignment[i] << " ";
    }
    cout << endl;
    
    for (int i = 0; i < n; i++) {
        cout << conference_assignment[team_assignment[i] - 1] << " ";
    }
    cout << endl;

    return 0;
}