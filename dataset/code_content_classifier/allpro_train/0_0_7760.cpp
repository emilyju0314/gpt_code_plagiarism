#include <iostream>
#include <set>
using namespace std;

int main() {
    int n;
    cin >> n;

    set<long long> numbers;
    numbers.insert(0);

    for (int i = 0; i < n; i++) {
        int t;
        long long l, r;
        cin >> t >> l >> r;

        if (t == 1) {
            auto it = numbers.lower_bound(l);
            while (*it <= r) {
                numbers.insert(*it);
                it++;
            }
        } else if (t == 2) {
            auto it = numbers.lower_bound(l);
            while (*it <= r) {
                numbers.erase(*it);
                it++;
            }
        } else if (t == 3) {
            auto it = numbers.lower_bound(l);
            while (*it <= r) {
                if (numbers.count(*it) > 0) {
                    numbers.erase(*it);
                } else {
                    numbers.insert(*it);
                }
                it++;
            }
        }

        auto mex = numbers.begin();
        while (*mex == *(next(mex))) {
            mex = next(mex);
        }
        cout << *mex << endl;
    }

    return 0;
}