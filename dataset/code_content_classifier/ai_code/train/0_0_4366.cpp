#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;

    int maxPile = 1;
    int n = s.length();

    for (int i = 0; i < n; i++) {
        int cnt = 1;
        int left = i - 1;
        int right = i + 1;

        // Check to the left
        while (left >= 0 && s[left] == s[i]) {
            cnt++;
            left--;
        }

        // Check to the right
        while (right < n && s[right] == s[i]) {
            cnt++;
            right++;
        }

        maxPile = max(maxPile, cnt);
    }

    cout << maxPile << endl;

    return 0;
}