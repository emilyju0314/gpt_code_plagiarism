#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n-1);
    for(int i = 0; i < n-1; i++) {
        cin >> a[i];
    }

    vector<long long> res(n-1, -1);

    map<int, int> last_occurrence;
    long long x = 1, y = 0;
    last_occurrence[x] = 0;
    for(int i = 1; i < n; i++) {
        if(last_occurrence.count(x) > 0) {
            int prev = last_occurrence[x];
            if(res[prev] != -1) {
                for(int j = prev; j < i-1; j++) {
                    res[j] = y;
                }
                break;
            } else {
                res[prev] = y;
                for(int j = prev+1; j < i-1; j++) {
                    res[j] = -1;
                }
                break;
            }
        }
        y += a[i-1];
        x += a[i-1];

        last_occurrence[x] = i;
    }

    for(int i = 0; i < n-1; i++) {
        cout << res[i] << endl;
    }

    return 0;
}