#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Friend {
    int height;
    int width;
    int index;
};

bool comparator(Friend a, Friend b) {
    if(a.height == b.height) {
        return a.width < b.width;
    }
    return a.height < b.height;
}

int main() {
    int t;
    cin >> t;

    for(int i = 0; i < t; i++) {
        int n;
        cin >> n;

        vector<Friend> friends(n);

        for(int j = 0; j < n; j++) {
            cin >> friends[j].height >> friends[j].width;
            friends[j].index = j + 1;
        }

        sort(friends.begin(), friends.end(), comparator);

        vector<int> result(n, -1);
        
        for(int j = 0; j < n; j++) {
            int current_h = friends[j].height;
            int current_w = friends[j].width;
            int candidate = -1;
            for(int k = 0; k < n; k++) {
                if(friends[k].width < current_w && friends[k].height < current_h) {
                    candidate = friends[k].index;
                    break;
                }
            }
            result[j] = candidate;
        }

        for(int j = 0; j < n; j++) {
            cout << result[j] << " ";
        }
        cout << endl;
    }

    return 0;
}