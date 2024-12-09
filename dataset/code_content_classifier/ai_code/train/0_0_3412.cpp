#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int calculateHammingDistance(string a, string b) {
    int distance = 0;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] != b[i]) {
            distance++;
        }
    }
    return distance;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> strings;
    for (int i = 0; i < m; i++) {
        int si, fi;
        cin >> si >> fi;
        strings.push_back(make_pair(si, fi));
    }

    int maxSum = 0;
    for (int i = 0; i < m; i++) {
        for (int j = i + 1; j < m; j++) {
            for (int k = j + 1; k < m; k++) {
                int sum = 2 * n - calculateHammingDistance(to_string(strings[i].first), to_string(strings[j].first))
                            - calculateHammingDistance(to_string(strings[j].first), to_string(strings[k].first))
                            - calculateHammingDistance(to_string(strings[k].first), to_string(strings[i].first));
                maxSum = max(maxSum, sum);
            }
        }
    }

    cout << maxSum << endl;

    return 0;
}