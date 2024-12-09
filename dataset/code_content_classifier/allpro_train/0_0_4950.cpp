#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<pair<int, int>> start_positions(k);
    vector<pair<int, int>> end_positions(k);

    for(int i = 0; i < k; i++) {
        cin >> start_positions[i].first >> start_positions[i].second;
    }

    for(int i = 0; i < k; i++) {
        cin >> end_positions[i].first >> end_positions[i].second;
    }

    string actions = "";
    int total_steps = 0;

    for(int i = 0; i < k; i++) {
        int steps = abs(start_positions[i].first - end_positions[i].first) + abs(start_positions[i].second - end_positions[i].second);
        total_steps += steps;
        for(int j = 0; j < abs(start_positions[i].first - end_positions[i].first); j++) {
            if(end_positions[i].first > start_positions[i].first) {
                actions += "D";
            } else {
                actions += "U";
            }
        }
        for(int j = 0; j < abs(start_positions[i].second - end_positions[i].second); j++) {
            if(end_positions[i].second > start_positions[i].second) {
                actions += "R";
            } else {
                actions += "L";
            }
        }
        actions += "LR";
        total_steps += 2;
    }

    cout << total_steps << endl;
    cout << actions << endl;

    return 0;
}