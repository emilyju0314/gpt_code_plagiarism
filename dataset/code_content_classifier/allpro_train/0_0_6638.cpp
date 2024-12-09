#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    string s;

    cin >> n;
    cin >> s;

    int coins = 0;

    int x = 0, y = 0;
    bool is_first_kingdom = true;

    for (int i = 0; i < n; i++) {
        if (s[i] == 'U') {
            y++;
        } else {
            x++;
        }

        if (x > y && is_first_kingdom) {
            coins++;
            is_first_kingdom = false;
        } else if (y > x && !is_first_kingdom) {
            coins++;
            is_first_kingdom = true;
        }
    }

    cout << coins << endl;

    return 0;
}