#include <iostream>
#include <vector>

using namespace std;

bool isValidBlock(vector<string>& block, int w, int d, int h) {
    int count = 0;
    for (int i = 0; i < d; i++) {
        for (int j = 0; j < w; j++) {
            if (block[i][j] == '*') count++;
        }
    }
    return count == h;
}

bool canFormRectangularSolid(vector<vector<string>>& blocks, int W, int D, int H) {
    int count = 0;
    for (int k = 0; k < blocks.size(); k++) {
        if (isValidBlock(blocks[k], blocks[k].size(), blocks[k][0].size(), blocks[k][0][0].size()) {
            count++;
        }
    }
    return count == W * D * H;
}

int main() {
    int W, D, H, N;
    
    while (cin >> W >> D >> H >> N) {
        if (W == 0 && D == 0 && H == 0 && N == 0) break;
        
        vector<vector<string>> blocks(N);
        
        for (int i = 0; i < N; i++) {
            int w, d, h;
            cin >> w >> d >> h;
            
            for (int j = 0; j < h; j++) {
                vector<string> block;
                for (int k = 0; k < d; k++) {
                    string row;
                    cin >> row;
                    block.push_back(row);
                }
                blocks[i].push_back(block);
            }
        }
        
        if (canFormRectangularSolid(blocks, W, D, H)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    
    return 0;
}