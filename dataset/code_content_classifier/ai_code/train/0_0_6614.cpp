#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    set<pair<int, int>> not_allowed;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        not_allowed.insert({a, b});
        not_allowed.insert({b, a});
    }

    int s = n*(n-1)/2 - m;
    cout << s << endl;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i != j && not_allowed.find({i, j}) == not_allowed.end()) {
                cout << i << " " << j << endl;
            }
        }
    }

    return 0;
}