#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    
    while (true) {
        cin >> n;
        
        if (n == 0) {
            break;
        }
        
        map<string, int> points;
        map<string, vector<int>> appearances;
        
        for (int i = 0; i < n; i++) {
            string name;
            int m;
            cin >> name >> m;
            
            for (int j = 0; j < m; j++) {
                int d;
                cin >> d;
                appearances[name].push_back(d);
            }
        }
        
        for (auto it = appearances.begin(); it != appearances.end(); it++) {
            for (int time : it->second) {
                points[it->first]++;
                for (auto other : appearances) {
                    if (other.first != it->first && find(other.second.begin(), other.second.end(), time) != other.second.end()) {
                        points[it->first]--;
                    }
                }
            }
        }
        
        int min_points = INT_MAX;
        string min_name = "";
        
        for (auto it = points.begin(); it != points.end(); it++) {
            if (it->second < min_points) {
                min_points = it->second;
                min_name = it->first;
            } else if (it->second == min_points && it->first < min_name) {
                min_name = it->first;
            }
        }
        
        cout << min_points << " " << min_name << endl;
    }
    
    return 0;
}