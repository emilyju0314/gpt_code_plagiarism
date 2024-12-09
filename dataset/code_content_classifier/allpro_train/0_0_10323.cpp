#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        map<int, int> skills;
        for (int i = 0; i < n; i++) {
            int skill;
            cin >> skill;
            skills[skill]++;
        }

        int max_size = 0;
        for (auto it = skills.begin(); it != skills.end(); it++) {
            max_size = max(max_size, min(it->second, it->first - 1));
        }

        cout << max_size << endl;
    }

    return 0;
}