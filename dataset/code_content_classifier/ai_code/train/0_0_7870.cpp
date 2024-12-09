#include <iostream>
#include <string>
#include <vector>

using namespace std;

int countMatches(vector<string>& image, vector<string>& pattern) {
    int count = 0;

    int h = image.size();
    int w = image[0].size();

    int p = pattern.size();

    for(int i = 0; i <= h - p; i++) {
        for(int j = 0; j <= w - p; j++) {
            bool match = true;
            for(int k = 0; k < p; k++) {
                for(int l = 0; l < p; l++) {
                    if(image[i+k][j+l] != pattern[k][l]) {
                        match = false;
                        break;
                    }
                }
                if(!match) {
                    break;
                }
            }

            if(match) {
                count++;
            }
        }
    }

    return count;
}

int main() {
    int w, h, p;

    while(cin >> w >> h >> p) {
        if(w == 0 && h == 0 && p == 0) {
            break;
        }

        vector<string> image(h);
        vector<string> pattern(p);

        for(int i = 0; i < h; i++) {
            cin >> image[i];
        }

        for(int i = 0; i < p; i++) {
            cin >> pattern[i];
        }

        int matches = countMatches(image, pattern);
        cout << matches << endl;
    }

    return 0;
}