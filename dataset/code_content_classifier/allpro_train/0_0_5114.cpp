#include <iostream>
#include <string>

using namespace std;

int main() {
    int x1, y1, x2, y2, n;
    cin >> x1 >> y1 >> x2 >> y2 >> n;

    string s;
    cin >> s;

    int days = 0;
    int current_x = x1, current_y = y1;

    for (int i = 0; i < n; i++) {
        if (s[i] == 'U') {
            current_y++;
        } else if (s[i] == 'D') {
            current_y--;
        } else if (s[i] == 'L') {
            current_x--;
        } else { // 'R'
            current_x++;
        }

        if (current_x == x2 && current_y == y2) {
            days = i + 1;
            break;
        }
    }

    if (current_x == x2 && current_y == y2) {
        cout << days << endl;
    } else {
        int diff_x = x2 - current_x;
        int diff_y = y2 - current_y;
        int remaining_distance = abs(diff_x) + abs(diff_y);

        if (remaining_distance <= n) {
            cout << n + (remaining_distance % 2) << endl;
        } else {
            cout << -1 << endl;
        }
    }

    return 0;
}