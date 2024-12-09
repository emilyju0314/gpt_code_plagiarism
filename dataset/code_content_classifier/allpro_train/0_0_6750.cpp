#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>

using namespace std;

int main() {
    int N, M;
    cin >> N;
    
    unordered_map<string, int> doors;
    for (int i = 0; i < N; i++) {
        string door;
        cin >> door;
        doors[door] = 1;
    }
    
    cin >> M;
    
    vector<pair<string, pair<int, int>>> cards;
    for (int i = 0; i < M; i++) {
        string card;
        int price;
        cin >> card >> price;
        cards.push_back(make_pair(card, make_pair(price, 0)));
    }
    
    for (auto& door : doors) {
        for (auto& card : cards) {
            if (door.first[0] == card.first[0] || door.first[1] == card.first[1]) {
                card.second.second++;
            }
        }
    }
    
    int total_price = 0;
    for (auto& card : cards) {
        if (card.second.second == 0) {
            cout << -1 << endl;
            return 0;
        }
        total_price += card.second.first;
    }
    
    cout << total_price << endl;
    
    return 0;
}