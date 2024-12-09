#include <iostream>
#include <vector>

using namespace std;

bool isImageSwapped(vector<vector<int>>& image) {
    int h = image.size();
    int w = image[0].size();
    
    for (int i = 0; i < h / 2; i++) {
        for (int j = 0; j < w; j++) {
            if (image[i][j] != image[i + h / 2][j]) {
                return true;
            }
        }
    }
    
    return false;
}

int main() {
    int q;
    cin >> q;
    
    int correctAnswers = 0;
    
    for (int i = 0; i < q; i++) {
        int h, w;
        cin >> h >> w;
        
        vector<vector<int>> image(h, vector<int>(w));
        
        for (int j = 0; j < h; j++) {
            for (int k = 0; k < w; k++) {
                cin >> image[j][k];
            }
        }
        
        if (isImageSwapped(image)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
            correctAnswers++;
        }
    }
    
    if (correctAnswers >= q * 0.75) {
        cout << "Gate is unlocked.";
    } else {
        cout << "Fan door opens.";
    }
    
    return 0;
}