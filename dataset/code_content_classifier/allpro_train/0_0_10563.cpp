#include <iostream>
#include <vector>
#include <map>
#include <iomanip>

using namespace std;

map<int, double> probabilities;
vector<vector<int>> graph;

double calculateProbability(int participant) {
    if(probabilities.find(participant) != probabilities.end()) {
        return probabilities[participant];
    }

    double probability = 1.0;
    for(int contact : graph[participant]) {
        probability *= (1 - calculateProbability(contact));
    }

    probabilities[participant] = probability;
    return probability;
}

int main() {
    int N;
    cout << fixed << setprecision(9);

    while (true) {
        cin >> N;
        if (N == 0) {
            break;
        }

        probabilities.clear();
        graph.clear();
        graph.resize(N + 1);

        for(int i = 1; i <= N; ++i) {
            double p;
            int m;
            cin >> p >> m;
            probabilities[i] = p;

            for(int j = 0; j < m; ++j) {
                int contact;
                cin >> contact;
                graph[i].push_back(contact);
            }
        }

        double result = 1.0;
        for(int i = 1; i <= N; ++i) {
            result *= (1 - calculateProbability(i));
        }

        cout << result << endl;
    }

    return 0;
}