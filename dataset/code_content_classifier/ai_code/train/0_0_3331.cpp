#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, w;
    cin >> n >> w;

    vector<int> a(2*n);
    for(int i = 0; i < 2*n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    double x = min((double)a[0], (double)a[n]/2.0);
    double total = 3.0*x*n;

    if(total > w) {
        total = w;
    }

    cout << total << endl;

    return 0;
}