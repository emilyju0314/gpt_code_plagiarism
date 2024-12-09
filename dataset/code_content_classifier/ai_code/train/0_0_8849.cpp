#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void update(vector<int>& arr, int type, int x, int k, int l, int r) {
    if (type == 1) {
        arr[x-1] = k;
    } else if (type == 2) {
        int len = pow(2, k);
        for (int i = l-1; i < r; i += 2*len) {
            reverse(arr.begin() + i, arr.begin() + min(i+len, r));
        }
    } else if (type == 3) {
        int len = pow(2, k);
        for (int i = l-1; i < r; i += 4*len) {
            swap_ranges(arr.begin() + i, arr.begin() + i + len, arr.begin() + i + 2*len);
        }
    }
}

int query(vector<int>& arr, int l, int r) {
    int sum = 0;
    for (int i = l-1; i < r; ++i) {
        sum += arr[i];
    }
    return sum;
}

int main() {
    int n, q;
    cin >> n >> q;
    
    int size = pow(2, n);
    vector<int> arr(size);
    
    for (int i = 0; i < size; ++i) {
        cin >> arr[i];
    }
    
    while (q--) {
        int type;
        cin >> type;
        
        if (type == 4) {
            int l, r;
            cin >> l >> r;
            cout << query(arr, l, r) << endl;
        } else {
            int k, x;
            cin >> k;
            
            if (type == 1) {
                cin >> x;
                update(arr, type, x, k, 0, 0);
            } else {
                update(arr, type, 0, 0, k, size);
            }
        }
    }

    return 0;
}