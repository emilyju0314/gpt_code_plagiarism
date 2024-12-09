#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<pair<char, int>> cards;
    int red_tokens = 0, blue_tokens = 0;
    
    for (int i = 0; i < n; i++) {
        char color;
        int red, blue;
        cin >> color >> red >> blue;
        
        cards.push_back(make_pair(color, red));
        cards.push_back(make_pair(color, blue));
    }
    
    int turns = 0;
    
    for (auto card : cards) {
        char color = card.first;
        int cost = card.second;
        
        if (color == 'R') {
            if (red_tokens < cost) {
                turns += cost - red_tokens;
                red_tokens = cost;
            }
            blue_tokens++;
        } else {
            if (blue_tokens < cost) {
                turns += cost - blue_tokens;
                blue_tokens = cost;
            }
            red_tokens++;
        }
    }
    
    cout << turns << endl;
    
    return 0;
}