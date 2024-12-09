#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> sizes(n);
    for(int i = 0; i < n; i++) {
        cin >> sizes[i];
    }
    
    sort(sizes.begin(), sizes.end());
    
    int visible = 0;
    
    for(int i = 0; i < n; i++) {
        if(i == 0 || sizes[i] < 2*sizes[i-1]) {
            visible++;
        }
    }
    
    cout << visible << endl;
    
    return 0;
}