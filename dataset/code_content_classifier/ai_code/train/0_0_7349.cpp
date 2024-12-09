#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

int leastColors(vector<vector<string>> territories) {
    map<string, set<string>> borders;
    
    for(auto& territory : territories) {
        string country = territory[0];
        for(int i = 1; i < territory.size() - 1; i++) {
            borders[country].insert(territory[i]);
        }
    }
    
    int colors = 1;
    map<string, int> colorMap;
    
    for(auto& border : borders) {
        for(auto& neighbor : border.second) {
            if(colorMap[neighbor] == colors) colors++;
        }
        colorMap[border.first] = colors;
    }
    
    return colors;
}

int main() {
    int n;
    while(cin >> n && n != 0) {
        vector<vector<string>> territories;
        
        for(int i = 0; i < n; i++) {
            vector<string> territory;
            string input;
            while(cin >> input && input != "-1") {
                territory.push_back(input);
            }
            territories.push_back(territory);
        }
        
        cout << leastColors(territories) << endl;
    }
    
    return 0;
}