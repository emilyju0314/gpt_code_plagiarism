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

    int operations = 0;
    int currMin = 1; // minimum number that needs to be deleted
    int count = 0; // number of elements with value currMin

    while(operations < n) {
        if(count == 0) {
            if(currMin <= n && a[currMin - 1] == 0) {
                currMin++;
                continue;
            }
            if(currMin <= n) {
                count = a[currMin - 1];
                operations++;
            }
        } else {
            operations++;
            a[currMin - 1]--;
            count--;
        }
    }

    cout << operations << endl;

    return 0;
}