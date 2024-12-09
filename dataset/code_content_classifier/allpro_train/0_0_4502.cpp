#include <iostream>
#include <vector>

using namespace std;

const int n = 8;
vector<pair<int, int>> queens;

bool isSafe(int row, int col) {
    for (auto queen : queens) {
        int r = queen.first;
        int c = queen.second;
        if (r == row || c == col || abs(r - row) == abs(c - col)) {
            return false;
        }
    }
    return true;
}

void solve(int k) {
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            if (isSafe(row, col)) {
                queens.push_back({row, col});
                if (queens.size() == k) {
                    cout << "Solution:" << endl;
                    for (int i = 0; i < n; i++) {
                        for (int j = 0; j < n; j++) {
                            if (find(queens.begin(), queens.end(), make_pair(i, j)) != queens.end()) {
                                cout << "Q";
                            } else {
                                cout << ".";
                            }
                        }
                        cout << endl;
                    }
                    return;
                } else {
                    solve(k);
                }
                queens.pop_back();
            }
        }
    }
}

int main() {
    int k;
    cin >> k;

    queens.resize(k);
    for (int i = 0; i < k; i++) {
        int r, c;
        cin >> r >> c;
        queens[i] = {r, c};
    }

    solve(k);

    return 0;
}