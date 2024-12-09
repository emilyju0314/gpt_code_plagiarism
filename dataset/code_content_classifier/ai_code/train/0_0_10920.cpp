#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<string> volunteers(n);
    for (int i = 0; i < n; i++) {
        cin >> volunteers[i];
    }

    vector<vector<int>> dislike(n, vector<int>(n, 0));
    for (int i = 0; i < m; i++) {
        string a, b;
        cin >> a >> b;
        int idxA = find(volunteers.begin(), volunteers.end(), a) - volunteers.begin();
        int idxB = find(volunteers.begin(), volunteers.end(), b) - volunteers.begin();
        dislike[idxA][idxB] = dislike[idxB][idxA] = 1;
    }

    int maxTeamSize = 1 << n;
    vector<string> result;
    for (int mask = 0; mask < maxTeamSize; mask++) {
        bool validTeam = true;
        vector<string> currentTeam;
        
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                for (string& member : currentTeam) {
                    int idxA = find(volunteers.begin(), volunteers.end(), member) - volunteers.begin();
                    if (dislike[idxA][i] == 1) {
                        validTeam = false;
                        break;
                    }
                }
                
                if (!validTeam) {
                    break;
                }
                
                currentTeam.push_back(volunteers[i]);
            }
        }

        if (validTeam && currentTeam.size() > result.size()) {
            result = currentTeam;
        }
    }

    cout << result.size() << endl;
    sort(result.begin(), result.end());
    for (const string& member : result) {
        cout << member << endl;
    }

    return 0;
}