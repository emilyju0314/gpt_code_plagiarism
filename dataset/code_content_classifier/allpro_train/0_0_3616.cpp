#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    map<string, vector<pair<int, int>>> restaurants;
    
    for(int i = 1; i <= N; i++) {
        string city;
        int score;
        cin >> city >> score;
        
        restaurants[city].push_back({score, i});
    }
    
    for(auto it = restaurants.begin(); it != restaurants.end(); it++) {
        sort(it->second.rbegin(), it->second.rend());
    }
    
    for(auto it = restaurants.begin(); it != restaurants.end(); it++) {
        for(auto restaurant : it->second) {
            cout << restaurant.second << endl;
        }
    }
    
    return 0;
}