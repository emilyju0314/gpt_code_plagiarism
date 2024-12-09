#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        long long n;
        cin >> n;

        vector<long long> s = {1, 2, 3};
        while (s.size() < n) {
            long long a = s[s.size() - 3];
            long long b = s[s.size() - 2];
            long long c = s[s.size() - 1];
            long long next = a ^ b ^ c;

            // Find the lexicographically smallest triple of positive integers
            while (find(s.begin(), s.end(), next) != s.end()) {
                next++;
            }

            s.push_back(next);
        }

        cout << s[n - 1] << endl;
    }

    return 0;
}