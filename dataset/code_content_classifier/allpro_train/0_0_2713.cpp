#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <tuple>

using namespace std;

int main() {
    int m, n, k;
    cin >> m >> n >> k;
    
    vector<vector<char>> city(m, vector<char>(n));
    vector<vector<int>> time(m, vector<int>(n, -1));
    
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            cin >> city[i][j];
        }
    }
    
    int rs, cs, re, ce;
    string s;
    cin >> rs >> cs >> s >> re >> ce;
    
    time[rs-1][cs-1] = 0;
    queue<pair<int, int>> q;
    q.push(make_pair(rs-1, cs-1));
    
    while(!q.empty()) {
        int x, y;
        tie(x, y) = q.front();
        q.pop();
        
        // Check if time exceeded
        if(time[x][y] >= k) {
            cout << x+1 << " " << y+1 << endl;
            return 0;
        }
        
        // Up
        if(x > 0 && city[x-1][y] != '#' && time[x-1][y] == -1) {
            if(city[x-1][y] >= '0' && city[x-1][y] <= '9') {
                time[x-1][y] = time[x][y] + (city[x-1][y]-'0');
                q.push(make_pair(x-1, y));
            } else {
                time[x-1][y] = time[x][y] + 1;
                q.push(make_pair(x-1, y));
            }
        }
        
        // Down
        if(x < m-1 && city[x+1][y] != '#' && time[x+1][y] == -1) {
            if(city[x+1][y] >= '0' && city[x+1][y] <= '9') {
                time[x+1][y] = time[x][y] + (city[x+1][y]-'0');
                q.push(make_pair(x+1, y));
            } else {
                time[x+1][y] = time[x][y] + 1;
                q.push(make_pair(x+1, y));
            }
        }
        
        // Left
        if(y > 0 && city[x][y-1] != '#' && time[x][y-1] == -1) {
            if(city[x][y-1] >= '0' && city[x][y-1] <= '9') {
                time[x][y-1] = time[x][y] + (city[x][y-1]-'0');
                q.push(make_pair(x, y-1));
            } else {
                time[x][y-1] = time[x][y] + 1;
                q.push(make_pair(x, y-1));
            }
        }
        
        // Right
        if(y < n-1 && city[x][y+1] != '#' && time[x][y+1] == -1) {
            if(city[x][y+1] >= '0' && city[x][y+1] <= '9') {
                time[x][y+1] = time[x][y] + (city[x][y+1]-'0');
                q.push(make_pair(x, y+1));
            } else {
                time[x][y+1] = time[x][y] + 1;
                q.push(make_pair(x, y+1));
            }
        }
    }
    
    return 0;
}