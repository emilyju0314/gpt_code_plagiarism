#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> initialSequence(n);
    for (int i = 0; i < n; i++) {
        cin >> initialSequence[i];
    }
    
    vector<int> finalSequence = initialSequence;
    vector<pair<int, int>> commands;
    
    // Try up to three commands
    for (int cmd1 = 1; cmd1 < n; cmd1++) {
        for (int cmd2 = cmd1+1; cmd2 < n; cmd2++) {
            vector<int> tempSequence = initialSequence;
            reverse(tempSequence.begin() + cmd1, tempSequence.begin() + cmd2 + 1);
            
            if (tempSequence == finalSequence) {
                commands.push_back({cmd1, cmd2});
            }
        }
    }
    
    cout << commands.size() << endl;
    for (auto command : commands) {
        cout << command.first << " " << command.second << endl;
    }
    
    return 0;
}