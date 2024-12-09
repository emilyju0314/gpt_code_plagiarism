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
    
    int count = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] == i+1) {
            count++;
        }
    }
    
    int result = count;
    for(int i = 0; i < n; i++) {
        if(a[i] != i+1 && a[a[i]-1] == i+1) {
            result = max(result, count + 2);
        }
    }
    
    cout << result << endl;
    
    return 0;
}