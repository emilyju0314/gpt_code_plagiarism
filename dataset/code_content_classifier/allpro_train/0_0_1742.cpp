#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct SpaceShip {
    int attackPower;
    int maxGold;

    SpaceShip(int power) : attackPower(power), maxGold(0) {}
};

struct EmpireBase {
    int defensePower;
    int gold;

    EmpireBase(int defense, int g) : defensePower(defense), gold(g) {}
};

int main() {
    int s, b;
    cin >> s >> b;

    vector<SpaceShip> spaceships;
    for (int i = 0; i < s; i++) {
        int power;
        cin >> power;
        spaceships.push_back(SpaceShip(power));
    }

    vector<EmpireBase> bases;
    for (int i = 0; i < b; i++) {
        int defense, gold;
        cin >> defense >> gold;
        bases.push_back(EmpireBase(defense, gold));
    }

    sort(spaceships.begin(), spaceships.end(), [](SpaceShip& a, SpaceShip& b) {
        return a.attackPower < b.attackPower;
    });

    sort(bases.begin(), bases.end(), [](EmpireBase& a, EmpireBase& b) {
        return a.defensePower < b.defensePower;
    });

    int baseCount = 0;
    for (int i = 0; i < s; i++) {
        while (baseCount < b && bases[baseCount].defensePower <= spaceships[i].attackPower) {
            spaceships[i].maxGold += bases[baseCount].gold;
            baseCount++;
        }
    }

    for (int i = 0; i < s; i++) {
        cout << spaceships[i].maxGold << " ";
    }

    cout << endl;

    return 0;
}