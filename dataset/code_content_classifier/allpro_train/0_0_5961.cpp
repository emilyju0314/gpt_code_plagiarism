#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <climits>

using namespace std;

struct Connection {
    string start_city;
    int departure_time;
    string arrival_city;
    int arrival_time;
    int price;
};

int convertTimeToInt(const string& time) {
    int hours = stoi(time.substr(0, 2));
    int minutes = stoi(time.substr(3, 2));
    return hours * 60 + minutes;
}

int main() {
    int n;
    while (true) {
        cin >> n;
        if (n == 0) break;

        unordered_map<string, vector<Connection>> connections;
        for (int i = 0; i < n; i++) {
            Connection conn;
            cin >> conn.start_city >> conn.departure_time >> conn.arrival_city >> conn.arrival_time >> conn.price;
            connections[conn.start_city].push_back(conn);
        }

        const int INF = INT_MAX;
        unordered_map<string, int> dp;
        dp["Hakodate"] = 0;
        priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> pq;
        pq.push({0, "Hakodate"});

        while (!pq.empty()) {
            int cost = pq.top().first;
            string city = pq.top().second;
            pq.pop();

            if (city == "Tokyo") {
                cout << dp["Tokyo"] << endl;
                break;
            }

            for (const Connection& conn : connections[city]) {
                if (dp.find(conn.arrival_city) == dp.end() || dp[conn.arrival_city] > cost + conn.price) {
                    int departure = convertTimeToInt(to_string(conn.arrival_time));
                    int arrival = convertTimeToInt(to_string(conn.departure_time));
                    int wait_time = 0;
                    if (departure >= arrival) {
                        wait_time = 1440 - departure + arrival;
                    } else {
                        wait_time = arrival - departure;
                    }

                    if (dp[city] + conn.price + wait_time < dp[conn.arrival_city]) {
                        dp[conn.arrival_city] = dp[city] + conn.price + wait_time;
                        pq.push({dp[conn.arrival_city], conn.arrival_city});
                    }
                }
            }
        }
    }

    return 0;
}