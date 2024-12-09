#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> c(n);
    for(int i = 0; i < n; i++) {
        cin >> c[i];
    }
    
    vector<vector<int>> table(n);
    for(int i = 0; i < n; i++) {
        table[i].resize(c[i]);
        for(int j = 0; j < c[i]; j++) {
            cin >> table[i][j];
        }
    }
    
    vector<pair<int, int>> swaps;
    
    for(int i = n-1; i >= 1; i--) {
        for(int j = c[i]-1; j >= 0; j--) {
            int num = table[i][j];
            int x = i, y = j+1;
            while(x >= 1 && y < c[x-1]) {
                swaps.push_back({x, y, x-1, y});
                swap(table[x][y], table[x-1][y]);
                y++;
            }
        }
    }
    
    cout << swaps.size() << endl;
    for(auto s : swaps) {
        cout << s.first << " " << s.second+1 << " " << s.third+1 << " " << s.fourth+1 << endl;
    }
    
    return 0;
}