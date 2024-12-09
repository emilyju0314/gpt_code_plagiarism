#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int n, m;
vector<int> animals;
vector<vector<int>> graph;
vector<vector<int>> minAnimal;

void floydWarshall() {
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                minAnimal[i][j] = min(minAnimal[i][j], max(minAnimal[i][k], minAnimal[k][j]));
            }
        }
    }
}

int main() {
    cin >> n >> m;
    animals.resize(n);
    graph.resize(n);
    minAnimal.resize(n, vector<int>(n, 0));

    for (int i = 0; i < n; ++i) {
        cin >> animals[i];
    }

    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        graph[x].push_back(y);
        graph[y].push_back(x);
        minAnimal[x][y] = minAnimal[y][x] = min(animals[x], animals[y]);
    }

    floydWarshall();

    double sum = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (i != j) {
                sum += minAnimal[i][j];
            }
        }
    }

    double avg = sum / (n * (n - 1) / 2);

    cout << setprecision(6) << fixed << avg << endl;

    return 0;
}