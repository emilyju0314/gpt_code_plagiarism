#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<string> cards(n);
    for (int i = 0; i < n; i++) {
        cin >> cards[i];
    }

    vector<bool> colors(5, false);
    vector<bool> values(5, false);

    for (const string& card : cards) {
        char color = card[0];
        char value = card[1];

        if (color == 'R') colors[0] = true;
        else if (color == 'G') colors[1] = true;
        else if (color == 'B') colors[2] = true;
        else if (color == 'Y') colors[3] = true;
        else if (color == 'W') colors[4] = true;

        values[value - '1'] = true;
    }

    int colorHints = 0;
    for (bool color : colors) {
        if (color) colorHints++;
    }

    int valueHints = 0;
    for (bool value : values) {
        if (value) valueHints++;
    }

    cout << min(colorHints, valueHints) << endl;

    return 0;
}