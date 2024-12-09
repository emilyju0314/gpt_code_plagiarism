#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> hp(m);
    int total_hp = 0;
    for (int i = 0; i < m; i++) {
        cin >> hp[i];
        total_hp += hp[i];
    }

    int num_steps = 0;
    int soldiers_per_group = n / m;
    cout << total_hp / soldiers_per_group + (total_hp % soldiers_per_group != 0) << endl;

    vector<int> soldiers(m);
    for (int i = 0; i < m; i++) {
        soldiers[i] = soldiers_per_group;
        if (i < total_hp % m) soldiers[i]++;
        cout << soldiers[i] << " ";
    }
    cout << endl;

    vector<vector<int>> attacks;
    while (total_hp > 0) {
        vector<int> a(m, 1);
        for (int i = 0; i < m; i++) {
            if (hp[i] > 0) {
                hp[i] -= soldiers[i];
                a[i] = (hp[i] > 0) ? i + 1 : 0;
                total_hp -= min(hp[i], soldiers[i]);
            }
        }
        attacks.push_back(a);
    }

    for (auto a : attacks) {
        for (int i = 0; i < m; i++) {
            cout << a[i] << " ";
        }
        cout << endl;
    }

    return 0;
}