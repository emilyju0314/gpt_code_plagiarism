#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;

        int cnt = count(s.begin(), s.end(), '1');
        int first_one = s.find('1');

        int operations = (cnt > 0) + min(first_one, n - first_one);
        cout << operations << endl;
    }

    return 0;
}