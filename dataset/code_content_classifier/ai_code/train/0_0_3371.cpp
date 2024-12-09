#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

double calculateMutationProbability(int s, int n, int t, string weekday, string time, int p, int m) {
    int totalEggs = 0;
    double totalMutated = 0;
    
    // Simulate the game progress for each stage
    for(int i = 0; i < m; i++) {
        // Simulate the hatching of eggs
        totalEggs += n;
        
        // Check if mutation can occur
        bool mutationPossible = false;
        if (weekday == "All" || weekday == "Mon" || weekday == "Tue" || weekday == "Wed" || weekday == "Thu" || weekday == "Fri" || weekday == "Sat") {
            mutationPossible = true;
        }
        if (time == "All" || time == "Day" || time == "Night") {
            mutationPossible = true;
        }
        
        if (mutationPossible) {
            // Calculate the probability of mutation
            double mutationProbability = 1.0 / p;
            totalMutated += mutationProbability * totalEggs;
        }
    }
    
    // Calculate the overall probability
    double overallProbability = totalMutated / (n * m);
    
    return overallProbability;
}

int main() {
    int s, n, t, p, m;
    string weekday, time;
    
    while (true) {
        cin >> s >> n >> t >> weekday >> time >> p >> m;
        if (s == 0 && n == 0 && t == 0 && weekday == "None" && time == "None" && p == 0 && m == 0) {
            break;
        }
        
        cout << fixed << setprecision(10) << calculateMutationProbability(s, n, t, weekday, time, p, m) << endl;
    }
    
    return 0;
}