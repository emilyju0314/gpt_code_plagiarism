#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, s;
    cin >> n >> s;
    
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    vector<int> superiors(n, 0);
    for(int i = 0; i < n; i++) {
        if(i == s-1) continue; // skip the chief
        superiors[a[i]]++;
    }
    
    int mistakes = 0;
    for(int i = 0; i < n; i++) {
        if(i == s-1) continue; // skip the chief
        if(superiors[i] != a[i]) {
            mistakes++;
        }
    }
    
    cout << mistakes << endl;
    
    return 0;
}