#include <iostream>
#include <vector>

using namespace std;

int main() {
    int L, b, f, n;
    cin >> L >> b >> f;
    
    cin >> n;
    
    vector<pair<int, int>> cars; // pair to store the length of the car and its parking position
    
    for(int i = 0; i < n; i++) {
        int type, length;
        cin >> type >> length;
        
        if(type == 1) {
            int position = -1; // default value if car cannot find parking spot
            
            for(int j = 0; j < cars.size(); j++) {
                int prevPosition = (j == 0) ? 0 : cars[j-1].second;
                int nextPosition = (j == cars.size() - 1) ? L : cars[j].second;
                
                if(cars[j].first <= length && (cars[j].first + b) <= nextPosition && (length + f) <= cars[j].second) {
                    position = max(prevPosition, nextPosition - length);
                    break;
                }
            }
            
            cout << position << endl;
            
            if(position != -1) {
                cars.push_back({length, position});
                sort(cars.begin(), cars.end());
            }
        } else if(type == 2) {
            int index = length - 1; // index of the car leaving the parking lot
            cars.erase(cars.begin() + index);
        }
    }
    
    return 0;
}