#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, x;
    cin >> n >> x;

    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    vector<int> left(x+1, 0);
    vector<int> right(x+1, 0);

    for(int i = 0; i < n; i++){
        left[a[i]]++;
        right[a[i]]++;
    }

    for(int i = 1; i <= x; i++){
        left[i] += left[i-1];
    }

    int ans = 0;
    for(int i = 0; i < n; i++){
        if(a[i] <= x){
            right[a[i]]--;
            if(a[i] > 1){
                ans += left[a[i]-1] - right[a[i]];
            }
        }
    }

    cout << ans << endl;

    return 0;
}