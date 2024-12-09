#include <iostream>
#include <iomanip>
#include <vector>
#include <map>

using namespace std;

int n;
char s, t, b;
map<char, vector<char>> rooms;
map<char, double> prob;

void moveRobot(char room, int battery) {
    if (battery == 0) {
        return;
    }
    
    double p = 1.0 / rooms[room].size();
    for (char nextRoom : rooms[room]) {
        prob[nextRoom] += p * prob[room];
        moveRobot(nextRoom, battery - 1);
    }
}

int main() {
    while (true) {
        cin >> n;
        if (n == 0) {
            break;
        }
        
        cin >> s >> t >> b;
        
        rooms.clear();
        prob.clear();
        
        vector<char> neighbors = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I'};
        for (char room : neighbors) {
            rooms[room] = neighbors;
            prob[room] = (room == s) ? 1.0 : 0.0;
        }
        
        for (char room : neighbors) {
            vector<char> neighborsCopy = neighbors;
            neighborsCopy.erase(find(neighborsCopy.begin(), neighborsCopy.end(), room));
            rooms[room] = neighborsCopy;
        }
        
        moveRobot(s, n);
        
        cout << fixed << setprecision(8) << prob[t] << endl;
    }
    
    return 0;
}