#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    int min_operations = n;

    for (int i = 1; i < n; i++) {
        string prefix = s.substr(0, i);
        string suffix = s.substr(i);

        if (suffix + prefix == s) {
            int operations = i + 1 + (n-i)/2;
            min_operations = min(min_operations, operations);
        }
    }

    cout << min_operations << endl;

    return 0;
}