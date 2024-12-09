#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<string, int>> jiroCards;
    for (int i = 0; i < n; i++) {
        string position;
        int strength;
        cin >> position >> strength;
        jiroCards.push_back(make_pair(position, strength));
    }

    vector<int> cielCards;
    for (int i = 0; i < m; i++) {
        int strength;
        cin >> strength;
        cielCards.push_back(strength);
    }

    int totalDamage = 0;
    for (int i = 0; i < m; i++) {
        bool found = false;
        for (int j = 0; j < n; j++) {
            if (jiroCards[j].first == "DEF" && cielCards[i] > jiroCards[j].second) {
                totalDamage += cielCards[i];
                found = true;
                break;
            } else if (jiroCards[j].first == "ATK" && cielCards[i] >= jiroCards[j].second) {
                totalDamage += cielCards[i] - jiroCards[j].second;
                found = true;
                break;
            }
        }
        if (!found) {
            totalDamage += cielCards[i];
        }
    }

    cout << totalDamage << endl;

    return 0;
}