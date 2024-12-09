#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int n, u, v, m;
    cin >> n >> u >> v >> m;

    vector<vector<int>> rabbit(n, vector<int>(n));
    vector<vector<int>> cat(n, vector<int>(n));

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> rabbit[i][j];
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> cat[i][j];
        }
    }

    set<int> rabbit_marked;
    set<int> cat_marked;
    int winner = 0;

    for(int i=0; i<m; i++) {
        int card;
        cin >> card;

        for(int j=0; j<n; j++) {
            for(int k=0; k<n; k++) {
                if(rabbit[j][k] == card) {
                    rabbit_marked.insert(j*n+k);
                }
                if(cat[j][k] == card) {
                    cat_marked.insert(j*n+k);
                }
            }
        }

        if(rabbit_marked.size() == n*n || cat_marked.size() == n*n) {
            if(rabbit_marked.size() == n*n && cat_marked.size() == n*n) {
                winner = 2;
            } else if(rabbit_marked.size() == n*n) {
                winner = 1;
            } else {
                winner = -1;
            }
            break;
        }
    }

    if(winner == 1) {
        cout << "USAGI" << endl;
    } else if(winner == -1) {
        cout << "NEKO" << endl;
    } else {
        cout << "DRAW" << endl;
    }

    return 0;
}