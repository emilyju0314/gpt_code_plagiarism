#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> serves(n);
    unordered_map<int, int> serveCount;
    unordered_map<pair<int, int>, bool> possibleOptions;
    
    for (int i = 0; i < n; i++) {
        cin >> serves[i];
        serveCount[serves[i]]++;
    }
    
    int petyaWins = 0, genaWins = 0;
    for (int i = 0; i < n; i++) {
        if (serves[i] == 1) {
            petyaWins++;
        } else {
            genaWins++;
        }
        
        if (petyaWins > genaWins) {
            if (possibleOptions.find(make_pair(petyaWins, petyaWins - genaWins)) == possibleOptions.end())
                possibleOptions[make_pair(petyaWins, petyaWins - genaWins)] = true;
        } else {
            if (possibleOptions.find(make_pair(genaWins, genaWins - petyaWins)) == possibleOptions.end())
                possibleOptions[make_pair(genaWins, genaWins - petyaWins)] = true;
        }
    }
    
    int count = 0;
    for (auto it = possibleOptions.begin(); it!=possibleOptions.end(); it++) {
        if (it->first.first * 2 > n) {
            if (it->first.first != n) {
                count++;
            }
        }
    }
    
    cout << count << endl;
    
    for (auto it = possibleOptions.begin(); it!=possibleOptions.end(); it++) {
        if (it->first.first * 2 > n) {
            if (it->first.first != n) {
                cout << it->first.first << " " << it->first.second << endl;
            }
        }
    }
    
    return 0;
}