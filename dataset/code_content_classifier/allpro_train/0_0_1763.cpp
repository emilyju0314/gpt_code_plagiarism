#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<set<int>> languages(n);

    for (int i = 0; i < n; i++) {
        int ki;
        cin >> ki;
        for (int j = 0; j < ki; j++) {
            int aij;
            cin >> aij;
            languages[i].insert(aij);
        }
    }

    set<int> unique_languages;

    for (int i = 0; i < n; i++) {
        for (int language : languages[i]) {
            unique_languages.insert(language);
        }
    }

    int min_cost = 0;

    for (int i = 0; i < n; i++) {
        int cost = m - languages[i].size();
        min_cost = max(min_cost, cost);
    }

    cout << min_cost << endl;

    return 0;
}