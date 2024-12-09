#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<pair<int, int>> dominoes(n);
    for (int i = 0; i < n; i++) {
        cin >> dominoes[i].first >> dominoes[i].second;
    }
    
    vector<bool> used(n, false);
    vector<pair<int, char>> solution;
    
    auto can_place = [&](int idx) {
        return dominoes[idx].first == dominoes[idx].second;
    };
    
    auto make_move = [&](int idx, char orient) {
        solution.push_back({idx + 1, orient});
        used[idx] = true;
    };
    
    bool found = true;
    int last = -1;
    for (int i = 0; i < n; i++) {
        bool placed = false;
        for (int j = 0; j < n; j++) {
            if (!used[j] && can_place(j)) {
                if (last == -1 || dominoes[j].first == dominoes[last].second) {
                    make_move(j, '+');
                    last = j;
                    placed = true;
                    break;
                }
                if (dominoes[j].first == dominoes[last].first) {
                    make_move(j, '-');
                    last = j;
                    placed = true;
                    break;
                }
            }
        }
        if (!placed) {
            found = false;
            break;
        }
    }
    
    if (found) {
        for (auto p : solution) {
            cout << p.first << " " << p.second << endl;
        }
    } else {
        cout << "No solution";
    }
    
    return 0;
}