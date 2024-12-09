#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<pair<int, int>> friends;
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        friends.push_back(make_pair(a, b));
    }

    sort(friends.begin(), friends.end());

    int max_friends = 0;
    int curr_friends = 0;

    for (int i = 0; i < N; i++) {
        if (friends[i].second < curr_friends) {
            continue;
        } else {
            max_friends = max(max_friends, friends[i].second);
            curr_friends = max_friends;
        }
    }

    cout << max_friends << endl;

    return 0;
}