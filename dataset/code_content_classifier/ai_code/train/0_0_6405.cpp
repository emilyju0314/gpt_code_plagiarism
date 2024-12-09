#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<string> strings(N);
    unordered_set<char> candidates;

    for (int i = 0; i < N; i++) {
        cin >> strings[i];
        candidates.insert(strings[i][0]);
    }

    char last_char = strings[0].back();
    bool found = true;
    while (found) {
        found = false;
        for (int i = 0; i < strings.size(); i++) {
            if (strings[i][0] == last_char) {
                candidates.insert(strings[i].back());
                last_char = strings[i].back();
                strings.erase(strings.begin() + i);
                found = true;
                break;
            }
        }
    }

    vector<char> result(candidates.begin(), candidates.end());
    sort(result.begin(), result.end());

    for (char c : result) {
        cout << c << endl;
    }

    return 0;
}