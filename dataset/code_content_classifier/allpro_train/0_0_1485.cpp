#include <iostream>
#include <string>
#include <vector>

using namespace std;

int countPairs(string s) {
    int n = s.length();
    vector<int> pref0(n+1), pref1(n+1);
    for(int i=0; i<n; i++) {
        pref0[i+1] = pref0[i] + (s[i] == '0');
        pref1[i+1] = pref1[i] + (s[i] == '1');
    }
    
    int ans = 0;
    for(int l=1; l<=n; l++) {
        for(int r=l; r<=n; r++) {
            for(int x=l; x<r-1; x++) {
                for(int k=1; x+2*k<=r; k++) {
                    if(pref0[x+k]-pref0[x] == pref1[x+2*k]-pref1[x+k]) {
                        ans++;
                        break;
                    }
                }
            }
        }
    }
    
    return ans;
}

int main() {
    string s;
    cin >> s;
    
    cout << countPairs(s) << endl;
    
    return 0;
}