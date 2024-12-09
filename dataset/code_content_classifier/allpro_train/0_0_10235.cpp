#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> calculateFingerprint(int key) {
    vector<int> fingerprint;
    while (key > 0) {
        int remainder = key % 2;
        fingerprint.push_back(remainder);
        key /= 2;
    }
    return fingerprint;
}

int main() {
    int t;
    cin >> t;
    
    for (int i = 0; i < t; i++) {
        long long key;
        cin >> key;
        
        vector<int> fingerprint = calculateFingerprint(key);
        
        unordered_map<vector<int>, int> fingerprintMap;
        fingerprintMap[fingerprint]++;
        
        int count = 0;
        
        while (key <= 1e18) {
            key++;
            vector<int> newFingerprint = calculateFingerprint(key);
            
            if (fingerprintMap[newFingerprint] > 0) {
                count++;
            }
        }
        
        cout << count << endl;
    }
    
    return 0;
}