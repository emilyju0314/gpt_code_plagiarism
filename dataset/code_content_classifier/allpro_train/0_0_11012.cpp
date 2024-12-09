#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

int countSets(int n, int k, vector<string>& cards) {
    int count = 0;
    
    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            string target(k, ' ');
            
            for(int f = 0; f < k; f++) {
                if(cards[i][f] == cards[j][f]) {
                    target[f] = cards[i][f];
                } else {
                    if(cards[i][f] != 'S' && cards[j][f] != 'S') target[f] = 'S';
                    if(cards[i][f] != 'E' && cards[j][f] != 'E') target[f] = 'E';
                    if(cards[i][f] != 'T' && cards[j][f] != 'T') target[f] = 'T';
                }
            }
            
            if(find(cards.begin(), cards.end(), target) != cards.end()) count++;
        }
    }
    
    return count;
}

int main() {
    int n, k;
    cin >> n >> k;
    
    vector<string> cards(n);
    for(int i = 0; i < n; i++) {
        cin >> cards[i];
    }
    
    cout << countSets(n, k, cards) << endl;
    
    return 0;
}