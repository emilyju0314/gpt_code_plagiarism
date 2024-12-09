#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Spell {
    int type; // 0 for vertical, 1 for horizontal
    int x, x1, x2, y;
};

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<Spell> spells;
    
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        spells.push_back({0, x, 0, 0, 0});
    }

    for (int i = 0; i < m; i++) {
        int x1, x2, y;
        cin >> x1 >> x2 >> y;
        spells.push_back({1, 0, x1, x2, y});
    }

    sort(spells.begin(), spells.end(), [](const Spell& a, const Spell& b) {
        if (a.type != b.type) {
            return a.type < b.type;
        } else if (a.type == 0) {
            return a.x < b.x;
        } else {
            return a.y > b.y;
        }
    });

    int vertical_removed = 0, horizontal_removed = 0;
    
    for (const Spell& spell : spells) {
        if (spell.type == 0) {
            vertical_removed++;
        } else {
            if (spell.x1 <= 1 && spell.x2 >= 1) {
                horizontal_removed++;
            } else {
                break;
            }
        }
    }

    cout << min(vertical_removed + horizontal_removed, 1);

    return 0;
}