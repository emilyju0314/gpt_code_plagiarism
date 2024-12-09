#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> info(M, vector<int>(3));
    for(int i = 0; i < M; i++) {
        cin >> info[i][0] >> info[i][1] >> info[i][2];
    }

    vector<vector<int>> counts(N+1);
    vector<long long> operations(N+1, 0);

    for(int i = 0; i < M; i++) {
        counts[info[i][0]].push_back(info[i][2]);
        counts[info[i][1]].push_back(info[i][2]);
        if(info[i][0] != info[i][1]) {
            operations[info[i][1]] += info[i][2];
        }
    }

    long long ans = 0;
    for(int i = 1; i <= N; i++) {
        sort(counts[i].begin(), counts[i].end());
        if(counts[i].size() == 0) {
            ans = -1;
            break;
        }
        for(int j = 0; j < counts[i].size() - 1; j++) {
            ans += counts[i][j];
        }
    }

    for(int i = 1; i <= N; i++) {
        if(operations[i] < counts[i][counts[i].size() - 1]) {
            ans = -1;
            break;
        }
        ans += operations[i];
    }

    cout << ans << endl;

    return 0;
}