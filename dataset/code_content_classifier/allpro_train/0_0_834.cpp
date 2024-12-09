#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k, m;
    cin >> n >> k >> m;

    vector<int> cities(n);
    for (int i = 0; i < n; i++) {
        cin >> cities[i];
    }

    long long totalParticipants = n * m;
    long long teamsFormed = 0;

    for (int city = 1; city <= 100000; city++) {
        vector<int> groupSizes;
        int groupSize = 0;

        for (int i = 0; i < n; i++) {
            if (cities[i] == city) {
                groupSize++;
            } else {
                if (groupSize >= k) {
                    groupSizes.push_back(groupSize);
                }
                groupSize = 0;
            }
        }

        if (groupSize >= k) {
            groupSizes.push_back(groupSize);
        }

        for (int size : groupSizes) {
            teamsFormed += size / k;
        }
    }

    cout << totalParticipants - teamsFormed * k << endl;

    return 0;
}