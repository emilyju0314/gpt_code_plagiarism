#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<string> hashtags(n);
    for(int i = 0; i < n; i++) {
        cin >> hashtags[i];
    }
    
    sort(hashtags.begin(), hashtags.end());
    
    for(int i = 0; i < n - 1; i++) {
        int j = 1;
        while(j < min(hashtags[i].size(), hashtags[i+1].size()) && hashtags[i][j] == hashtags[i+1][j]) {
            j++;
        }
        hashtags[i] = hashtags[i].substr(0, j);
    }
    
    for(int i = 0; i < n; i++) {
        cout << hashtags[i] << endl;
    }
    
    return 0;
}