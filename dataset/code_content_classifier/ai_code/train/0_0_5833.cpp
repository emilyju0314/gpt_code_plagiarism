#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> dances(m, vector<int>(3));
    vector<int> colors(n, 0);

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < 3; j++) {
            cin >> dances[i][j];
        }
    }

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < 3; j++) {
            if(colors[dances[i][j] - 1] == 0) {
                for(int k = 1; k <= 3; k++) {
                    if(find(begin(colors), end(colors), k) == end(colors)) {
                        colors[dances[i][j] - 1] = k;
                        break;
                    }
                }
            }
        }
    }

    for(int i = 0; i < n; i++) {
        cout << colors[i] << " ";
    }

    return 0;
}