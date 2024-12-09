#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> ones;

    for(int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        ones.push_back({x, y});
    }

    vector<vector<int>> matrix(n, vector<int>(n, 0));
    for(auto& p : ones) {
        matrix[p.first - 1][p.second - 1] = 1;
    }

    vector<pair<int, int>> actions;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i > j) {
                if(matrix[i][j] == 1) {
                    actions.push_back({1, i+1});
                    actions.push_back({1, j+1});
                    for(int k = 0; k < n; k++) {
                        swap(matrix[i][k], matrix[j][k]);
                    }
                }
            }
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i > j) {
                if(matrix[j][i] == 1) {
                    actions.push_back({2, i+1});
                    actions.push_back({2, j+1});
                    for(int k = 0; k < n; k++) {
                        swap(matrix[k][i], matrix[k][j]);
                    }
                }
            }
        }
    }

    cout << actions.size() << endl;
    for(auto& a : actions) {
        cout << a.first << " " << a.second << " ";
        if(a.first == 1) {
            cout << a.second << endl;
        } else {
            cout << a.second + n << endl;
        }
    }

    return 0;
}