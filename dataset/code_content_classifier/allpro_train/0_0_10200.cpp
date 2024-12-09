#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    vector<vector<int>> moves;
    vector<int> opened(N, 0);

    for (int i = 0; i < K; i++) {
        int idx = 0;
        bool found = false;
        while (idx < N && opened[idx] >= a[idx]) {
            idx++;
        }

        if (idx == N) {
            cout << -1 << endl;
            return 0;
        }

        opened[idx]++;
        moves.push_back({idx + 1});
        found = true;

        if (found) {
            int box = idx;
            while (box < N) {
                if (opened[box] < a[box]) {
                    moves.push_back({box + 1});
                    opened[box]++;
                }
                box++;
            }
        }
    }

    cout << moves.size() << endl;
    for (auto move : moves) {
        for (int box : move) {
            cout << box << " ";
        }
    }
    cout << endl;

    return 0;
}