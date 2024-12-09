#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<long long> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    long long max_sum = 0;
    long long sum = 0;
    long long min_odd = 1013; // maximum value of an element in the sequence

    for(int i = 0; i < n; i++) {
        sum += a[i];
        if(i % 2 != 0) {
            min_odd = min(min_odd, a[i]);
        }
        max_sum = max(max_sum, sum - min_odd);
    }

    cout << max_sum << endl;

    return 0;
}