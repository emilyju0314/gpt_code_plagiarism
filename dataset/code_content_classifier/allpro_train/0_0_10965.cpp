#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<pair<int, int>> lr(n+1);
    for (int i = 1; i <= n; i++) {
        int l, r;
        cin >> l >> r;
        lr[i] = make_pair(l, r);
    }

    int start = 0;
    for (int i = 1; i <= n; i++) {
        if (lr[i].first == 0) {
            start = i;
            break;
        }
    }

    int current = start;
    while (current != 0) {
        cout << lr[current].first << " " << lr[current].second << endl;
        current = lr[current].second;
    }
    
    return 0;
}