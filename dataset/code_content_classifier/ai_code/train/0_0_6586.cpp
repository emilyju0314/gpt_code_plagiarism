#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isValidArrangement(vector<int> arrangement, vector<pair<int, int>> restrictions) {
    for (auto restriction : restrictions) {
        int seniorPos = find(arrangement.begin(), arrangement.end(), restriction.first) - arrangement.begin();
        int juniorPos = find(arrangement.begin(), arrangement.end(), restriction.second) - arrangement.begin();
        if (seniorPos >= juniorPos) {
            return false;
        }
    }
    return true;
}

int main() {
    int n, m;
    long long y;
    cin >> n >> y >> m;

    vector<pair<int, int>> restrictions;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        restrictions.push_back(make_pair(a, b));
    }

    vector<int> professors(n);
    for (int i = 0; i < n; i++) {
        professors[i] = i + 1;
    }

    int count = 0;
    vector<int> arrangement;
    do {
        if (isValidArrangement(professors, restrictions)) {
            count++;
            if (count == y - 2000) {
                arrangement = professors;
                break;
            }
        }
    } while (next_permutation(professors.begin(), professors.end()));

    if (arrangement.empty()) {
        cout << "The times have changed" << endl;
    } else {
        for (int i = 0; i < n; i++) {
            cout << arrangement[i] << " ";
        }
        cout << endl;
    }

    return 0;
}