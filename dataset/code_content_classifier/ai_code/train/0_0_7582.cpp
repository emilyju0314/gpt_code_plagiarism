#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> computers(n);
    vector<int> sockets(m);
    
    for(int i = 0; i < n; i++) {
        cin >> computers[i];
    }

    for(int i = 0; i < m; i++) {
        cin >> sockets[i];
    }

    sort(computers.begin(), computers.end());
    sort(sockets.begin(), sockets.end());

    int c = 0, u = 0;

    for(int i = 0, j = 0; i < n && j < m; ) {
        if (computers[i] == sockets[j]) {
            c++;
            i++;
            j++;
        } else if (computers[i] < sockets[j]) {
            i++;
        } else {
            j++;
        }
    }

    u = c;

    cout << c << " " << u << endl;

    for(int i = 0; i < m; i++) {
        if (i < u) {
            cout << 1 << " ";
        } else {
            cout << 0 << " ";
        }
    }
    cout << endl;

    for(int i = 0, j = 0; i < n && j < m; ) {
        if (computers[i] == sockets[j]) {
            cout << j+1 << " ";
            i++;
            j++;
        } else if (computers[i] < sockets[j]) {
            i++;
        } else {
            j++;
        }
    }
    cout << endl;

    return 0;
}