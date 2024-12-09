#include <iostream>
#include <string>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    for (int i = 0; i < n; i++) {
        int distance = min('z' - s[i], k);
        s[i] = s[i] + distance;
        k -= distance;
    }

    if (k > 0) {
        cout << "-1" << endl;
    } else {
        cout << s << endl;
    }

    return 0;
}