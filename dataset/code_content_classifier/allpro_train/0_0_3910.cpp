#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n, vector<int>(n, 0));
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a-1][b-1] = 1;
        graph[b-1][a-1] = 1;
    }

    int max_dominoes = 0;
    for(int i = 0; i < (1 << n); i++) {
        bool valid = true;
        vector<int> count(n, 0);
        for(int j = 0; j < n; j++) {
            if((i >> j) & 1) {
                for(int k = 0; k < n; k++) {
                    if(((i >> k) & 1) && graph[j][k]) {
                        count[j]++;
                    }
                }
                if(count[j] > 6) {
                    valid = false;
                    break;
                }
            }
        }
        if(valid) {
            int sum = 0;
            for(int j = 0; j < n; j++) {
                sum += min(6, count[j]);
            }
            max_dominoes = max(max_dominoes, sum / 2);
        }
    }

    cout << max_dominoes << endl;

    return 0;
}