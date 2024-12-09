#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> unread(n, 0);
    int unreadCount = 0;
    int t = 0;

    for (int i = 0; i < q; i++) {
        int type;
        cin >> type;

        if (type == 1) {
            int x;
            cin >> x;
            unread[x-1]++;
            unreadCount++;
        } else if (type == 2) {
            int x;
            cin >> x;
            unreadCount -= unread[x-1];
            unread[x-1] = 0;
        } else {
            int tt;
            cin >> tt;
            while (t < tt) {
                unreadCount -= unread[t];
                unread[t] = 0;
                t++;
            }
        }

        cout << unreadCount << endl;
    }

    return 0;
}