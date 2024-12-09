#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    
    int result = 0;
    for(int i = 0; i < n; i++){
        if(a[i] == i+1){
            result++;
        }
    }
    
    for(int i = 0; i < n; i++){
        if(a[i] == i+1){
            int j = i;
            while(j < n-1 && a[j] == j+1 && a[j+1] == j+2){
                result++;
                j++;
            }
            i = j;
        }
    }
    
    cout << result << endl;
    
    return 0;
}