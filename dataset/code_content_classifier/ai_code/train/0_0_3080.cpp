#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> vertical_lines, horizontal_lines;

    for (int x = -108; x <= 108; x++) {
        cout << "0 " << x << " 0" << endl; // Querying each x-coordinate
        cout.flush();

        int min_distance;
        cin >> min_distance;

        if (min_distance == 0) {
            vertical_lines.push_back(x);
        }
    }

    for (int y = -108; y <= 108; y++) {
        cout << "0 0 " << y << endl; // Querying each y-coordinate
        cout.flush();

        int min_distance;
        cin >> min_distance;

        if (min_distance == 0) {
            horizontal_lines.push_back(y);
        }
        if ((int) horizontal_lines.size() >= 104) break;
    }

    cout << "1 " << vertical_lines.size() << " " << horizontal_lines.size() << endl;
    for (int line : vertical_lines) {
        cout << line << " ";
    }
    cout << endl;

    for (int line : horizontal_lines) {
        cout << line << " ";
    }
    cout << endl;

    return 0;
}