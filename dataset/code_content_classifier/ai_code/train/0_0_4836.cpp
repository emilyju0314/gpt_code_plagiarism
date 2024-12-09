#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    while(true) {
        int n, m;
        cin >> n >> m;
        
        if(n == 0 && m == 0) {
            break;
        }
        
        vector<pair<int, int>> places(m); // <place_number, number_of_people>
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                int choice;
                cin >> choice;
                if(choice == 1) {
                    places[j].second++;
                }
            }
        }
        
        sort(places.begin(), places.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            if(a.second == b.second) {
                return a.first > b.first;
            } else {
                return a.second > b.second;
            }
        });
        
        for(auto& p : places) {
            cout << p.first + 1 << " ";
        }
        cout << endl;
    }
    
    return 0;
}