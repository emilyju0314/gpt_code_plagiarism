#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> p(n);
    for(int i = 0; i < n; i++) {
        cin >> p[i];
    }

    int num_special = 0;
    for(int i = 0; i < n; i++) {
        int max_val = p[i];
        int l = i, r = i;

        while(l > 0 && p[l-1] < max_val) {
            l--;
        }

        while(r < n-1 && p[r+1] < max_val) {
            r++;
        }

        if(p[l] + p[r] == max_val) {
            num_special++;
        }
    }

    cout << num_special << endl;

    return 0;
}