#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    long long count = 0;
    map<int, int> cnt;
    cnt[0] = 1;
    int sum = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] < m) sum--;
        else sum++;

        count += cnt[sum];
        cnt[sum]++;
    }

    cout << count << endl;

    return 0;
}