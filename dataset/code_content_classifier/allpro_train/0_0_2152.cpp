#include <iostream>
#include <vector>

using namespace std;

int main() {
    int H, W, N;
    cin >> H >> W >> N;
    
    vector<vector<bool>> grid(H, vector<bool>(W, false));
    
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        grid[a-1][b-1] = true;
    }
    
    vector<int> counts(10, 0);
    
    for (int i = 0; i < H-2; i++) {
        for (int j = 0; j < W-2; j++) {
            int black_count = 0;
            for (int r = i; r < i+3; r++) {
                for (int c = j; c < j+3; c++) {
                    if (grid[r][c]) black_count++;
                }
            }
            counts[black_count]++;
        }
    }
    
    for (int count : counts) {
        cout << count << endl;
    }
    
    return 0;
}