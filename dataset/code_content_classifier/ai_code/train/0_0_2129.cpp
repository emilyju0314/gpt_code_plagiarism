#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    string s;
    cin >> s;
    
    vector<int> dist(n, 0);
    
    int diameter = 0;
    for(int i = 1; i < n; i++) {
        if(s[i] == s[i-1]) {
            dist[i] = dist[i-1] + 1;
        }
        diameter = max(diameter, dist[i]);
    }
    
    int count = 0;
    for(int i = 0; i < n; i++) {
        if(dist[i] == diameter) {
            count++;
        }
    }
    
    cout << diameter << " " << count << endl;
    
    return 0;
}