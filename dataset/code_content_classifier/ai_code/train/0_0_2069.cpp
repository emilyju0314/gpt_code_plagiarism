#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void enumerateCandidates(string encrypted) {
    vector<string> candidates;
    
    candidates.push_back(encrypted);
    
    for (char c = 'z'; c >= 'b'; c--) {
        vector<string> newCandidates;
        
        for (string candidate : candidates) {
            size_t pos = candidate.find(c);
            while (pos != string::npos) {
                candidate[pos]--;
                newCandidates.push_back(candidate);
                candidate[pos]++;
                pos = candidate.find(c, pos+1);
            }
        }
        
        candidates.insert(candidates.end(), newCandidates.begin(), newCandidates.end());
    }
    
    sort(candidates.begin(), candidates.end());
    
    cout << candidates.size() << endl;
    
    if (candidates.size() <= 10) {
        for (string candidate : candidates) {
            cout << candidate << endl;
        }
    } else {
        for (int i = 0; i < 5; i++) {
            cout << candidates[i] << endl;
        }
        cout << "..." << endl;
        for (int i = candidates.size()-5; i < candidates.size(); i++) {
            cout << candidates[i] << endl;
        }
    }
}

int main() {
    string encrypted;
    
    while (true) {
        cin >> encrypted;
        
        if (encrypted == "#") {
            break;
        }
        
        enumerateCandidates(encrypted);
    }
    
    return 0;
}