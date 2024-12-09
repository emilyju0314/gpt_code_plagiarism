#include <iostream>
#include <string>

using namespace std;

int main() {
    string commands;
    cin >> commands;

    int cnt = 0;
    int n = commands.size();

    for (int i = 0; i < n; i++) {
        if (commands[i] == 'R') {
            int j = i;
            bool is_valid = false;

            while (j < n && commands[j] == 'R') {
                j++;
            }

            while (j < n && commands[j] == 'L') {
                j++;
                is_valid = true;
            }

            if (j == n && is_valid) {
                cnt++;
            }

            i = j - 1;
        }
    }

    cout << cnt << endl;

    return 0;
}