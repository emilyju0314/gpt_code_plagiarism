#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    
    int n;
    cin >> n;
    
    vector<int> banknotes(n);
    
    for(int i = 0; i < n; i++) {
        cin >> banknotes[i];
    }
    
    sort(banknotes.begin(), banknotes.end());
    
    int count = 0;
    
    for(int i = 0; i < n; i++) {
        if(banknotes[i] > b && banknotes[i] < c) {
            count++;
        }
    }
    
    cout << count << endl;
    
    return 0;
}