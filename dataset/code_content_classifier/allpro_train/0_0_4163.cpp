#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    int count = 0;
    for (int i = 1; i < n; ++i) {
        if (s[i] == s[i-1]) {
            count++;
            if (i < n-1 && s[i] == s[i+1]) {
                // Change color to any of the other two colors
                if (s[i] != 'R' && s[i+1] != 'R') {
                    s[i] = 'R';
                } else if (s[i] != 'G' && s[i+1] != 'G') {
                    s[i] = 'G';
                } else {
                    s[i] = 'B';
                }
            }
        }
    }

    cout << count << endl;
    cout << s << endl;

    return 0;
}