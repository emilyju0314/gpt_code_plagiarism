#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    unordered_map<string, int> goals;
    
    for(int i=0; i<n; i++){
        string team;
        cin >> team;
        
        if(goals.find(team) == goals.end()){
            goals[team] = 1;
        } else {
            goals[team]++;
        }
    }
    
    string winningTeam;
    int maxGoals = 0;
    
    for(auto it : goals){
        if(it.second > maxGoals){
            maxGoals = it.second;
            winningTeam = it.first;
        }
    }
    
    cout << winningTeam << endl;
    
    return 0;
}