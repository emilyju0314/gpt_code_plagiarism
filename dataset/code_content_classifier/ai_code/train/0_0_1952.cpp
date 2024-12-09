#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, pair<string, int>>> participants;
    for (int i = 0; i < n; i++) {
        string name;
        int region, score;
        cin >> name >> region >> score;
        participants.push_back({score, {name, region}});
    }

    sort(participants.begin(), participants.end(), greater<pair<int, pair<string, int>>>());

    vector<set<string>> region_teams(m+1); // +1 to account for 1-based indexing
    for (int i = 0; i < n; i++) {
        int region = participants[i].second.second;
        string name = participants[i].second.first;

        if (region_teams[region].size() >= 2) {
            continue;
        }

        bool team_found = false;
        for (int j = 1; j <= m; j++) {
            if (j != region && region_teams[j].size() < 2) {
                region_teams[j].insert(name);
                region_teams[j].insert(participants[i+1].second.first);
                team_found = true;
                break;
            }
        }

        if (!team_found) {
            region_teams[region].insert(name);
        }
    }

    for (int i = 1; i <= m; i++) {
        if (region_teams[i].size() == 2) {
            for (auto name : region_teams[i]) {
                cout << name << " ";
            }
            cout << endl;
        } else {
            cout << "?" << endl;
        }
    }

    return 0;
}