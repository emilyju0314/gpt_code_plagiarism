#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    double left = a[0], right = a[n-1];
    double ans = a[n-1];

    for(int i = 0; i < 100; i++){
        double mid1 = left + (right - left) / 3;
        double mid2 = right - (right - left) / 3;

        double poorness1 = 0.0;
        double poorness2 = 0.0;

        for(int j = 0; j < n; j++){
            poorness1 += abs(a[j] - mid1);
            poorness2 += abs(a[j] - mid2);
        }

        if(poorness1 < poorness2){
            right = mid2;
            ans = min(ans, poorness1);
        } else {
            left = mid1;
            ans = min(ans, poorness2);
        }
    }

    cout.precision(12);
    cout << fixed << ans << endl;

    return 0;
}