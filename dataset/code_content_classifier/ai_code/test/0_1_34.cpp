#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    const int MAX_X = 8192;
    vector<bool> possible(MAX_X, false);
    
    possible[0] = true;
    
    for(int i = 0; i < n; i++) {
        for(int j = MAX_X-1; j >= 0; j--) {
            if(possible[j]) {
                possible[j ^ a[i]] = true;
            }
        }
    }
    
    vector<int> result;
    for(int i = 0; i < MAX_X; i++) {
        if(possible[i]) {
            result.push_back(i);
        }
    }
    
    cout << result.size() << endl;
    for(int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    
    return 0;
}