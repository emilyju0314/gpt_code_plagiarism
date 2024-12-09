#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int max_diff = 0;
    
    vector<int> l_indices;
    for(int i = 0; i < n; i++) {
        int l = i;
        int r = i;
        
        int gcd = a[i];
        while(r < n && a[r] % gcd == 0) {
            r++;
            gcd = __gcd(gcd, a[r]);
        }

        r--;

        if(r - l > max_diff) {
            max_diff = r - l;
            l_indices.clear();
            l_indices.push_back(l + 1);
        } else if(r - l == max_diff) {
            l_indices.push_back(l + 1);
        }

    }

    cout << l_indices.size() << " " << max_diff << endl;
    for(int i = 0; i < l_indices.size(); i++) {
        cout << l_indices[i] << " ";
    }
    cout << endl;

    return 0;
}