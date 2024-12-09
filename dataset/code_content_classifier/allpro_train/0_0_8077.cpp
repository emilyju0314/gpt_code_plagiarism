#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    vector<long long> S(n);
    for (int i = 0; i < n; i++) {
        cin >> S[i];
    }

    sort(S.begin(), S.end());

    long long sum = 0;
    for (int i = 0; i < n; i++) {
         sum += S[i];
    }

    cout << (S[n-1] - sum) + n << endl;

    for (int i = 0; i < q; i++) {
        int t;
        long long a;
        cin >> t >> a;

        if (t == 1) {
            S.push_back(a);
        } else {
            S.erase(remove(S.begin(), S.end(), a), S.end());
        }

        sort(S.begin(), S.end());

        sum = 0;
        for (int j = 0; j < S.size(); j++) {
            sum += S[j];
        }

        cout << (S[S.size()-1] - sum) + S.size() << endl;
    }

    return 0;
}