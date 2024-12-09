#include <iostream>
#include <string>
#include <vector>

using namespace std;

string mutate(string dna, int l, int r) {
    string active = dna.substr(l - 1, r - l + 1);
    string mutated = "";
    
    for(int i = 1; i < active.length(); i += 2) {
        mutated += active[i];
    }
    
    for(int i = 0; i < active.length(); i += 2) {
        mutated += active[i];
    }
    
    return dna.substr(0, l - 1) + active + mutated + dna.substr(r, dna.length() - r);
}

int main() {
    string dna;
    cin >> dna;
    
    int k, n;
    cin >> k >> n;
    
    vector<pair<int, int>> mutations;
    
    for(int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        mutations.push_back({l, r});
    }
    
    for(int i = mutations.size() - 1; i >= 0; i--) {
        dna = mutate(dna, mutations[i].first, mutations[i].second);
    }
    
    cout << dna.substr(0, k) << endl;
    
    return 0;
}