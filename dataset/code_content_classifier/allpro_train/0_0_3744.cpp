#include <iostream>
#include <map>

using namespace std;

int main() {
    int n;
    cin >> n;

    map<int, int> fire_spells, lightning_spells;
    int lightning_multiplier = 0;
    int current_damage = 0;

    for (int i = 0; i < n; i++) {
        int tp, d;
        cin >> tp >> d;

        if (tp == 0) { // Fire spell
            if (fire_spells.find(d) != fire_spells.end()) {
                // Forget the fire spell
                current_damage -= d;
                fire_spells.erase(d);
            } else {
                // Learn the fire spell
                current_damage += d;
                fire_spells[d] = d;
            }
        } else { // Lightning spell
            if (lightning_spells.find(d) != lightning_spells.end()) {
                // Forget the lightning spell
                current_damage -= d;
                if (lightning_multiplier > 0) {
                    current_damage -= d * lightning_multiplier;
                    lightning_multiplier = 0;
                }
                lightning_spells.erase(d);
            } else {
                // Learn the lightning spell
                current_damage += d;
                lightning_spells[d] = d;
            }
        }

        cout << current_damage + (lightning_multiplier * lightning_spells.begin()->first) << endl;
    }

    return 0;
}