#include <iostream>
#include <vector>

using namespace std;

int findMinMoves(vector<int>& a) {
    int min_moves = 0;
    int max_count = 0;

    for (int num : a) {
        int count = 0;
        while (num % 2 == 0) {
            num /= 2;
            count++;
        }
        if (count > max_count) {
            max_count = count;
        }
    }

    return max_count;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        int min_moves = findMinMoves(a);
        cout << min_moves << endl;
    }

    return 0;
}