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

    long long clicks = 0;
    for(int i = 0; i < n; i++) {
        clicks += 1LL * a[i] * (i + 1);
    }

    cout << clicks << endl;

    return 0;
}