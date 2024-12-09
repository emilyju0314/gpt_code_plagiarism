#include <iostream>
#include <queue>
#include <vector>
#include <utility>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    priority_queue<long long, vector<long long>, greater<long long>> available_servers;
    vector<pair<long long, long long>> videos(n);
    
    for(int i = 0; i < n; i++) {
        cin >> videos[i].first >> videos[i].second;
    }

    for(int i = 0; i < k; i++) {
        available_servers.push(0);
    }

    for(int i = 0; i < n; i++) {
        long long start_time = max(videos[i].first, available_servers.top());
        long long end_time = start_time + videos[i].second * 60;

        cout << end_time << endl;

        available_servers.pop();
        available_servers.push(end_time);
    }

    return 0;
}