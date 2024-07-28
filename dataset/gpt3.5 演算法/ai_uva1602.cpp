#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
    if(a.second == b.second) {
        return a.first < b.first;
    }
    return a.second > b.second;
}

int main() {
    int n, m;
    while (cin >> n >> m) {
        if (n == 0 && m == 0) {
            break;
        }

        vector<pair<int, int>> tasks;
        for (int i = 0; i < n; i++) {
            int s, d;
            cin >> s >> d;
            tasks.push_back(make_pair(s, s + d));
        }

        sort(tasks.begin(), tasks.end(), cmp);

        int count = 1;
        int last_end = tasks[0].second;
        for (int i = 1; i < n; i++) {
            if (tasks[i].first >= last_end) {
                count++;
                last_end = tasks[i].second;
            }
        }

        cout << count << endl;
    }

    return 0;
}
