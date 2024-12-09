#include <bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define pii pair<int, int>
#define ll long long
#define ld long double

using namespace std;

int main() {
    fastIO;
    
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        
        int total = 0;
        for (int i = 1; i < n - 1; i++) {
            if ((a[i - 1] < a[i] && a[i + 1] < a[i]) || (a[i - 1] > a[i] && a[i + 1] > a[i])) total++;
        }
        
        int mxRemove = 0;
        for (int i = 1; i < n - 1; i++) {
            int best = 0;
            int original = 1;
            if ((a[i] > a[i - 1] && a[i] > a[i + 1]) || (a[i] < a[i + 1] && a[i] < a[i - 1])) {
                // check original
                if (i - 2 >= 0 && a[i - 2] > a[i - 1] && a[i] > a[i - 1]) original++;
                else if (i - 2 >= 0 && a[i - 2] < a[i - 1] && a[i] < a[i - 1]) original++;
                
                if (i + 2 < n && a[i + 2] > a[i + 1] && a[i] > a[i + 1]) original++;
                else if (i + 2 < n && a[i + 2] < a[i + 1] && a[i] < a[i + 1]) original++;
                
                int temp = a[i];
                // set to either
                a[i] = a[i - 1];
                if (i - 2 >= 0 && a[i - 2] > a[i - 1] && a[i] > a[i - 1]) best++;
                else if (i - 2 >= 0 && a[i - 2] < a[i - 1] && a[i] < a[i - 1]) best++;
                
                if (i + 2 < n && a[i + 2] > a[i + 1] && a[i] > a[i + 1]) best++;
                else if (i + 2 < n && a[i + 2] < a[i + 1] && a[i] < a[i + 1]) best++;
                
                mxRemove = max(mxRemove, original - best);
                
                best = 0;
                a[i] = a[i + 1];
                if (i - 2 >= 0 && a[i - 2] > a[i - 1] && a[i] > a[i - 1]) best++;
                else if (i - 2 >= 0 && a[i - 2] < a[i - 1] && a[i] < a[i - 1]) best++;
                
                if (i + 2 < n && a[i + 2] > a[i + 1] && a[i] > a[i + 1]) best++;
                else if (i + 2 < n && a[i + 2] < a[i + 1] && a[i] < a[i + 1]) best++;
                
                a[i] = temp;
                
                
            }
            mxRemove = max(mxRemove, original - best);
        }
        
        cout << max(0, total - mxRemove) << "\n";
    }
}
