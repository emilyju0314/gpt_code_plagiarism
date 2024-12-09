#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    set<int> x_values;
    x_values.insert(0); // It is always possible to choose an empty subsequence

    set<int> current_x_values;
    current_x_values.insert(0);

    for (int i = 0; i < n; i++) {
        set<int> new_x_values;

        for (int x : current_x_values) {
            new_x_values.insert(x ^ a[i]);
        }

        for (int x : new_x_values) {
            x_values.insert(x);
        }

        for (int x : new_x_values) {
            current_x_values.insert(x);
        }
    }

    cout << x_values.size() << "\n";
    for (int x : x_values) {
        cout << x << " ";
    }

    return 0;
}