#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> serves(n);
    for(int i = 0; i < n; i++) {
        cin >> serves[i];
    }
    
    unordered_set<int> possibleS;
    for(int t = 1; t <= n; t++) {
        int idx = 0;
        int s = 0;
        bool valid = true;
        while(idx < n) {
            int petyaScore = 0, genaScore = 0;
            while(idx < n && (serves[idx] == 1 || petyaScore < t) && (serves[idx] == 2 || genaScore < t)) {
                if(serves[idx] == 1) {
                    petyaScore++;
                } else {
                    genaScore++;
                }
                idx++;
            }
            if(petyaScore != t && genaScore != t) {
                valid = false;
                break;
            }
            s++;
        }
        if(valid) {
            possibleS.insert(s);
        }
    }
    
    cout << possibleS.size() << endl;
    for(int s : possibleS) {
        cout << "1 " << s << endl;
    }
    
    return 0;
}