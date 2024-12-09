#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

// Data structure to represent a planet
struct Planet {
    double probability;
    vector<int> neighbors;
};

// Perform depth-first search to count the number of connected planets in Bubbledom
int dfs(int current, vector<Planet>& planets, vector<bool>& visited) {
    visited[current] = true;
    int count = 1;
    for(int neighbor : planets[current].neighbors) {
        if(!visited[neighbor]) {
            count += dfs(neighbor, planets, visited);
        }
    }
    return count;
}

int main() {
    int N;
    cin >> N;

    // Read the probabilities for each planet
    vector<Planet> planets(N);
    for(int i = 0; i < N; i++) {
        cin >> planets[i].probability;
    }

    // Read the connections between planets
    for(int i = 0; i < N-1; i++) {
        int planet1, planet2;
        cin >> planet1 >> planet2;
        planets[planet1].neighbors.push_back(planet2);
        planets[planet2].neighbors.push_back(planet1);
    }

    int Q;
    cin >> Q;

    double totalProb = 0;
    for(int i = 0; i < N; i++) {
        totalProb += planets[i].probability;
    }

    int numConnected = 1;
    vector<bool> visited(N, false);
    cout << fixed << setprecision(5);
    
    // Output the initial expected number of kingdoms
    cout << totalProb << endl;

    // Process the reinforcement/weakening of planets
    for(int q = 0; q < Q; q++) {
        int planet;
        double newProb;
        cin >> planet >> newProb;

        // Update the total probability and the probability of the planet
        totalProb = totalProb - planets[planet].probability + newProb;
        planets[planet].probability = newProb;

        // Calculate the expected number of kingdoms
        int connectedPlanets = dfs(0, planets, visited);
        cout << totalProb - (connectedPlanets - numConnected) << endl;
        numConnected = connectedPlanets;
    }

    return 0;
}