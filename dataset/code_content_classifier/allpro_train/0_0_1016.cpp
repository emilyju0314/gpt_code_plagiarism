#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> firstSet(n);
    vector<pair<int, int>> secondSet(m);

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        firstSet[i] = make_pair(a, b);
    }

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        secondSet[i] = make_pair(a, b);
    }

    int sharedNumber = -1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (firstSet[i].first == secondSet[j].first || firstSet[i].first == secondSet[j].second) {
                if (sharedNumber == -1) {
                    sharedNumber = firstSet[i].first;
                } else if (sharedNumber != firstSet[i].first) {
                    cout << -1 << endl;
                    return 0;
                }
            }
            if (firstSet[i].second == secondSet[j].first || firstSet[i].second == secondSet[j].second) {
                if (sharedNumber == -1) {
                    sharedNumber = firstSet[i].second;
                } else if (sharedNumber != firstSet[i].second) {
                    cout << -1 << endl;
                    return 0;
                }
            }
        }
    }

    cout << sharedNumber << endl;

    return 0;
}