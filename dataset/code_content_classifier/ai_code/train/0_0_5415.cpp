#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n;
    
    unordered_map<int, int> audioCount, subtitleCount, bothCount;
    vector<int> scientists(n);
    
    for (int i = 0; i < n; i++) {
        cin >> scientists[i];
    }
    
    cin >> m;
    
    vector<int> audio(m), subtitle(m);
    
    for (int i = 0; i < m; i++) {
        cin >> audio[i];
        audioCount[audio[i]]++;
    }
    
    for (int i = 0; i < m; i++) {
        cin >> subtitle[i];
        subtitleCount[subtitle[i]]++;
    }
    
    for (int i = 0; i < m; i++) {
        int veryPleased = audioCount[audio[i]] + subtitleCount[subtitle[i]] - bothCount[audio[i]];
        int almostSatisfied = min(audioCount[audio[i]], subtitleCount[subtitle[i]]);
        
        if (veryPleased > bothCount[audio[i]] || (veryPleased == bothCount[audio[i]] && almostSatisfied > bothCount[audio[i]])) {
            cout << i + 1 << endl;
            break;
        }
    }

    return 0;
}