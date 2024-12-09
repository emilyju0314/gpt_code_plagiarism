#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> friends;
    vector<long long> sizes;

    long long total_width = 0;
    int max_height = 0;

    for(int i = 0; i < n; i++) {
        int w, h;
        cin >> w >> h;
        friends.push_back(make_pair(w, h));
        total_width += w;
        max_height = max(max_height, h);
    }

    for(int i = 0; i < n; i++) {
        long long width_without_friend = total_width - friends[i].first;
        long long height = (max_height > friends[i].second) ? max_height : friends[i].second;
        sizes.push_back(width_without_friend * height);
    }

    for(int i = 0; i < n; i++) {
        cout << sizes[i] << " ";
    }

    return 0;
}