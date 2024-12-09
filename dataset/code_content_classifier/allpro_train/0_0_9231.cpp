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

    int maxF = INT_MIN;
    for(int i = 0; i < n-1; i++) {
        for(int j = i+1; j < n; j++) {
            int f = abs(a[i] - a[j]) + j - i;
            maxF = max(maxF, f);
        }
    }

    cout << maxF << endl;

    return 0;
}