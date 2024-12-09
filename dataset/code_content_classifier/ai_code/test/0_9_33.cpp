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

    set<int> possible_values;
    possible_values.insert(0);

    for (int i = 0; i < n; i++) {
        set<int> new_values;
        for (int val : possible_values) {
            new_values.insert(val ^ a[i]);
        }
        possible_values.insert(new_values.begin(), new_values.end());
    }

    cout << possible_values.size() << endl;
    for (int val : possible_values) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}