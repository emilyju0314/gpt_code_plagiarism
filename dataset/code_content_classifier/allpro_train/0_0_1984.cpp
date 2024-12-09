#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<int> q(m), k(m);
    for (int i = 0; i < m; i++) {
        cin >> q[i] >> k[i];
    }
    
    int total_rooms = 0;
    for (int i = 1; i <= n; i++) {
        total_rooms += i * i;
    }
    
    int lit_rooms = total_rooms;
    
    for (int i = 0; i < m; i++) {
        if (q[i] == 0) {
            lit_rooms -= k[i] * (n - k[i] + 1);
        } else if (q[i] == 1) {
            lit_rooms -= k[i] * (n - k[i] + 1);
        } else {
            lit_rooms -= k[i];
        }
    }
    
    cout << lit_rooms << endl;
    
    return 0;
}