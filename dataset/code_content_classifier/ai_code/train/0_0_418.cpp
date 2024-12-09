#include <iostream>
#include <vector>

using namespace std;

int main() {
    int H, W;
    cin >> H >> W;
    
    vector<vector<int>> A(H, vector<int>(W));
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            cin >> A[i][j];
        }
    }
    
    vector<vector<int>> B(H, vector<int>(W));
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            cin >> B[i][j];
        }
    }
    
    int h, w;
    cin >> h >> w;
    
    vector<vector<int>> C(h, vector<int>(w));
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            cin >> C[i][j];
        }
    }
    
    int maxScore = -1;
    for(int x = 0; x <= H - h; x++) {
        for(int y = 0; y <= W - w; y++) {
            bool match = true;
            int score = 0;
            for(int i = 0; i < h; i++) {
                for(int j = 0; j < w; j++) {
                    if(B[x + i][y + j] == C[i][j]) {
                        score += A[x + i][y + j];
                    } else {
                        match = false;
                        break;
                    }
                }
                if(!match) break;
            }
            if(match) {
                maxScore = max(maxScore, score);
            }
        }
    }
    
    if(maxScore == -1) {
        cout << "NA" << endl;
    } else {
        cout << maxScore << endl;
    }
    
    return 0;
}