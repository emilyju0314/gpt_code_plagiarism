#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> A(N), B(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i] >> B[i];
    }

    vector<pair<int, int>> cords(M);
    for (int j = 0; j < M; j++) {
        cin >> cords[j].first >> cords[j].second;
    }

    vector<int> cnt_bombs(M+1);
    for (int i = 0; i < N; i++) {
        cnt_bombs[A[i]] = B[i];
    }

    vector<int> cnt_switches(M+1);
    for (int j = 0; j < M; j++) {
        if (cnt_bombs[cords[j].first] != cnt_bombs[cords[j].second]) {
            cnt_switches[cords[j].first]++;
            cnt_switches[cords[j].second+1]--;
        }
    }

    vector<int> cumulative_switches(M+1);
    for (int i = 1; i <= M; i++) {
        cumulative_switches[i] = cumulative_switches[i-1] + cnt_switches[i];
    }

    bool possible = true;
    for (int i = 1; i <= M; i++) {
        if ((cumulative_switches[i] % 2) != cnt_bombs[i]) {
            possible = false;
            break;
        }
    }

    if (!possible) {
        cout << -1 << endl;
    } else {
        vector<int> cuts;
        for (int j = 0; j < M; j++) {
            if (cnt_switches[cords[j].first] % 2 == 1) {
                cuts.push_back(j+1);
            }
        }

        cout << cuts.size() << endl;
        for (int cut : cuts) {
            cout << cut << " ";
        }
        cout << endl;
    }

    return 0;
}