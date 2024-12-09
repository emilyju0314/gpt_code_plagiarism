#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t = 1;
    
    while (true) {
        int N, M, L;
        cin >> N >> M >> L;
        
        if (N == 0 && M == 0 && L == 0) {
            break;
        }
        
        // Read the initial state of the colonies
        vector<vector<int>> colonies(2*N - 1, vector<int>(N));
        for (int i = 0; i < 2*N - 1; i++) {
            for (int j = 0; j < colonies[i].size(); j++) {
                cin >> colonies[i][j];
            }
        }
        
        // Simulate the propagation and self-attacking of viruses
        for (int period = 1; period <= L; period++) {
            // Your logic for virus propagation and self-attacking goes here
        }
        
        // Calculate the total number of viruses after L periods
        int total_viruses = 0;
        for (int i = 0; i < colonies.size(); i++) {
            for (int j = 0; j < colonies[i].size(); j++) {
                total_viruses += colonies[i][j];
            }
        }
        
        // Output the result
        cout << "Case " << t << ": " << total_viruses << endl;
        
        t++;
    }
    
    return 0;
}