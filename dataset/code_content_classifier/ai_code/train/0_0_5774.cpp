#include <iostream>
#include <vector>
using namespace std;

int main() {
    int H, W, K;
    cin >> H >> W >> K;

    vector<vector<char>> grid(H, vector<char>(W));
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            cin >> grid[i][j];
        }
    }

    int ans = 0;
    // Iterate over all possible combinations of choosing rows and columns
    for(int row_mask=0; row_mask < (1<<H); row_mask++){
        for(int col_mask=0; col_mask < (1<<W); col_mask++){
            // Count the number of black squares in the chosen rows and columns
            int black_count = 0;
            for(int i=0; i<H; i++){
                for(int j=0; j<W; j++){
                    if((row_mask & (1<<i)) || (col_mask & (1<<j))){
                        if(grid[i][j] == '#'){
                            black_count++;
                        }
                    }
                }
            }
            // If the number of remaining black squares matches K, increment the answer
            if(H*W - black_count == K){
                ans++;
            }
        }
    }

    cout << ans << endl;

    return 0;
}