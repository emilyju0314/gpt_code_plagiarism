#include <iostream>
#include <string>

using namespace std;

int main() {
    string colors;
    cin >> colors;

    int operations = 0;
    bool deleted = true;

    while (deleted) {
        deleted = false;
        string newColors = "";
        for (int i = 0; i < colors.size(); i++) {
            if (i > 0 && i < colors.size() - 1 && colors[i-1] != colors[i] && colors[i+1] != colors[i]) {
                deleted = true;
                i++;
            } else {
                newColors += colors[i];
            }
        }
        colors = newColors;
        if (deleted) {
            operations++;
        }
    }

    cout << operations << endl;

    return 0;
}