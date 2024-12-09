#include <iostream>
#include <set>
#include <iomanip>

using namespace std;

int main() {
    int Q;
    cin >> Q;

    multiset<long long> S;
    long long sum = 0;

    for (int i = 0; i < Q; i++) {
        int type;
        cin >> type;

        if (type == 1) {
            long long x;
            cin >> x;
            S.insert(x);
            sum += x;
        } else {
            int n = S.size();
            long long max_element = *S.rbegin();
            double average = (double)sum / n;
            cout << fixed << setprecision(10) << max_element - average << endl;
        }
    }

    return 0;
}