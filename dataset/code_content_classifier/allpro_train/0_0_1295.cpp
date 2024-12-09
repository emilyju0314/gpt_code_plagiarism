#include <iostream>
#include <vector>

using namespace std;

int main() {
    int R, C;
    
    while (true) {
        cin >> R >> C;
        
        if (R == 0 && C == 0) {
            break;
        }
        
        vector<vector<int>> crackers(R, vector<int>(C));
        
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                cin >> crackers[i][j];
            }
        }
        
        int max_shipped = 0;
        
        for (int mask = 0; mask < (1 << R); mask++) {
            int sum = 0;
            
            for (int i = 0; i < R; i++) {
                int count_front = 0;
                
                for (int j = 0; j < C; j++) {
                    count_front += crackers[i][j] ^ ((mask >> i) & 1);
                }
                
                sum += max(count_front, C - count_front);
            }
            
            max_shipped = max(max_shipped, sum);
        }
        
        cout << max_shipped << endl;
    }
    
    return 0;
}