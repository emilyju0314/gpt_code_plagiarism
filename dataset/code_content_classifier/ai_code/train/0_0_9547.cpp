#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n, m, k;
        cin >> n >> m >> k;

        vector<int> indices(m);
        for(int i = 0; i < m; i++) {
            cin >> indices[i];
        }

        sort(indices.begin(), indices.end());

        vector<int> distances;
        int prev = -1;
        for(int i = 0; i < m; i++) {
            if(prev != -1) {
                distances.push_back(indices[i] - prev - 1);
            }
            prev = indices[i];
        }

        sort(distances.begin(), distances.end());

        int l = 1, r = n-1;
        for(int i = 0; i < min(k, m); i++) {
            if(distances[i] <= l) {
                l -= distances[i];
            } else {
                l = 0;
            }
        }

        cout << r - l << endl;
    }

    return 0;
}