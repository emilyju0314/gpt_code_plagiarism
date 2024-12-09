#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> p(n), q(n);
    for(int i = 0; i < n; i++) {
        cin >> p[i];
    }

    for(int i = 0; i < n; i++) {
        cin >> q[i];
    }

    vector<int> max_values(n+1);
    vector<bool> bombs(n+1);

    int max_val = 0;

    for(int i = 0; i < n; i++) {
        max_values[p[i]] = max(max_values[p[i]], p[i]);
        bombs[q[i]] = true;

        while(max_values[max_val] != 0 || bombs[max_val]) {
            max_val++;
        }

        cout << max_val << " ";
    }

    return 0;
}