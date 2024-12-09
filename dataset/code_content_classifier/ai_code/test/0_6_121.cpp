#include <iostream>
#include <string>

using namespace std;

int min_operations(string a, string b) {
    int n = a.size();
    int count = 0;
    
    for(int i = n-1; i >= 0; i--) {
        if(a[i] != b[i]) {
            if(a[i] != a[0]) {
                count++;
                for(int j = 0; j <= i; j++) {
                    a[j] = '1' + '0' - a[j];
                }
            } else {
                return -1;
            }
        }
    }
    
    return count;
}

int main() {
    int t;
    cin >> t;
    
    while(t--) {
        int n;
        string a, b;
        cin >> n >> a >> b;
        
        int result = min_operations(a, b);
        cout << result << endl;
    }
    
    return 0;
}