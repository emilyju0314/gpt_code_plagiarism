#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    string houses;
    cin >> houses;
    
    vector<string> possibleHouses = {"Gryffindor", "Hufflepuff", "Ravenclaw", "Slytherin"};
    
    vector<int> houseCount(4, 0);
    
    for(int i = 0; i < n; i++) {
        if(houses[i] != '?') {
            if(houses[i] == 'G')
                houseCount[0]++;
            else if(houses[i] == 'H')
                houseCount[1]++;
            else if(houses[i] == 'R')
                houseCount[2]++;
            else if(houses[i] == 'S')
                houseCount[3]++;
        }
    }
    
    vector<string> result;
    
    for(int i = 0; i < 4; i++) {
        if(houses[n-1] == '?' || houses[n-1] == possibleHouses[i][0]) {
            vector<int> temp = houseCount;
            temp[i]++;
            
            sort(temp.begin(), temp.end());
            
            if(temp[0] == houseCount[i])
                result.push_back(possibleHouses[i]);
        }
    }
    
    sort(result.begin(), result.end());
    
    for(int i = 0; i < result.size(); i++) {
        cout << result[i] << endl;
    }
    
    return 0;
}