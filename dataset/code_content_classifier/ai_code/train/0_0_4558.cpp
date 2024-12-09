#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Enemy {
    int max_health;
    int current_health;
    int regen_rate;
    vector<pair<int, int>> health_updates; // pair of (time, updated_health)
};

int main() {
    int n, m;
    cin >> n >> m;

    int ability_damage, initial_bounty, bounty_increase;
    cin >> ability_damage >> initial_bounty >> bounty_increase;

    vector<Enemy> enemies(n);
    for (int i = 0; i < n; i++) {
        cin >> enemies[i].max_health >> enemies[i].current_health >> enemies[i].regen_rate;
    }

    for (int i = 0; i < m; i++) {
        int time, enemy_idx, updated_health;
        cin >> time >> enemy_idx >> updated_health;
        enemies[enemy_idx - 1].health_updates.push_back({time, updated_health});
    }

    long long max_bounty = -1;
    for (int t = 0; ; t++) {
        long long total_bounty = 0;
        bool infinite_bounty = false;
        for (int i = 0; i < n; i++) {
            Enemy& enemy = enemies[i];
            int current_health = enemy.current_health;
            int max_updated_health = enemy.max_health;

            for (const auto& update : enemy.health_updates) {
                if (update.first <= t) {
                    max_updated_health = max(max_updated_health, update.second);
                }
            }

            current_health = min(max_updated_health, current_health + ((t - 1) * enemy.regen_rate));
            if (current_health <= ability_damage) {
                infinite_bounty = true;
                break;
            }

            total_bounty += initial_bounty + bounty_increase * t;
        }

        if (infinite_bounty) {
            cout << -1 << endl;
            break;
        } else {
            max_bounty = max(max_bounty, total_bounty);
        }

        if (t >= 1000000) {
            cout << max_bounty << endl;
            break;
        }
    }

    return 0;
}