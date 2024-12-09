#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    unordered_set<int> possible_x_values;
    for (int i = 0; i < n; i++) {
        unordered_set<int> new_possible_x_values;
        for (int x : possible_x_values) {
            new_possible_x_values.insert(x ^ a[i]);
        }
        new_possible_x_values.insert(a[i]);
        possible_x_values.insert(new_possible_x_values.begin(), new_possible_x_values.end());
    }

    cout << possible_x_values.size() << endl;
    for (int x : possible_x_values) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}