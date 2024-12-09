#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> tubes(n);
    for(int i = 0; i < n; i++){
        cin >> tubes[i];
    }

    vector<pair<int, int>> actions; // pair<pi, xi>
    for(int i = 0; i < q; i++){
        int type;
        cin >> type;
        if(type == 1){
            int pi, xi;
            cin >> pi >> xi;
            actions.push_back({pi-1, xi});
        }
        else{
            long long vi;
            cin >> vi;
            long double ans = 0.0;
            for(int j = 0; j < n; j++){
                long double filled = max(tubes[j], (long long)vi);
                ans = max(ans, filled);
            }
            cout << fixed << setprecision(6) << ans << endl;
        }
    }

    return 0;
}