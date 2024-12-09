#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> a(n), b(n);
    unordered_map<int, int> indexMap;
    
    for(int i=0; i<n; i++) {
        cin >> a[i];
        indexMap[a[i]] = i;
    }
    
    for(int i=0; i<n; i++) {
        cin >> b[i];
    }
    
    int ans = 0;
    int lastIndex = 0;
    
    for(int i=0; i<n; i++) {
        if(b[i] != 0) {
            int targetIndex = indexMap[b[i]];
            if(targetIndex < lastIndex) {
                ans += n - lastIndex + targetIndex;
            } else {
                ans += targetIndex - lastIndex;
            }
            lastIndex = targetIndex;
        }
    }
    
    cout << ans << endl;
    
    return 0;
}