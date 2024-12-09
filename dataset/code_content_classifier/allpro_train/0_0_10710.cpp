#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    int n;
    cin >> n;

    string pullover, t_shirt;
    cin >> pullover >> t_shirt;

    map<char, char> spells;

    for (int i = 0; i < n; i++) {
        if (pullover[i] != t_shirt[i]) {
            if (spells.find(pullover[i]) != spells.end()) {
                if (spells[pullover[i]] != t_shirt[i]) {
                    cout << "No solution exists";
                    return 0;
                }
            } else {
                spells[pullover[i]] = t_shirt[i];
            }
        }
    }

    cout << spells.size() << endl;
    for (auto s : spells) {
        cout << s.first << " " << s.second << endl;
    }

    return 0;
}