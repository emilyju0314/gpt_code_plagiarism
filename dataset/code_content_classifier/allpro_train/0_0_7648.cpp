#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    string left_wall, right_wall;
    cin >> left_wall >> right_wall;

    vector<bool> left_safe(n, false);
    vector<bool> right_safe(n, false);

    for (int i = 0; i < n; i++) {
        if (left_wall[i] != 'X') left_safe[i] = true;
        if (right_wall[i] != 'X') right_safe[i] = true;
    }

    vector<bool> possible(n, false);
    possible[0] = true;

    for (int i = 0; i < n; i++) {
        if (!possible[i]) continue;
        if (i + k >= n || left_wall[i + k] == '-' || right_wall[i + k] == '-') {
            cout << "YES" << endl;
            return 0;
        }
        
        if (i + 1 < n && left_safe[i + 1]) possible[i + 1] = true;
        if (i - 1 >= 0 && left_safe[i - 1]) possible[i - 1] = true;
        if (i + k < n && right_safe[i + k]) possible[i + k] = true;
    }

    cout << "NO" << endl;

    return 0;
}