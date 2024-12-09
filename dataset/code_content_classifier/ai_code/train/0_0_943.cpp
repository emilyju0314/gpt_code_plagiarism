#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool isStable(vector<vector<int>>& pieces, int n, int w) {
    for (int i = 0; i < w; i++) {
        vector<int> heights;
        for (int j = 0; j < n; j++) {
            if (pieces[j][i] != 0) {
                heights.push_back(j);
            }
        }
        if (heights.size() == 0) continue;
        
        int maxY = *max_element(heights.begin(), heights.end());
        int minY = *min_element(heights.begin(), heights.end());
        int totalHeight = maxY - minY + 1;
        int centerOfMass = 0;
        
        for (int j = 0; j < n; j++) {
            if (pieces[j][i] != 0) {
                centerOfMass += (maxY - j);
            }
        }
        centerOfMass /= totalHeight;
        
        if (centerOfMass != i) {
            return false;
        }
    }
    return true;
}

int main() {
    int w, h;
    while (true) {
        cin >> w >> h;
        if (w == 0 && h == 0) break;
        
        vector<vector<int>> pieces(h, vector<int>(w));
        
        for (int i = 0; i < h; i++) {
            string row;
            cin >> row;
            for (int j = 0; j < w; j++) {
                if (row[j] == '.') {
                    pieces[i][j] = 0;
                } else {
                    pieces[i][j] = row[j] - '0';
                }
            }
        }
        
        if (isStable(pieces, h, w)) {
            cout << "STABLE" << endl;
        } else {
            cout << "UNSTABLE" << endl;
        }
    }
    
    return 0;
}