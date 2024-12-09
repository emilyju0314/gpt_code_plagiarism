#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> sequences(n);
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        sequences[i].resize(k);
        for (int j = 0; j < k; j++) {
            cin >> sequences[i][j];
        }
    }
    
    vector<int> count(m + 1, 0);
    vector<int> lastSeen(200001, -1);
    
    for (int t = 0; t < 10100; t++) {
        for (int i = 0; i < n; i++) {
            int num = sequences[i][0];
            count[num] = max(count[num], t - lastSeen[num]);
            for (int j = 1; j < sequences[i].size(); j++) {
                sequences[i][j - 1] = sequences[i][j];
            }
            sequences[i][sequences[i].size() - 1] = num;
        }
    }
    
    for (int i = 1; i <= m; i++) {
        count[i] = max(count[i], 10100 - lastSeen[i]);
        cout << count[i] << endl;
    }
    
    return 0;
}