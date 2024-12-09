#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, c;
    cin >> n >> c;

    vector<pair<int, int>> planets;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        planets.push_back({a, b});
    }

    long long ans = 0;
    for (int x = 1; x <= 100; x++) {
        bool valid = true;
        long long days = 0;
        for (int i = 0; i < n; i++) {
            int a = planets[i].first;
            int b = planets[i].second;
            long long presents = a * x;
            days += b;
            if (presents < days) {
                valid = false;
                break;
            }
        }
        if (valid && days <= c) {
            if (days == c) ans++;
            else if ((c - days) % n == 0) ans++;
        }
    }

    if (ans == 0) cout << "-1" << endl;
    else cout << ans << endl;

    return 0;
}