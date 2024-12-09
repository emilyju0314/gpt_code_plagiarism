#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<pair<int, int>> heroes(m);
    for(int i = 0; i < m; i++) {
        cin >> heroes[i].first >> heroes[i].second;
    }
    
    vector<int> board(n);
    for(int i = 0; i < n; i++) {
        cin >> board[i];
    }
    
    for(int i = 0; i < n; i++) {
        bool possible = true;
        
        vector<pair<int, int>> order;
        for(int j = 0; j < m; j++) {
            order.push_back({abs(i - heroes[j].first), j});
        }
        
        sort(order.begin(), order.end());
        
        for(auto& p : order) {
            int heroIndex = p.second;
            int step = i - heroes[heroIndex].first;
            
            if(step < 0) {
                for(int k = 0; k < -step; k++) {
                    if(board[heroes[heroIndex].first - k] < 0) {
                        possible = false;
                        break;
                    }
                }
            } else if(step > 0) {
                for(int k = 0; k < step; k++) {
                    if(board[heroes[heroIndex].first + k] < 0) {
                        possible = false;
                        break;
                    }
                }
            }
        }
        
        if(possible) {
            cout << i + 1 << endl;
            for(auto& p : order) {
                cout << p.second + 1 << " ";
            }
            cout << endl;
            return 0;
        }
    }
    
    cout << -1 << endl;
    
    return 0;
}