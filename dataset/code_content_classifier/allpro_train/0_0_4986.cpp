#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> a(k);
    for (int i = 0; i < k; i++) {
        cin >> a[i];
    }

    int curr_leader = 1;
    for (int i = 0; i < k; i++) {
        int to_eliminate = (curr_leader + a[i] - 1) % n;
        if (to_eliminate == 0) {
            to_eliminate = n;
        }
        cout << to_eliminate << " ";
        n--;
        curr_leader = to_eliminate;
    }

    return 0;
}