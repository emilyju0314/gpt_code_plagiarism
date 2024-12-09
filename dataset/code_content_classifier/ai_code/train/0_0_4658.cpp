#include <iostream>
#include <vector>
#include <utility>
#include <map>

using namespace std;

bool isValid(int R, int C, vector<pair<int, int>> points) {
    map<int, pair<pair<int, int>, pair<int, int>>> pairs;
    for(auto p : points) {
        int num1 = -1, num2 = -1;
        for(auto pair : pairs) {
            if((p.first == pair.second.first.first && p.second == pair.second.first.second) || 
               (p.first == pair.second.second.first && p.second == pair.second.second.second)) {
                if(num1 == -1) {
                    num1 = pair.first;
                } else {
                    num2 = pair.first;
                }
            }
        }
        
        if(num1 == -1) {
            pairs.emplace(p.first, make_pair(p, make_pair(-1, -1)));
        } else {
            if((p.first == pairs[num1].first.first && p.second == pairs[num1].first.second) || 
               (p.first == pairs[num1].second.first && p.second == pairs[num1].second.second)) {
                if(num2 == -1) {
                    pairs[num1].second = p;
                } else {
                    pairs[num2].first = p;
                }
            } else {
                return false;
            }
        }
    }
    
    return true;
}

int main() {
    int R, C, N;
    cin >> R >> C >> N;
    
    vector<pair<int, int>> points;
    for(int i = 0; i < N; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        points.push_back(make_pair(x1, y1));
        points.push_back(make_pair(x2, y2));
    }
    
    if(isValid(R, C, points)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    
    return 0;
}