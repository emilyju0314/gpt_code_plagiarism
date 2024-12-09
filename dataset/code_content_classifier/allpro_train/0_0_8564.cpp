#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    int L1, L2, L3, L4;
    cin >> L1;
    vector<pair<int, int>> loved_men;
    for (int i = 0; i < L1; i++) {
        int a, b;
        cin >> a >> b;
        loved_men.push_back({a, b});
    }

    cin >> L2;
    vector<pair<int, int>> moderate_loved_men;
    for (int i = 0; i < L2; i++) {
        int c, d;
        cin >> c >> d;
        moderate_loved_men.push_back({c, d});
    }

    cin >> L3;
    set<pair<int, int>> loved_women;
    for (int i = 0; i < L3; i++) {
        int e, f;
        cin >> e >> f;
        loved_women.insert({e, f});
    }

    cin >> L4;
    set<pair<int, int>> moderate_loved_women;
    for (int i = 0; i < L4; i++) {
        int g, h;
        cin >> g >> h;
        moderate_loved_women.insert({g, h});
    }

    int loved_pairs = 0, moderate_loved_pairs = 0, moderate_pairs = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (loved_men[i].second == j && loved_women.count({i, j}) > 0) {
                loved_pairs++;
            } else if (moderate_loved_men[i].second == j && moderate_loved_women.count({i, j}) > 0) {
                moderate_loved_pairs++;
            }
        }
    }

    cout << loved_pairs << " " << moderate_loved_pairs << " " << moderate_pairs << endl;

    return 0;
}