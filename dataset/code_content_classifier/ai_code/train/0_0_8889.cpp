#include <iostream>
#include <vector>

using namespace std;

int main() {
    long long n, q;
    cin >> n >> q;

    vector<long long> queries(q);
    for (int i = 0; i < q; i++) {
        cin >> queries[i];
    }

    for (int i = 0; i < q; i++) {
        long long x = queries[i];
        long long result;
        if (x % 2 == 1) {
            result = (x + 1) / 2;
        } else {
            result = n / 2 + (x / 2);
        }
        cout << result << endl;
    }

    return 0;
}