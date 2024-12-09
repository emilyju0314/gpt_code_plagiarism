#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<pair<int, int>>> rules(n); // stores the rules for each server
    vector<int> servers(2*n, 4); // number of processes on each server

    for(int i = 0; i < 4*n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        rules[a-1].push_back({b-1, c-1});
    }

    queue<int> next_rules; // stores the order of rules to be applied
    vector<bool> visited(4*n, false);

    for(int i = 0; i < n; i++) {
        if(servers[i] == 8) {
            next_rules.push(i);
            visited[i] = true;
        }
    }

    while(!next_rules.empty()) {
        int current = next_rules.front();
        next_rules.pop();

        for(auto p : rules[current]) {
            if(servers[p.first] < 8 && servers[p.second] < 8) {
                servers[p.first]++;
                servers[p.second]++;
                if(servers[p.first] == 8 && !visited[p.first]) {
                    next_rules.push(p.first);
                    visited[p.first] = true;
                }
                if(servers[p.second] == 8 && !visited[p.second]) {
                    next_rules.push(p.second);
                    visited[p.second] = true;
                }
                cout << current + 1 << " ";
            }
        }
    }

    bool possible = true;
    for(int i = 0; i < 2*n; i++) {
        if(servers[i] < 8) {
            possible = false;
            break;
        }
    }

    if(possible) {
        cout << "\nYES";
    } else {
        cout << "\nNO";
    }

    return 0;
}