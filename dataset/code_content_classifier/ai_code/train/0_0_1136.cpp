#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<string, string>> blacklist;
    vector<pair<string, string>> whitelist;
    set<string> matched;

    for (int i = 0; i < n; i++) {
        char type;
        string ip;
        cin >> type >> ip;

        if (type == '-') {
            blacklist.push_back({type, ip});
        } else {
            whitelist.push_back({type, ip});
        }
    }

    map<string, int> blocked;
    map<string, int> allowed;

    for (auto [_, subnet] : blacklist) {
        int pos = subnet.find('/');
        if (pos != string::npos) {
            string ip = subnet.substr(0, pos);
            int len = atoi(subnet.substr(pos + 1).c_str());

            blocked[ip] = max(blocked[ip], len);
        } else {
            blocked[subnet] = 32;
        }
    }

    for (auto [_, subnet] : whitelist) {
        int pos = subnet.find('/');
        if (pos != string::npos) {
            string ip = subnet.substr(0, pos);
            int len = atoi(subnet.substr(pos + 1).c_str());

            allowed[ip] = max(allowed[ip], len);
        } else {
            allowed[subnet] = 32;
        }
    }

    for (auto [ip, len] : allowed) {
        if (blocked.count(ip)) {
            matched.insert(ip);
        }
    }

    if (!matched.empty()) {
        cout << -1 << endl;
    } else {
        vector<pair<string, int>> optimized_blacklist;

        for (auto [ip, len] : blocked) {
            if (allowed.find(ip) != allowed.end() && blocked[ip] <= allowed[ip]) {
                continue;
            }

            string subnet = ip;
            if (len < 32) {
                subnet += "/" + to_string(len);
            }

            optimized_blacklist.push_back({subnet, len});
        }

        cout << optimized_blacklist.size() << endl;
        for (auto [subnet, len] : optimized_blacklist) {
            cout << subnet << endl;
        }
    }

    return 0;
}