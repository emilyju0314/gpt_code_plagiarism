#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

bool checkCodes(vector<string>& airports, int k) {
    unordered_set<string> codes;
    
    for (string airport: airports) {
        string code;
        
        for (int i = 0; i < airport.size(); i++) {
            if (airport[i] == 'a' || airport[i] == 'e' || airport[i] == 'i' || airport[i] == 'o' || airport[i] == 'u') {
                code += airport[i];
                if (code.size() == k) break;
            }
        }
        
        if (code.size() < k) {
            code = airport[0] + code;
        }
        
        if (codes.find(code) != codes.end()) {
            return false;
        }
        
        codes.insert(code);
    }
    
    return true;
}

int main() {
    int n;
    
    while (cin >> n && n != 0) {
        vector<string> airports;
        
        for (int i = 0; i < n; i++) {
            string airport;
            cin >> airport;
            airports.push_back(airport);
        }
        
        int k = 1;
        bool allDifferent = false;
        
        while (k <= 50) {
            if (checkCodes(airports, k)) {
                allDifferent = true;
                break;
            }
            k++;
        }
        
        if (allDifferent) {
            cout << k << endl;
        } else {
            cout << -1 << endl;
        }
    }
    
    return 0;
}