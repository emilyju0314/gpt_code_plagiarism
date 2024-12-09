#include <iostream>
#include <vector>
using namespace std;

int main() {
    int H, W, K;
    cin >> H >> W >> K;

    vector<vector<int>> chocolate(H, vector<int>(W, 0));
    for(int i = 0; i < H; i++) {
        string line;
        cin >> line;
        for(int j = 0; j < W; j++) {
            chocolate[i][j] = line[j] - '0';
        }
    }

    int cuts = 0;
    for(int i = 0; i < (1 << (H - 1)); i++) {
        int num_cuts = 0;
        vector<int> cut_positions;
        for(int j = 0; j < H - 1; j++) {
            if(i & (1 << j)) {
                num_cuts++;
                cut_positions.push_back(j);
            }
        }

        vector<int> block_white(W, 0);
        int num_blocks = num_cuts + 1;
        for(int j = 0; j < W; j++) {
            for(int k = 0; k < H; k++) {
                if(chocolate[k][j] == 1) {
                    block_white[j]++;
                }
            }

            bool possible = true;
            for(int cut : cut_positions) {
                int white_in_block = 0;
                for(int k = 0; k < H; k++) {
                    if(k > cut && block_white[j] + block_white[j] > K) {
                        possible = false;
                        break;
                    }
                    white_in_block += chocolate[k][j];
                }
                if(possible && white_in_block > K) {
                    num_blocks++;
                    block_white = vector<int>(W, 0);
                }
            }
        }

        if(possible) {
            cuts = num_cuts;
            break;
        }
    }

    cout << cuts << endl;

    return 0;
}