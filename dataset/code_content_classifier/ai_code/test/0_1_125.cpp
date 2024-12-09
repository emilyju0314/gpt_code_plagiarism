#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    vector<int> count(n+1, 0);
    
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(a[i] == 0) {
            count[0]++;
        } else {
            count[a[i]]++;
        }
    }
    
    int filler = 1;
    for(int i = 0; i < n; i++) {
        if(a[i] == 0) {
            while(count[filler] > 0) {
                filler++;
            }
            count[filler]++;
            a[i] = filler;
        }
    }
    
    for(int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    
    cout << endl;
    
    return 0;
}