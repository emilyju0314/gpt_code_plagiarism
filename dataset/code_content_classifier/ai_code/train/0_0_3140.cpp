#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

string find_stolen_string(int n, int m) {
    vector<string> original_strings(n);
    vector<string> exchanged_strings(n - 1);
    
    // Read the original strings
    for (int i = 0; i < n; i++) {
        cin >> original_strings[i];
    }
    
    // Read the exchanged strings
    for (int i = 0; i < n - 1; i++) {
        cin >> exchanged_strings[i];
    }
    
    unordered_map<string, int> count;
    for (auto str : original_strings) {
        count[str]++;
    }
    
    for (auto str : exchanged_strings) {
        count[str]--;
    }
    
    for (auto entry : count) {
        if (entry.second > 0) {
            return entry.first;
        }
    }
    
    return "";
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n, m;
        cin >> n >> m;
        
        string stolen_string = find_stolen_string(n, m);
        cout << stolen_string << endl;
        cout.flush();  // Flush the output buffer
    }
    
    return 0;
}