#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int main() {
    int n, m, k, w;
    cin >> n >> m >> k >> w;

    vector<string> levels(k);
    vector<pair<int, int>> transfer_order;
    vector<vector<int>> diffs;
    
    for(int i = 0; i < k; i++) {
        cin.ignore();
        for(int j = 0; j < n; j++) {
            string s;
            cin >> s;
            levels[i] += s;
        }
    }

    int total_bytes = 0;
    for(int i = 0; i < k; i++) {
        total_bytes += n * m;
    }

    cout << total_bytes << endl;

    for(int i = 0; i < k; i++) {
        bool transferred = false;

        for(int j = 0; j < i; j++) {
            int diff = 0;
            for(int l = 0; l < n * m; l++) {
                if(levels[i][l] != levels[j][l]) {
                    diff++;
                }
            }

            if(diff * w < n * m) {
                transfer_order.push_back({i + 1, j + 1});
                transferred = true;
                break;
            }
        }

        if(!transferred) {
            transfer_order.push_back({i + 1, 0});
        }
    }

    for(auto& p : transfer_order) {
        cout << p.first << " " << p.second << endl;
    }

    return 0;
}