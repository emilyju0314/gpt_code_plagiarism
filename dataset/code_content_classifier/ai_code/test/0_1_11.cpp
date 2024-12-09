#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int cnt = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] == i + 1) {
            cnt++;
            a[i] = 0;
        }
    }

    sort(a.begin(), a.end());

    int start = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] > 0) {
            cnt++;
            start = i + 1;
            break;
        }
    }

    for(int i = start; i < n; i++) {
        if(a[i] == i + 1) {
            cnt++;
            break;
        }
    }

    cout << cnt << endl;

    return 0;
}