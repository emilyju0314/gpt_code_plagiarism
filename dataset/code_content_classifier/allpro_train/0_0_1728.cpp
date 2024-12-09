#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int W, H, N;
    cin >> W >> H >> N;
    
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    
    vector<vector<int>> grid(H, vector<int>(W, 0));
    
    for(int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        
        int T;
        string pattern;
        cin >> T >> pattern;
        
        for(int j = 0; j < T; j++) {
            for(char c : pattern) {
                if(c == 'U' && y > 0) y--;
                else if(c == 'D' && y < H - 1) y++;
                else if(c == 'L' && x > 0) x--;
                else if(c == 'R' && x < W - 1) x++;
                
                if((x == x1 && y == y1) || (x == x2 && y == y2)) grid[y][x]++;
            }
        }
    }
    
    cout << *max_element(grid.begin(), grid.end()) << endl;
    
    return 0;
}