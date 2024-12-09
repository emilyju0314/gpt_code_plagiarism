#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int m, n, k, t;
    cin >> m >> n >> k >> t;

    vector<int> agility(m);
    for(int i = 0; i < m; i++) {
        cin >> agility[i];
    }

    vector<pair<int, pair<int, int>>> traps(k);
    for(int i = 0; i < k; i++) {
        cin >> traps[i].second.first >> traps[i].first >> traps[i].second.second;
    }

    sort(traps.begin(), traps.end());

    int soldiers_saved = 0;
    int time = 0;
    int current_trap_idx = 0;

    int i = 0;
    while(i < m) {
        if(time >= t) break;
        
        int next_pos = n + 1 - time;

        while(current_trap_idx < k && traps[current_trap_idx].first == next_pos) {
            if(traps[current_trap_idx].second.second < agility[i]) {
                soldiers_saved++;
            }
            current_trap_idx++;
        }

        if(current_trap_idx < k && traps[current_trap_idx].first == next_pos - 1) {
            if(traps[current_trap_idx].second.second >= agility[i]) {
                time += 2;
                i++;
                continue;
            }
        }

        time++;
        i++;
    }

    cout << m - soldiers_saved << endl;

    return 0;
}