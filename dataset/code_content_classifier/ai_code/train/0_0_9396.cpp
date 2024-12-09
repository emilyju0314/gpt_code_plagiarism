#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int w, h;
    cin >> w >> h;

    vector<string> image(h);
    for (int i = 0; i < h; i++) {
        cin >> image[i];
    }

    // Rotate the image 90 degrees clockwise
    vector<string> rotatedImage(w, string(h, '.'));
    for (int i = 0; i < w; i++) {
        for (int j = 0; j < h; j++) {
            rotatedImage[i][j] = image[h - 1 - j][i];
        }
    }

    // Flip the rotated image horizontally
    for (int i = 0; i < w; i++) {
        for (int j = 0; j < h; j++) {
            rotatedImage[i][j] = rotatedImage[i][w - 1 - j];
        }
    }

    // Zoom in on the image
    for (int i = 0; i < w; i++) {
        for (int j = 0; j < h; j++) {
            rotatedImage[i][2 * j] = rotatedImage[i][2 * j + 1] = rotatedImage[i][j];
        }
    }

    // Print the final image
    for (int i = 0; i < w; i++) {
        cout << rotatedImage[i] << endl;
        cout << rotatedImage[i] << endl;
    }

    return 0;
}