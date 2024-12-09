#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Weapon {
    int type;
    vector<int> targets;
};

int main() {
    int N, M;
    cin >> N >> M;

    vector<Weapon> weapons(N);
    for (int i = 0; i < N; i++) {
        cin >> weapons[i].type;
        if (weapons[i].type == 0) {
            int K;
            cin >> K;
            weapons[i].targets.resize(K);
            for (int j = 0; j < K; j++) {
                cin >> weapons[i].targets[j];
            }
        } else if (weapons[i].type == 1) {
            int l, r;
            cin >> l >> r;
            weapons[i].targets.push_back(l);
            weapons[i].targets.push_back(r);
        } else {
            int a, b, c;
            cin >> a >> b >> c;
            weapons[i].targets.push_back(a);
            weapons[i].targets.push_back(b);
            weapons[i].targets.push_back(c);
        }
    }

    int destroyed = 0;
    vector<pair<int, int>> destructionPlan;

    // Sorting the weapons based on number of targets
    sort(weapons.begin(), weapons.end(), [](const Weapon& w1, const Weapon& w2) {
        return w1.targets.size() > w2.targets.size();
    });

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < weapons[i].targets.size(); j++) {
            if (destroyed == M) break;
            destructionPlan.push_back({i + 1, weapons[i].targets[j]});
            destroyed++;
        }
    }

    cout << destroyed << endl;
    for (const auto& plan : destructionPlan) {
        cout << plan.first << " " << plan.second << endl;
    }

    return 0;
}