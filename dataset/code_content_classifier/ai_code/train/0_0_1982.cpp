#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Trapezoid {
    int area;
    int count;
};

bool isTrapezoid(vector<string>& picture, int x, int y) {
    if (x + 2 >= picture.size() || y + 2 >= picture[0].size()) {
        return false;
    }
    if (picture[x][y] == '*' && picture[x + 1][y - 1] == '*' && picture[x + 1][y] == '*' && picture[x + 1][y + 1] == '*' && picture[x + 2][y] == '*') {
        return true;
    }
    return false;
}

int calculateArea(vector<string>& picture, int x, int y) {
    int area = 1;
    int x0 = x;
    int y0 = y;
    while (x < picture.size() && y >= 0 && y < picture[0].size() && picture[x][y] == '*') {
        area++;
        x++;
        y--;
    }
    x = x0 + 1;
    y = y0;
    while (x < picture.size() && y < picture[0].size() && picture[x][y] == '*') {
        area++;
        x++;
    }
    x = x0 + 1;
    y = y0;
    while (x < picture.size() && y < picture[0].size() && picture[x][y] == '*') {
        area++;
        x++;
    }
    x = x0 + 1;
    y = y0 + 1;
    while (x < picture.size() && y < picture[0].size() && picture[x][y] == '*') {
        area++;
        x++;
        y++;
    }
    x = x0 + 2;
    y = y0;
    while (y < picture[0].size() && picture[x][y] == '*') {
        area++;
        y++;
    }
    return area;
}

int main() {
    vector<vector<string>> pictures;
    vector<Trapezoid> trapezoids;

    while (true) {
        int h;
        cin >> h;
        if (h == 0) {
            break;
        }
        vector<string> picture;
        for (int i = 0; i < h; i++) {
            string line;
            cin >> line;
            picture.push_back(line);
        }
        pictures.push_back(picture);
    }

    for (int i = 0; i < pictures.size(); i++) {
        vector<string> picture = pictures[i];
        trapezoids.clear();

        for (int x = 0; x < picture.size(); x++) {
            for (int y = 0; y < picture[x].size(); y++) {
                if (picture[x][y] == '*' && isTrapezoid(picture, x, y)) {
                    int area = calculateArea(picture, x, y);
                    bool found = false;
                    for (int j = 0; j < trapezoids.size(); j++) {
                        if (trapezoids[j].area == area) {
                            trapezoids[j].count++;
                            found = true;
                            break;
                        }
                    }
                    if (!found) {
                        Trapezoid trapezoid = {area, 1};
                        trapezoids.push_back(trapezoid);
                    }
                }
            }
        }

        sort(trapezoids.begin(), trapezoids.end(), [](Trapezoid a, Trapezoid b) {
            return a.area < b.area;
        });

        for (int j = 0; j < trapezoids.size(); j++) {
            cout << trapezoids[j].area << " " << trapezoids[j].count << endl;
        }
        if (i < pictures.size() - 1) {
            cout << "----------" << endl;
        }
    }

    return 0;
}