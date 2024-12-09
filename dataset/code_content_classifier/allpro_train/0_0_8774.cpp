#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
    string s, t;
    cin >> s >> t;

    unordered_map<char, int> sIndex, tIndex;
    
    for(int i = 0; i < s.size(); i++) {
        sIndex[s[i]] = i;
    }

    for(int i = 0; i < t.size(); i++) {
        tIndex[t[i]] = i;
    }

    long long res = 0;
    for(int i = 0; i < s.size(); i++) {
        for(int j = 0; j < t.size(); j++) {
            char colorS = s[i];
            char colorT = t[j];
            int diffS = i - sIndex[colorS];
            int diffT = j - tIndex[colorT];

            if(diffS < 0 || diffT < 0 || (diffS % 3 != diffT % 3)) continue;

            res++;
        }
    }

    cout << res << endl;

    return 0;
}