#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> roads(n - 1); // pair of city and days
    vector<long long> beautifulTrees(n - 1, 0);

    for (int i = 0; i < n - 1; i++) {
        int a, b, d;
        cin >> a >> b >> d;
        roads[i] = make_pair(d, i + 1); // days and road number
    }

    sort(roads.begin(), roads.end()); // sort by days

    for (int i = 1; i < n; i++) {
        beautifulTrees[i - 1] = 1LL * i * (n - i) * roads[n - i - 1].first;
    }

    long long maxBeautifulTrees = *max_element(beautifulTrees.begin(), beautifulTrees.end());

    cout << maxBeautifulTrees << " ";

    int numMaxBeautifulRoads = 0;
    for (int i = 0; i < n - 1; i++) {
        if (beautifulTrees[i] == maxBeautifulTrees) {
            numMaxBeautifulRoads++;
        }
    }

    cout << numMaxBeautifulRoads << endl;

    for (int i = 0; i < n - 1; i++) {
        if (beautifulTrees[i] == maxBeautifulTrees) {
            cout << roads[i].second << " ";
        }
    }

    return 0;
}