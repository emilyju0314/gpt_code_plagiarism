#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> friends(n, 0);

        for (int i = 1; i < n; i++) {
            for (int j = 2*i; j < n; j += i) {
                friends[j]++;
            }
        }

        int total = 0;
        for (int i = 1; i < n; i++) {
            total += (friends[i] == i);
        }

        cout << total << endl;
    }

    return 0;
}