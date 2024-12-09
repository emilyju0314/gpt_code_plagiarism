#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    map<int, int> pirates;

    for(int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        pirates[a] = b;
    }

    map<int, int> adj_pirates;
    for(auto it = pirates.begin(); it != pirates.end(); it++) {
        adj_pirates[it->first] = it->second;
    }

    if(adj_pirates.size() == 1) {
        cout << -1 << endl;
        return 0;
    }

    map<int, int> actual_pirates = pirates;

    int gcd = 0;
    for(auto it = adj_pirates.begin(); it != adj_pirates.end(); it++) {
        gcd = __gcd(gcd, it->second);
    }

    while(actual_pirates.size() > 1) {
        map<int, int> new_pirates;

        for(auto it = actual_pirates.begin(); it != actual_pirates.end(); it++) {
            if(it->second >= 2) {
                int next_pos = it->first + 1;
                if(next_pos > n) next_pos = 1;

                adj_pirates[next_pos] += 1;
                it->second -= 1;

                if(it->second == 1) {
                    new_pirates[it->first] = it->second;
                }
            }
        }

        for(auto it = adj_pirates.begin(); it != adj_pirates.end(); it++) {
            adj_pirates[it->first] = it->second;
        }

        for(auto it = actual_pirates.begin(); it != actual_pirates.end(); it++) {
            if(it->second > 1) {
                new_pirates[it->first] = it->second;
            }
        }

        actual_pirates = new_pirates;

        if(__gcd(gcd, 2) == 1) {
            cout << 1 << endl;
            return 0;
        }
    }

    cout << -1 << endl;

    return 0;
}