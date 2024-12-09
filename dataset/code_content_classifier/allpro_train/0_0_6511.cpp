#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int getMinMoves(string A, string B) {
    vector<int> cnt(26, 0); // Count occurrences of each letter in A - 'a'

    int n = A.size();
    for (int i = 0; i < n; i++) {
        cnt[A[i] - 'a']++;
    }

    for (int i = 0; i < n; i++) {
        if (B[i] < A[i]) {
            return -1; // If B[i] is less than A[i], it's impossible to make them equal
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (A[i] != B[i]) {
            if (cnt[B[i] - 'a'] > 0) {
                cnt[B[i] - 'a']--;
            } else {
                ans++;
            }
        }
    }

    return ans;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        string A, B;
        cin >> A >> B;

        int minMoves = getMinMoves(A, B);
        cout << minMoves << endl;
    }

    return 0;
}