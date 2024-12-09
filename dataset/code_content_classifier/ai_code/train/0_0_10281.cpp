#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    int n, l, w_max;
    cin >> n >> l >> w_max;

    vector<pair<int, int>> clouds;
    for (int i = 0; i < n; i++) {
        int x_i, v_i;
        cin >> x_i >> v_i;
        clouds.push_back(make_pair(x_i, v_i));
    }

    sort(clouds.begin(), clouds.end());

    int count = 0;
    map<int, int> positive_clouds, negative_clouds;

    for (int i = 0; i < n; i++) {
        if (clouds[i].second == 1) {
            count += i - positive_clouds.size();
            positive_clouds[clouds[i].first] = 1;
        } else {
            count += negative_clouds.size();
            negative_clouds[clouds[i].first] = 1;
        }
    }

    cout << count << endl;

    return 0;
}