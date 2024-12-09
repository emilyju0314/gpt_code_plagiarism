#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int h, w;
vector<string> pattern;

bool checkRepeat(string str, int x, int y, int dx, int dy) {
    for (int i = 0; i < str.size(); i++) {
        int nx = x + dx * i;
        int ny = y + dy * i;
        if (pattern[ny][nx] != str[i]) {
            return false;
        }
    }
    return true;
}

string findMagicSpell(int x, int y) {
    string magicSpell = "";
    for (int dx = -1; dx <= 1; dx++) {
        for (int dy = -1; dy <= 1; dy++) {
            if (dx == 0 && dy == 0) continue;
            for (int len = 2; len <= min(h, w); len++) {
                for (int i = 0; i < len; i++) {
                    int nx = x + dx * i;
                    int ny = y + dy * i;
                    if (nx < 0 || nx >= w || ny < 0 || ny >= h) {
                        break;
                    }
                    if (!checkRepeat(magicSpell + pattern[y][x], x, y, dx, dy)) {
                        break;
                    }
                    magicSpell += pattern[y][x];
                }
            }
        }
    }
    return magicSpell;
}

int main() {
    while (true) {
        cin >> h >> w;
        if (h == 0 && w == 0) {
            break;
        }

        pattern.clear();
        for (int i = 0; i < h; i++) {
            string row;
            cin >> row;
            pattern.push_back(row);
        }

        string magicSpell = "0";
        for (int y = 0; y < h; y++) {
            for (int x = 0; x < w; x++) {
                string spell = findMagicSpell(x, y);
                if (spell.size() > magicSpell.size() || (spell.size() == magicSpell.size() && spell < magicSpell)) {
                    magicSpell = spell;
                }
            }
        }

        cout << magicSpell << endl;
    }

    return 0;
}