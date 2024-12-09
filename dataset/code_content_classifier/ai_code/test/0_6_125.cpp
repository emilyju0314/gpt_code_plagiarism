#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }

    int cur = 1;
    for(int i=0; i<n; i++) {
        if(a[i] == 0) {
            if(i == 0 || a[i-1] != cur) {
                int next = cur;
                while(next == cur || (i<n-1 && a[i+1] == next)) {
                    next++;
                }
                a[i] = cur;
                cur = next;
            } else {
                a[i] = cur;
            }
        }
    }

    for(int i=0; i<n; i++) {
        cout << a[i] << " ";
    }

    return 0;
}