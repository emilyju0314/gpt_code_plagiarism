#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int main() {
    int n;
    while (cin >> n && n != 0) {
        vector<vector<int>> bars(n, vector<int>(4));
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 4; j++) {
                cin >> bars[i][j];
            }
        }
        
        int counts[10] = {0};
        for (int i = 0; i < n; i++) {
            int x1 = bars[i][0], y1 = bars[i][1];
            int x2 = bars[i][2], y2 = bars[i][3];
            
            int digit = -1;
            if (x1 == x2) {
                if (y1 < y2) {
                    digit = 0;
                } else {
                    digit = 9;
                }
            } else if (y1 == y2) {
                if (x1 < x2) {
                    digit = 6;
                } else {
                    digit = 5;
                }
            } else if (x1 < x2 && y1 < y2) {
                digit = 1;
            } else if (x1 < x2 && y1 > y2) {
                digit = 7;
            } else if (x1 > x2 && y1 < y2) {
                digit = 3;
            } else {
                digit = 2;
            }
            
            counts[digit]++;
        }
        
        for (int i = 0; i < 10; i++) {
            cout << counts[i] << " ";
        }
        cout << "\n";
    }
    
    return 0;
}