#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>
using namespace std;

bool isValid(vector<string>& pieces, const string& restored, int index) {
    for (string piece : pieces) {
        for (int i = 0; i < piece.size(); i++) {
            if (restored[index + i] != '.' && restored[index + i] != piece[i]) {
                return false;
            }
        }
    }
    return true;
}

void generatePossibleEssays(vector<string>& pieces, int d, const string& altered, string& restored, set<string>& possibleEssays, int index = 0) {
    if (index == altered.size()) {
        possibleEssays.insert(restored);
        return;
    }

    if (!isValid(pieces, restored, index)) {
        return;
    }

    for (int i = 0; i < pieces.size(); i++) {
        string temp = restored;
        for (int j = 0; j < pieces[i].size(); j++) {
            if (temp[index + j] == '.' || temp[index + j] == pieces[i][j]) {
                temp[index + j] = pieces[i][j];
            }
        }
        generatePossibleEssays(pieces, d, altered, temp, possibleEssays, index + pieces[i].size());
    }

    if (d > 0) {
        for (char c = 'A'; c <= 'Z'; c++) {
            string temp = restored;
            for (int j = 0; j < pieces[0].size(); j++) {
                if (temp[index + j] == '.' || temp[index + j] == c) {
                    temp[index + j] = c;
                }
            }
            generatePossibleEssays(pieces, d - 1, altered, temp, possibleEssays, index + 1);
        }
    }
}

int main() {
    int d, n;
    while (cin >> d >> n && d != 0 && n != 0) {
        string altered;
        cin >> altered;

        vector<string> pieces(n);
        for (int i = 0; i < n; i++) {
            cin >> pieces[i];
        }

        set<string> possibleEssays;
        string restored(altered.size(), '.');
        generatePossibleEssays(pieces, d, altered, restored, possibleEssays);

        cout << possibleEssays.size() << endl;
        if (possibleEssays.size() <= 5) {
            for (const string& essay : possibleEssays) {
                cout << essay << endl;
            }
        }
    }

    return 0;
}