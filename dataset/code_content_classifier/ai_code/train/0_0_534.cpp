#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main() {
    int n, q, k;
    cin >> n >> q >> k;

    unordered_set<int> contacts[n+1];
    vector<int> days(n+1, 0);

    for(int i = 0; i < q; i++) {
        int t;
        cin >> t;

        if(t == 1) {
            int x, y;
            cin >> x >> y;
            contacts[x].insert(y);
            contacts[y].insert(x);
            days[x] = i+1; 
            days[y] = i+1;
        } else if(t == 2) {
            int z;
            cin >> z;
            int count = 0;
            for(auto c : contacts[z]) {
                if(i+1 - days[c] <= k) {
                    count++;
                }
            }
            cout << count << endl;
        } else {
            // end of the day, do nothing
        }
    }

    return 0;
}