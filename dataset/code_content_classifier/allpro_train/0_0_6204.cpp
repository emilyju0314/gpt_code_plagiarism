#include <iostream>
#include <string>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    string s, t;
    cin >> s >> t;

    for (int i = k; i <= n - k; i++) {
        string first_substring = s.substr(0, k);
        string second_substring = s.substr(i, k);
        string concatenated = first_substring + second_substring;

        if (concatenated.find(t) != string::npos) {
            cout << "Yes" << endl;
            cout << 1 << " " << i + 1 << endl;
            return 0;
        }
    }

    cout << "No" << endl;

    return 0;
}