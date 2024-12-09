#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> tabs(n);
    for(int i = 0; i < n; i++) {
        cin >> tabs[i];
    }

    int max_absolute_difference = 0;
    for(int b = 0; b < k; b++) {
        int e = 0, s = 0;
        for(int i = b; i < n; i += k) {
            if(tabs[i] == 1) {
                e++;
            } else {
                s++;
            }
        }
        max_absolute_difference = max(max_absolute_difference, abs(e - s));
    }

    cout << max_absolute_difference << endl;

    return 0;
}