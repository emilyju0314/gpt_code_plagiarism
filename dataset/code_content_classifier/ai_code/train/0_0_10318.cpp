#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    vector<pair<int, int>> lights(n);
    for (int i = 0; i < n; i++) {
        cin >> lights[i].first >> lights[i].second;
    }

    int max_lights_on = 0;
    for (int t = 1; t <= 5; t++) {
        int count_lights_on = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                if ((t - lights[i].second) % lights[i].first == 0) {
                    if ((t - lights[i].second) / lights[i].first % 2 == 0) {
                        count_lights_on++;
                    }
                }
            }
        }
        max_lights_on = max(max_lights_on, count_lights_on);
    }

    cout << max_lights_on << endl;

    return 0;
}