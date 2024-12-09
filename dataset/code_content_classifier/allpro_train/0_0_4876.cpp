#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> ai(n);
    for (int i = 0; i < n; i++) {
        cin >> ai[i];
    }

    long long total_time = 0;
    long long cnt = 0;
    for (int i = n-1; i >= 0; i--) {
        cnt = max(cnt-1, 0LL) + ai[i];
        total_time += cnt;
    }

    cout << total_time << endl;
    
    return 0;
}