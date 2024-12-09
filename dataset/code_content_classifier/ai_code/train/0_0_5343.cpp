#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    unordered_map<int, int> firstParticipantPairs;
    unordered_map<int, int> secondParticipantPairs;

    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        firstParticipantPairs[a]++;
        firstParticipantPairs[b]++;
    }

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        secondParticipantPairs[a]++;
        secondParticipantPairs[b]++;
    }

    int commonNumber = -1;

    for (auto it : firstParticipantPairs) {
        if (secondParticipantPairs.count(it.first) > 0) {
            if (commonNumber == -1) {
                commonNumber = it.first;
            } else {
                cout << "0" << endl;
                return 0;
            }
        }
    }

    if (commonNumber != -1) {
        cout << commonNumber << endl;
    } else {
        cout << "-1" << endl;
    }

    return 0;
}