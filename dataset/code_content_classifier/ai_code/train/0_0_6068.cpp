#include <iostream>
#include <vector>

using namespace std;

int findGroups(vector<int>& managers, vector<int>& groups, int employee) {
    if(managers[employee] == -1) {
        groups[employee] = 1;
        return 1;
    }
    
    if(groups[employee] == 0) {
        groups[employee] = findGroups(managers, groups, managers[employee]) + 1;
    }
    
    return groups[employee];
}

int main() {
    int n;
    cin >> n;
    
    vector<int> managers(n+1);
    for(int i=1; i<=n; i++) {
        cin >> managers[i];
    }
    
    vector<int> groups(n+1, 0);
    int minGroups = 0;
    
    for(int i=1; i<=n; i++) {
        minGroups = max(minGroups, findGroups(managers, groups, i));
    }
    
    cout << minGroups << endl;
    
    return 0;
}