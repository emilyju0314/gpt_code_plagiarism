#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    
    vector<int> warriors(n);
    for(int i = 0; i < n; i++) {
        cin >> warriors[i];
    }
    
    int q;
    cin >> q;
    
    int last = 0;
    while(q--) {
        int xi, yi;
        cin >> xi >> yi;
        
        int li = ((xi + last) % n) + 1;
        int ri = ((yi + last) % n) + 1;
        
        if(li > ri) {
            swap(li, ri);
        }
        
        int max_size = 0;
        vector<int> count(100001, 0);
        int unique_types = 0;
        int l = 0;
        
        for(int r = 0; r < n; r++) {
            if(count[warriors[r]] == 0) {
                unique_types++;
            }
            count[warriors[r]]++;
            
            while(unique_types > k) {
                count[warriors[l]]--;
                if(count[warriors[l]] == 0) {
                    unique_types--;
                }
                l++;
            }
            
            if(r - l + 1 > max_size && l >= li - 1 && r <= ri - 1) {
                max_size = r - l + 1;
            }
        }
        
        last = max_size;
        cout << max_size << endl;
    }
    
    return 0;
}