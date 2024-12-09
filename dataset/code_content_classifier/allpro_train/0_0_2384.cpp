#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    int n, M, T;
    cin >> n >> M >> T;

    vector<pair<int, string>> requests;
    map<string, int> user_ids;

    for (int i = 0; i < n; i++) {
        string timestamp;
        cin >> timestamp;
        requests.push_back({i, timestamp});
    }

    int R = 0;
    int max_users = 0;
    vector<int> online_users;
    int last_timestamp = -1;

    for (int i = 0; i < n; i++) {
        string timestamp = requests[i].second;
        int secs = stoi(timestamp.substr(0, 2)) * 3600 + stoi(timestamp.substr(3, 2)) * 60 + stoi(timestamp.substr(6, 2));

        while (!online_users.empty() && online_users.front() + T <= secs) {
            online_users.erase(online_users.begin());
        }

        if (online_users.size() < M) {
            R++;
            online_users.push_back(secs);
        }

        if (online_users.size() == M) {
            max_users = max(max_users, R);
        }

        if (max_users == M) {
            last_timestamp = i;
            break;
        }

        user_ids[timestamp] = R;
    }

    if (max_users < M) {
        cout << "No solution" << endl;
    } else {
        cout << R << endl;
        for (int i = 0; i <= last_timestamp; i++) {
            cout << user_ids[requests[i].second] << endl;
        }
    }

    return 0;
}