#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
    int m;
    cin >> m;

    unordered_map<string, int> occurrences;
    string s;

    while (m--) {
        int t;
        cin >> t >> s;

        if (t == 1) {
            occurrences[s]++;
        } else if (t == 2) {
            occurrences[s]--;
        } else {
            int count = 0;
            for (int i = 0; i <= s.length(); i++) {
                for (int j = i + 1; j <= s.length(); j++) {
                    string sub = s.substr(i, j - i);

                    count += occurrences[sub];
                }
            }
            cout << count << endl;
            fflush(stdout);
        }
    }

    return 0;
}