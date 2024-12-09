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
    
    int colors = 1;
    for(int i = 0; i < n-1; i++) {
        if(sizes[i] * 2 >= sizes[i+1]) {
            colors++;
        }
    }
    
    cout << colors << endl;
    
    return 0;
}