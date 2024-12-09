#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> tested(n, 0);
    int m = 0;
    int interesting = 0;

    for(int t = 0; m < n; t++) {
        for(int j = 0; j < k; j++) {
            if(tested[j] == 0) {
                tested[j] = 1;
                m++;
                if(m == n) break;
            }
        }

        int d = 100 * m / n;
        for(int i = 0; i < n; i++) {
            if(((t + 0.5) / a[i]) >= d/100.0 && ((t + 0.5) / a[i]) < (d+1)/100.0) {
                interesting++;
                break;
            }
        }
    }

    cout << interesting << endl;

    return 0;
}