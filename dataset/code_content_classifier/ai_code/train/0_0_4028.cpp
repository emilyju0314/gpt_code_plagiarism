#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, A, cf, cm;
    long long m;
    cin >> n >> A >> cf >> cm >> m;

    vector<int> skills(n);
    for (int i = 0; i < n; i++) {
        cin >> skills[i];
    }

    sort(skills.begin(), skills.end());

    long long force = 0;
    int min_level = skills[0];
    int perfect_skills = 0;

    for (int i = 0; i < n; i++) {
        int extra_cost = max(0, A - skills[i]);
        long long total_cost = extra_cost * cf;

        if ((m - total_cost) < 0) {
            break;
        }

        m -= total_cost;
        if (skills[i] == A) {
            perfect_skills++;
        } else {
            int diff = min(A, skills[i] + m) - skills[i];
            skills[i] += diff;
            m -= diff;
        }

        min_level = min(min_level, skills[i]);
        force = max(force, (long long)perfect_skills * cf + (long long)min_level * cm);
    }

    cout << force << endl;
    for (int i = 0; i < n; i++) {
        cout << skills[i] << " ";
    }

    return 0;
}