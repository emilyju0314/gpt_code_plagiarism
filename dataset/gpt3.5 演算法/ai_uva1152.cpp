#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int mod(int a, int b) {
    if (b == 0) return 1;
    int ans = 1;
    for (int i = 0; i < b; i++) {
        ans = (ans * a) % 2;
    }
    return ans;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        vector<int> fib(n+1);
        fib[0] = 0;
        fib[1] = 1;
        for (int i = 2; i <= n; i++) {
            fib[i] = (fib[i-1] + fib[i-2]) % 2;
        }

        map<int, int> numIndex;
        for (int i = 0; i <= n; i++) {
            numIndex[fib[i]] = i;
        }

        for (int i = 0; i <= n; i++) {
            if (i > 0) cout << " ";
            cout << numIndex[mod(2, i)];
        }
        cout << endl;
    }

    return 0;
}
