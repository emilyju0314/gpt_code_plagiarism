#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int lenS, lenT;
    string S, T;
    cin >> lenS >> lenT;
    cin >> S >> T;

    vector<int> positions;
    for (int i = 0; i <= lenS - lenT; i++) {
        bool possible = true;
        for (int j = 0; j < lenT; j++) {
            if (S[i + j] != T[j]) {
                possible = false;
                break;
            }
        }
        if (possible) {
            positions.push_back(i+1);
        }
    }

    cout << positions.size() << endl;
    for (int i = 0; i < positions.size(); i++) {
        cout << positions[i] << " ";
    }
    cout << endl;

    return 0;
}