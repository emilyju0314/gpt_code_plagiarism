#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> logs(n);
    for(int i = 0; i < n; i++) {
        cin >> logs[i];
    }

    sort(logs.rbegin(), logs.rend());

    int x = logs[0], y = logs[1];
    long long max_area = 0;

    for(int i = 2; i < n; i++) {
        max_area = max(max_area, (long long)x * y);
        if(logs[i] >= x) {
            y = x;
            x = logs[i];
        } else if(logs[i] >= y) {
            y = logs[i];
        }
    }

    max_area = max(max_area, (long long)x * y);
    
    cout << max_area << endl;

    return 0;
}