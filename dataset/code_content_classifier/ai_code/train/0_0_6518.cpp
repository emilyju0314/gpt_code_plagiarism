#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int n, q, s, d;
    cin >> n >> q >> s >> d;

    vector<int> rocks(n);
    for(int i = 0; i < n; i++) {
        cin >> rocks[i];
    }

    sort(rocks.begin(), rocks.end());

    for(int i = 0; i < q; i++) {
        int dest, k;
        cin >> dest >> k;
        
        int diff = abs(rocks[dest-1] - rocks[s-1]);

        if(diff <= d) {
            cout << "Yes" << endl;
        } else {
            if(k >= diff) {
                cout << "Yes" << endl;
            } else {
                bool reachable = false;
                for(int j = dest-1; j >= 0; j--) {
                    if(abs(rocks[j] - rocks[s-1]) <= d) {
                        if(abs(rocks[dest-1] - rocks[j]) <= k) {
                            reachable = true;
                            break;
                        }
                    } else {
                        break;
                    }
                }
                if(reachable) {
                    cout << "Yes" << endl;
                } else {
                    reachable = false;
                    for(int j = dest-1; j < n; j++) {
                        if(abs(rocks[j] - rocks[s-1]) <= d) {
                            if(abs(rocks[dest-1] - rocks[j]) <= k) {
                                reachable = true;
                                break;
                            }
                        } else {
                            break;
                        }
                    }
                    if(reachable) {
                        cout << "Yes" << endl;
                    } else {
                        cout << "No" << endl;
                    }
                }
            }
        }
    }

    return 0;
}