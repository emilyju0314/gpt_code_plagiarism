#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> unread(n+1, 0);

    int lastReadIndex = 0;
    int unreadCount = 0;

    for(int i = 0; i < q; i++) {
        int type, x;
        cin >> type >> x;

        if(type == 1) {
            unread[x]++;
            unreadCount++;
        } else if(type == 2) {
            unreadCount -= unread[x];
            unread[x] = 0;
        } else if(type == 3) {
            for(int j = lastReadIndex+1; j <= x; j++) {
                unreadCount -= unread[j];
                unread[j] = 0;
            }
            lastReadIndex = max(lastReadIndex, x);
        }

        cout << unreadCount << endl;
    }

    return 0;
}