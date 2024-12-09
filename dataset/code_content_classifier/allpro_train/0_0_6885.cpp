#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> ingredients(n);
    vector<int> available(n);

    for(int i = 0; i < n; i++) {
        cin >> ingredients[i];
    }
    
    for(int i = 0; i < n; i++) {
        cin >> available[i];
    }

    int maxCookies = 0;
    
    int low = 0, high = 1e9;
    while(low <= high) {
        int mid = (low + high) / 2;
        
        long long extraPowder = 0;

        for(int i = 0; i < n; i++) {
            long long needed = (long long)mid * ingredients[i];
            long long diff = needed - available[i];
            
            if(diff > 0) {
                extraPowder += diff;
            }
        }

        if(extraPowder <= (long long)k) {
            maxCookies = max(maxCookies, mid);
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    cout << maxCookies << endl;

    return 0;
}