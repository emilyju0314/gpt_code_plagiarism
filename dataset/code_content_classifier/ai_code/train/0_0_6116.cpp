#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m1, m2, t;
    cin >> n >> m1 >> m2 >> t;

    vector<int> obstacles1(m1);
    vector<int> obstacles2(m2);

    for (int i = 0; i < m1; i++) {
        cin >> obstacles1[i];
    }

    for (int i = 0; i < m2; i++) {
        cin >> obstacles2[i];
    }

    sort(obstacles1.begin(), obstacles1.end());
    sort(obstacles2.begin(), obstacles2.end());

    vector<int> transitions;
    vector<pair<int, int>> shots;

    int currLane = 1;
    int reloadTime = t;
    int nextObstacle1 = 0;
    int nextObstacle2 = 0;
    
    bool possible = true;

    int shotCount = 0;

    for (int i = 1; i <= n; i++) {
        if (currLane == 1 && nextObstacle1 < m1 && obstacles1[nextObstacle1] == i) {
            if (reloadTime < t) {
                possible = false;
                break;
            }
            shots.push_back(make_pair(i, 1));
            nextObstacle1++;
            reloadTime = 0;
            shotCount++;
        } else if (currLane == 2 && nextObstacle2 < m2 && obstacles2[nextObstacle2] == i) {
            if (reloadTime < t) {
                possible = false;
                break;
            }
            shots.push_back(make_pair(i, 2));
            nextObstacle2++;
            reloadTime = 0;
            shotCount++;
        }

        if (i == n) {
            if (currLane == 1) {
                transitions.push_back(i + 1);
            }
            break;
        }

        if (currLane == 1) {
            if (nextObstacle2 < m2 && obstacles2[nextObstacle2] == i + 1) {
                transitions.push_back(i);
                currLane = 2;
            }
        } else {
            if (nextObstacle1 < m1 && obstacles1[nextObstacle1] == i + 1) {
                transitions.push_back(i);
                currLane = 1;
            }
        }

        reloadTime++;
    }

    if (possible) {
        cout << "Yes" << endl;
        cout << transitions.size() << endl;
        for (int transition : transitions) {
            cout << transition << " ";
        }
        cout << endl;

        cout << shotCount << endl;
        for (auto shot : shots) {
            cout << shot.first << " " << shot.second << endl;
        }
    } else {
        cout << "No" << endl;
    }

    return 0;
}