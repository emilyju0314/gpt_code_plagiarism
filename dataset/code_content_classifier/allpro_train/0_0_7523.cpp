#include <iostream>
#include <vector>

using namespace std;

bool isRectangle(const vector<string>& analysis, int H, int W) {
    // Find the coordinates of the top-left and bottom-right corners of the rectangle
    int top = H, bottom = -1, left = W, right = -1;
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            if(analysis[i][j] != '.') {
                top = min(top, i);
                bottom = max(bottom, i);
                left = min(left, j);
                right = max(right, j);
            }
        }
    }
    
    // Check if the non-rectangle items are present in the analysis
    for(int i = top; i <= bottom; i++) {
        for(int j = left; j <= right; j++) {
            if(analysis[i][j] == '.') {
                return false;
            }
        }
    }
    
    return true;
}

int main() {
    int datasets;
    cin >> datasets;
    
    for(int i = 0; i < datasets; i++) {
        int H, W;
        cin >> H >> W;
        
        vector<string> analysis(H);
        for(int j = 0; j < H; j++) {
            cin >> analysis[j];
        }
        
        if(isRectangle(analysis, H, W)) {
            cout << "SAFE" << endl;
        } else {
            cout << "SUSPICIOUS" << endl;
        }
    }
    
    return 0;
}