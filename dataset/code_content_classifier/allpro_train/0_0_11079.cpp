#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

bool canBuildBicube(int H, int W, vector<string>& sheet) {
    int count[26] = {0};
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (isalpha(sheet[i][j])) {
                count[sheet[i][j]-'a']++;
                if (count[sheet[i][j]-'a'] > 2) {
                    return false;
                }
            }
        }
    }

    for (int i = 0; i < 26; i++) {
        if (count[i] == 1) {
            return false;
        }
    }

    return true;
}

int main() {
    int H, W;
    cin >> H >> W;
    vector<string> sheet(H);
    for (int i = 0; i < H; i++) {
        cin >> sheet[i];
    }

    if (canBuildBicube(H, W, sheet)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}