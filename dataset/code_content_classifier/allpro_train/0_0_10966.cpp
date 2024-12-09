#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<vector<int>> problems(n, vector<int>(k));
    vector<int> teamCount(k, 0);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < k; j++) {
            cin >> problems[i][j];
            teamCount[j] += problems[i][j];
        }
    }

    for(int i = 0; i < n; i++) {
        bool valid = true;
        for(int j = 0; j < k; j++) {
            if(teamCount[j] - problems[i][j] >= (n + 1) / 2) {
                valid = false;
                break;
            }
        }
        if(valid) {
            cout << "YES" << endl;
            return 0;
        }
    }

    cout << "NO" << endl;

    return 0;
}