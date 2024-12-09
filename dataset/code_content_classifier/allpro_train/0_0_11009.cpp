#include <iostream>
#include <vector>

using namespace std;

int minDepth(vector<int>& perm) {
    int n = perm.size();
    vector<int> depth(n, 0);
    
    int min_depth = 0;
    for (int i = 0; i < n; ++i) {
        depth[i] = 1;
        if (i > 0 && perm[i] > perm[i-1]) {
            depth[i] = depth[i-1] + 1;
        }
        min_depth = max(min_depth, depth[i]);
    }
    
    return min_depth;
}

int main() {
    int n;
    cin >> n;
    
    vector<int> perm(n);
    for (int i = 0; i < n; ++i) {
        cin >> perm[i];
    }
    
    int min_depth = minDepth(perm);
    
    int shift = 0;
    while (minDepth(perm) != min_depth) {
        perm.push_back(perm[0]);
        perm.erase(perm.begin());
        shift++;
    }
    
    cout << min_depth << " " << shift << endl;
    
    return 0;
}