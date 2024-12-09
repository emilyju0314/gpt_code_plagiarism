#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, s;
    cin >> n >> s;

    vector<int> a(n);
    vector<int> cnt(n+1, 0);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }

    int mistakes = 0;

    if (cnt[0] != 1) {
        mistakes++;
    }

    for (int i = 1; i <= n; i++) {
        if (i != s && cnt[i] == 0) {
            mistakes++;
        }
    }

    cout << mistakes << endl;

    return 0;
}