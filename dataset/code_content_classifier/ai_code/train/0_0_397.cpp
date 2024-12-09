#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> direct_managers(n+1);
    for (int i = 2; i <= n; i++) {
        cin >> direct_managers[i];
    }

    vector<int> bearing_limits(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> bearing_limits[i];
    }

    vector<int> events(m);
    for (int i = 0; i < m; i++) {
        cin >> events[i];
    }

    set<int> on_vacation;
    set<int> displeased_employees;

    for (int i = 0; i < m; i++) {
        if (events[i] > 0) {
            on_vacation.insert(events[i]);
        } else {
            on_vacation.erase(-events[i]);
        }

        displeased_employees.clear();
        for (int j = 1; j <= n; j++) {
            if (on_vacation.count(j) == 0 && on_vacation.count(direct_managers[j]) > bearing_limits[j]) {
                displeased_employees.insert(direct_managers[j]);
            }
        }

        cout << displeased_employees.size() << " ";
    }

    cout << endl;

    return 0;
}