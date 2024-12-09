#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n, b;
    cin >> n >> b;

    vector<pair<int, int>> queries(n);
    for (int i = 0; i < n; i++) {
        cin >> queries[i].first >> queries[i].second;
    }

    long long currentTime = 0;
    queue<pair<int, int>> queryQueue;
    vector<int> finishTimes(n, 0);

    for (int i = 0; i < n; i++) {
        if (currentTime < queries[i].first) {
            currentTime = queries[i].first;
        }

        while (!queryQueue.empty() && currentTime >= queryQueue.front().first) {
            currentTime += queryQueue.front().second;
            finishTimes[queryQueue.front().second] = currentTime;
            queryQueue.pop();
        }

        if(queryQueue.size() < b) {
            queryQueue.push(make_pair(currentTime, queries[i].second));
            currentTime += queries[i].second;
            finishTimes[i] = currentTime;
        } else {
            finishTimes[i] = -1;
        }
    }

    for(int i = 0; i < n; i++) {
        cout << finishTimes[i] << " ";
    }

    return 0;
}