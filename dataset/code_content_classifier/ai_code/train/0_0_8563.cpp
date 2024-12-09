#include <iostream>
#include <vector>

using namespace std;

int main() {
    int h, w;
    
    while (true) {
        cin >> h >> w;
        
        if (h == 0 && w == 0) {
            break;
        }
        
        vector<vector<char>> map(h, vector<char>(w));
        
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cin >> map[i][j];
            }
        }
        
        int min_chests = 0;
        
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (map[i][j] == '*') {
                    continue;
                }
                
                int neighbors = 0;
                
                if (map[i][j] == '.') {
                    neighbors = 9;
                } else {
                    neighbors = map[i][j] - '0';
                }
                
                min_chests += neighbors;
            }
        }
        
        cout << min_chests << endl;
    }
    
    return 0;
}