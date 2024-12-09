#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Spell {
    int a, b, c, d, index;
};

bool compareSpells(const Spell& s1, const Spell& s2) {
    return s1.c < s2.c;
}

int main() {
    int n;
    cin >> n;

    vector<Spell> spells(n);
    for (int i = 0; i < n; i++) {
        cin >> spells[i].a >> spells[i].b >> spells[i].c >> spells[i].d;
        spells[i].index = i + 1;
    }

    sort(spells.begin(), spells.end(), compareSpells);

    int x = 0, y = 0;
    vector<int> moves;
    for (int i = 0; i < n; i++) {
        if (spells[i].a <= x && spells[i].b <= y) {
            moves.push_back(spells[i].index);
            x = spells[i].c;
            y = spells[i].d;
        }
    }

    if (moves.empty() || spells[n - 1].c != x || spells[n - 1].d != y) {
        cout << -1 << endl;
    } else {
        cout << moves.size() << endl;
        for (int i = 0; i < moves.size(); i++) {
            cout << moves[i] << " ";
        }
        cout << endl;
    }

    return 0;
}