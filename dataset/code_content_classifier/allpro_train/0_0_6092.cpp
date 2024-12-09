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

    string binary;
    cin >> binary;

    int m = binary.size();
    int max_val = 0;

    for(int i = 0; i < m; i++) {
        if(binary[i] == '1') {
            max_val = max(max_val, max_val + a[m - i - 1]);
        }
    }

    cout << max_val << endl;

    return 0;
}