#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

char mix_colors(char color1, char color2) {
    if (color1 == 'R') {
        if (color2 == 'Y') return 'W';
        else if (color2 == 'B') return 'M';
    } else if (color1 == 'Y') {
        if (color2 == 'R') return 'W';
        else if (color2 == 'B') return 'C';
    } else if (color1 == 'B') {
        if (color2 == 'R') return 'M';
        else if (color2 == 'Y') return 'C';
    }
    return 'W';
}

int main() {
    int n, k;
    cin >> n >> k;

    unordered_map<int, char> palette;
    vector<pair<string, vector<int>>> operations;

    for (int i = 0; i < k; i++) {
        string op;
        int m;
        cin >> op >> m;
        vector<int> indexes;
        for (int j = 0; j < m; j++) {
            int index;
            cin >> index;
            indexes.push_back(index);
        }
        operations.push_back({op, indexes});
    }

    bool possible = true;

    for (int i = 0; i < n; i++) {
        char color = '.';
        palette[i+1] = color;
    }

    for (auto operation : operations) {
        if (operation.first == "mix") {
            char mixed_color = operation.second.back();
            operation.second.pop_back();
            for (int index : operation.second) {
                if (palette[index] == '.') continue;
                if (palette[index] == mixed_color) palette[index] = '.';
                else if (palette[index] == '.') palette[index] = mixed_color;
                else if (palette[index] != mixed_color) possible = false;
            }
        } else {
            char color1, color2;
            if (operation.first == "RY") {
                color1 = 'R';
                color2 = 'Y';
            } else if (operation.first == "RB") {
                color1 = 'R';
                color2 = 'B';
            } else if (operation.first == "YB") {
                color1 = 'Y';
                color2 = 'B';
            }

            for (int index : operation.second) {
                if (palette[index] == color1) palette[index] = color2;
                else if (palette[index] == color2) palette[index] = color1;
            }
        }
    }

    if (!possible) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        for (int i = 0; i < n; i++) {
            cout << palette[i+1];
        }
        cout << endl;
    }

    return 0;
}