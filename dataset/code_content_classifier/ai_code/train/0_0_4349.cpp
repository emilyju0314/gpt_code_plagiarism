#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }

        vector<int> sorted = a;
        sort(sorted.begin(), sorted.end());

        int start = 0, end = n-1;
        while(start < n && a[start] == sorted[start]) {
            start++;
        }
        while(end >= 0 && a[end] == sorted[end]) {
            end--;
        }

        int operations = 0;
        if(start < n && end >= 0) {
            int min_val = INT_MAX;
            for(int i = start; i <= end; i++) {
                if(a[i] < min_val) {
                   min_val = a[i];
                }
            }
            for(int i = start; i <= end; i++) {
                if(a[i] == min_val) {
                    start = i;
                    break;
                }
            }
            operations = 1;
        }

        cout << operations << endl;
    }

    return 0;
}