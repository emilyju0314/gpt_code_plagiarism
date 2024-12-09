#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Ant {
    int number;
    int x;
    int y;
    char direction;
};

bool compareAnts(const Ant& a, const Ant& b) {
    return a.number < b.number;
}

int main() {
    int W, H, N;
    cin >> W >> H >> N;
    
    vector<Ant> ants(N);
    
    for(int i = 0; i < N; i++) {
        cin >> ants[i].x >> ants[i].y >> ants[i].direction;
        ants[i].number = i + 1;
    }
    
    vector<int> order(N);
    for(int i = 0; i < N; i++) {
        order[i] = i;
    }
    
    // Sort ants based on their positions
    sort(order.begin(), order.end(), [&](int a, int b) {
        return ants[a].x + ants[a].y * W < ants[b].x + ants[b].y * W;
    });
    
    // Perform simulation of ants moving
    vector<int> fallenAnts;
    for(int i = 0; i < N; i++) {
        int antIdx = order[i];
        Ant& ant = ants[antIdx];
        
        int dx = ant.direction == 'E' ? 1 : 0;
        int dy = ant.direction == 'S' ? 1 : 0;

        int nx = ant.x + dx;
        int ny = ant.y + dy;
        
        if(nx < 1 || nx > W || ny < 1 || ny > H) {
            fallenAnts.push_back(ant.number);
        } else {
            ant.x = nx;
            ant.y = ny;
        }
    }
    
    // Sort fallenAnts and print the result
    sort(fallenAnts.begin(), fallenAnts.end());
    for(int antNumber : fallenAnts) {
        cout << antNumber << endl;
    }
    
    return 0;
}