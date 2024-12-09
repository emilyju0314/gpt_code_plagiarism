#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> sequence(n);
    for(int i = 0; i < n; i++) {
        cin >> sequence[i];
    }
    
    sort(sequence.begin(), sequence.end());
    
    int changes = 0;
    int count = 1;
    for(int i = 0; i < n; i++) {
        if(sequence[i] == count) {
            count++;
        } else {
            changes++;
        }
    }
    
    cout << changes << endl;
    
    return 0;
}