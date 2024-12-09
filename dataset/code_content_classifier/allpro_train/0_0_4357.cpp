#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int k;
    cin >> k;

    string s;
    cin >> s;

    int n;
    cin >> n;

    vector<pair<int, char>> changes;
    for (int i = 0; i < n; i++) {
        int p;
        char c;
        cin >> p >> c;
        changes.push_back(make_pair(p, c));
    }

    string final_name = s;
    for (int i = n - 1; i >= 0; i--) {
        int p = changes[i].first;
        char c = changes[i].second;

        int count = 0;
        for (int j = 0; j < final_name.length(); j++) {
            if (final_name[j] == c) {
                count++;
            }
            if (count == p) {
                final_name.erase(j, 1);
                break;
            }
        }
    }

    string result = "";
    for (int i = 0; i < k; i++) {
        result += final_name;
    }

    cout << result << endl;

    return 0;
}