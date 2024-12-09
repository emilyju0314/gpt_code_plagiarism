#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }

        int hills = 0, valleys = 0;
        for(int i = 1; i < n - 1; i++) {
            if((a[i] > a[i-1] && a[i] > a[i+1]) || (a[i] < a[i-1] && a[i] < a[i+1])) {
                if(a[i] != a[i-1] && a[i] != a[i+1]) {
                    if((a[i] > a[i-1] && a[i] > a[i+1])) {
                        hills++;
                    } else {
                        valleys++;
                    }
                }
            }
        }

        int min_intimidation_value = min(hills, valleys);
        cout << min_intimidation_value << endl;
    }

    return 0;
}