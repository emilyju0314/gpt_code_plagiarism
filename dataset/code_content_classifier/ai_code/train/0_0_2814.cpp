#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    long long sum = 0;
    long long max_sum = 0;
    long long prev = 0;

    for(int i = 0; i < n; i++) {
        sum += a[i] * i;
        if(i > 0) {
            max_sum = max(max_sum, sum - a[i] * i + prev);
        }
        prev += a[i];
    }

    cout << max_sum << endl;

    return 0;
}