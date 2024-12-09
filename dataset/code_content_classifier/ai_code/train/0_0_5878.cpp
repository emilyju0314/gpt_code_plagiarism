#include <iostream>
#include <vector>

using namespace std;

struct Component {
    char color;
    int connected;
    vector<pair<int,int>> pixels;
};

bool surround(Component& a, Component& b) {
    for (auto& pixA : a.pixels) {
        for (auto& pixB : b.pixels) {
            int dx = pixA.first - pixB.first;
            int dy = pixA.second - pixB.second;
            if (dx >= -1 && dx <= 1 && dy >= -1 && dy <= 1) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    int h, w;
    while (cin >> h >> w && h != 0 && w != 0) {
        vector<vector<char>> image1(h, vector<char>(w));
        vector<vector<char>> image2(h, vector<char>(w));

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cin >> image1[i][j];
            }
        }

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cin >> image2[i][j];
            }
        }

        vector<Component> components1, components2;
        vector<pair<int,int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

        char color = 'A';
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (image1[i][j] == '.' || image1[i][j] == '#') {
                    Component comp;
                    comp.color = image1[i][j];
                    comp.connected = 0;
                    components1.push_back(comp);
                }
            }
        }

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (components1[i].pixels.empty() && (image1[i][j] == '.' || image1[i][j] == '#')) {
                    components1[i].color = image1[i][j];
                }
                if (image1[i][j] == components1[i].color) {
                    components1[i].connected++;
                    components1[i].pixels.push_back({i, j});
                    for (auto& dir : directions) {
                        int ni = i + dir.first;
                        int nj = j + dir.second;
                        if (ni >= 0 && ni < h && nj >= 0 && nj < w && image1[ni][nj] == components1[i].color) {
                            components1[i].connected++;
                            components1[i].pixels.push_back({ni, nj});
                        }
                    }
                }
            }
        }

        color = 'A';
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (image2[i][j] == '.' || image2[i][j] == '#') {
                    Component comp;
                    comp.color = image2[i][j];
                    comp.connected = 0;
                    components2.push_back(comp);
                }
            }
        }

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (components2[i].pixels.empty() && (image2[i][j] == '.' || image2[i][j] == '#')) {
                    components2[i].color = image2[i][j];
                }
                if (image2[i][j] == components2[i].color) {
                    components2[i].connected++;
                    components2[i].pixels.push_back({i, j});
                    for (auto& dir : directions) {
                        int ni = i + dir.first;
                        int nj = j + dir.second;
                        if (ni >= 0 && ni < h && nj >= 0 && nj < w && image2[ni][nj] == components2[i].color) {
                            components2[i].connected++;
                            components2[i].pixels.push_back({ni, nj});
                        }
                    }
                }
            }
        }

        if (components1.size() != components2.size()) {
            cout << "no" << endl;
            continue;
        }

        bool same = true;
        for (int i = 0; i < components1.size(); i++) {
            bool found = false;
            for (int j = 0; j < components2.size(); j++) {
                if (components2[j].color == components1[i].color && components2[j].connected == components1[i].connected) {
                    found = true;
                    bool s = surround(components1[i], components2[j]);
                    if (!s) {
                        same = false;
                        break;
                    }
                    break;
                }
            }
            if (!found) {
                same = false;
                break;
            }
        }

        if (same) {
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }
    }

    return 0;
}