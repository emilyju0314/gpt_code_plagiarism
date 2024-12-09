#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> coatHanger(n, 0);
    map<int, int> occupiedHooks;

    for(int i = 0; i < q; i++) {
        int request;
        cin >> request;

        if(request == 0) {
            int i, j;
            cin >> i >> j;

            int count = 0;
            for(auto it = occupiedHooks.lower_bound(i); it != occupiedHooks.upper_bound(j); it++) {
                count++;
            }
            cout << count << endl;
        } else {
            if(occupiedHooks.find(request) == occupiedHooks.end()) {
                int left = request, right = request;
                auto it = occupiedHooks.upper_bound(request);
                if(it != occupiedHooks.end()) {
                    right = it->second;
                    occupiedHooks.erase(it);
                }
                it = occupiedHooks.lower_bound(request);
                if(it != occupiedHooks.begin()) {
                    it--;
                    left = it->first;
                    if(it->second == request) {
                        left = it->first;
                        occupiedHooks.erase(it);
                    }
                }
                int mid = (left + right) / 2;
                occupiedHooks[left] = mid;
                occupiedHooks[mid] = right;
            } else {
                occupiedHooks.erase(request);
            }
        }
    }

    return 0;
}