#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        char c;
        cin >> n >> c;

        string s;
        cin >> s;

        vector<int> operations;
        int count = 0;

        for (int i = 1; i <= n; i++) {
            if (s[i-1] != c) {
                if (n % i == 0) {
                    count++;
                    operations.push_back(i);
                    for (int j = 0; j < n; j += i) {
                        s[j] = c;
                    }
                }
            }
        }

        cout << count << endl;
        for (int val : operations) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}