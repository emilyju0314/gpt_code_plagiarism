#include <iostream>
#include <vector>
#include <string>

using namespace std;

string f0 = "What are you doing at the end of the world? Are you busy? Will you save us?";

char solve(int n, long long k) {
    if (n == 0) {
        if (k <= f0.length()) {
            return f0[k-1];
        } else {
            return '.';
        }
    }

    string a = "What are you doing while sending \"";
    string b = "\"? Are you busy? Will you send \"";

    if (k <= a.length()) {
        return a[k-1];
    } else if (k <= a.length() + k-1 + f0.length() + b.length()) {
        if (k <= a.length() + 1 + k-1) {
            return solve(n-1, k-a.length());
        } else if (k <= a.length() + 1 + k-1 + f0.length()) {
            return f0[k-a.length()-1-2-(k-1)];
        } else {
            return b[k-a.length()-1-f0.length()-2-(k-1)-1];
        }
    } else {
        return '.';
    }
}

int main() {
    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        int n;
        long long k;
        cin >> n >> k;

        cout << solve(n, k);
    }

    return 0;
}