#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> universities(n);
        for (int i = 0; i < n; i++) {
            cin >> universities[i];
        }

        vector<int> skills(n);
        for (int i = 0; i < n; i++) {
            cin >> skills[i];
        }

        map<int, vector<int>, greater<int>> universitySkills;
        for (int i = 0; i < n; i++) {
            universitySkills[universities[i]].push_back(skills[i]);
        }

        for (const auto& entry : universitySkills) {
            sort(entry.second.begin(), entry.second.end(), greater<int>());
        }

        for (int k = 1; k <= n; k++) {
            long long totalStrength = 0;
            vector<int> teamSizes(n + 1, 0);

            for (const auto& entry : universitySkills) {
                int teamSize = 0;
                
                for (int skill : entry.second) {
                    if (teamSize < k) {
                        totalStrength += skill;
                        teamSize++;
                    } else {
                        break;
                    }
                }
                
                teamSizes[teamSize]++;
            }

            cout << totalStrength << " ";
        }

        cout << endl;
    }

    return 0;
}