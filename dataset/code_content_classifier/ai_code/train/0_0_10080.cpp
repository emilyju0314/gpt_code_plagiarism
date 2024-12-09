#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Card {
    string position;
    int strength;
};

int main() {
    int n, m;
    cin >> n >> m;

    vector<Card> jiro_cards(n);
    for (int i = 0; i < n; i++) {
        cin >> jiro_cards[i].position >> jiro_cards[i].strength;
    }

    vector<int> ciel_cards(m);
    for (int i = 0; i < m; i++) {
        cin >> ciel_cards[i];
    }

    sort(jiro_cards.begin(), jiro_cards.end(), [](const Card &a, const Card &b) {
        return a.strength < b.strength;
    });

    sort(ciel_cards.begin(), ciel_cards.end(), greater<int>());

    int damage = 0;
    for (int i = 0; i < m; i++) {
        int max_dmg = 0;
        int max_j = -1;

        for (int j = 0; j < n; j++) {
            if(jiro_cards[j].position == "ATK" && ciel_cards[i] >= jiro_cards[j].strength) {
                if(ciel_cards[i] - jiro_cards[j].strength > max_dmg) {
                    max_dmg = ciel_cards[i] - jiro_cards[j].strength;
                    max_j = j;
                }
            } else if (jiro_cards[j].position == "DEF" && ciel_cards[i] > jiro_cards[j].strength) {
                if(ciel_cards[i] > max_dmg) {
                    max_dmg = ciel_cards[i];
                    max_j = j;
                }
            }
        }

        if(max_j != -1) {
            damage += max_dmg;
            jiro_cards.erase(jiro_cards.begin() + max_j);
        }
    }

    cout << damage << endl;

    return 0;
}