#include <iostream>
#include <vector>

using namespace std;

const int MAX_H = 1600;
const int MAX_W = 1600;

int h, w;
int image[MAX_H][MAX_W];
int raysCount[MAX_H][MAX_W];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0 ,-1};

bool isValid(int x, int y) {
    return x >= 0 && x < h && y >= 0 && y < w;
}

void floodFill(int x, int y, int sunId) {
    if(!isValid(x, y) || image[x][y] == 0 || raysCount[x][y] != 0) {
        return;
    }
    raysCount[x][y] = sunId;

    for(int i = 0; i < 4; i++) {
        floodFill(x + dx[i], y + dy[i], sunId);
    }
}

int main() {
    cin >> h >> w;

    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            cin >> image[i][j];
        }
    }

    int sunId = 0;
    vector<int> raysPerSun;

    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            if(image[i][j] == 1 && raysCount[i][j] == 0) {
                sunId++;
                int rays = 0;
                floodFill(i, j, sunId);
                for(int k = 0; k < h; k++) {
                    for(int l = 0; l < w; l++) {
                        if(raysCount[k][l] == sunId) {
                            rays++;
                        }
                    }
                }
                raysPerSun.push_back(rays);
            }
        }
    }

    cout << sunId << endl;

    sort(raysPerSun.begin(), raysPerSun.end());
    for(int i = 0; i < raysPerSun.size(); i++) {
        cout << raysPerSun[i] << " ";
    }
    cout << endl;

    return 0;
}