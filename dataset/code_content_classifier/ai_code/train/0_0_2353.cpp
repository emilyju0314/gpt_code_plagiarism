#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    string s, t;
    cin >> s >> t;

    int count = 0;
    vector<pair<int, int>> operations;

    for (int i = 0; i < n; i++) {
        if (s[i] != t[i]) {
            bool found = false;
            for (int j = i + 1; j < n; j++) {
                if (s[j] == t[i] && t[j] == s[i]) {
                    swap(s[j], t[j]);
                    operations.push_back({j+1, j+1});
                    swap(s[j], t[i]);
                    operations.push_back({j+1, i+1});
                    count += 2;
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << -1 << endl;
                return 0;
            }
        }
    }

    cout << count << endl;
    for (auto operation : operations) {
        cout << operation.first << " " << operation.second << endl;
    }

    return 0;
}