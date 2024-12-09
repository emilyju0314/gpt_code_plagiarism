#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b) {
    return a.first > b.first;
}

int main() {
    int n;
    cin >> n;

    vector<pair<int, pair<int, int>>> people;
    vector<int> result(n);

    for (int i = 0; i < n; i++) {
        int a, c;
        cin >> a >> c;
        people.push_back(make_pair(a, make_pair(c, i)));
    }

    sort(people.begin(), people.end(), compare);

    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = i+1; j < n; j++) {
            if (count == people[i].second.first) {
                break;
            }
            if (people[j].first > people[i].first) {
                count++;
                swap(people[i], people[j]);
            }
        }
        result[people[i].second.second] = i+1;
    }

    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }

    return 0;
}