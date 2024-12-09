#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

struct Point {
    int x, y;
    Point(int _x, int _y) : x(_x), y(_y) {}
};

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int main() {
    int W, H;
    char palace[30][30];
    
    while (true) {
        cin >> W >> H;
        if (W == 0 && H == 0) break;
        
        Point queen(-1, -1), army(-1, -1);
        vector<Point> exits;
        
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                cin >> palace[i][j];
                if (palace[i][j] == 'Q') {
                    queen.x = j;
                    queen.y = i;
                    palace[i][j] = '.';
                } else if (palace[i][j] == 'A') {
                    army.x = j;
                    army.y = i;
                    palace[i][j] = '.';
                } else if (palace[i][j] == 'E') {
                    exits.push_back(Point(j, i));
                }
            }
        }
        
        queue<pair<Point, Point>> q;
        int queenDist[30][30];
        int armyDist[30][30];
        
        memset(queenDist, -1, sizeof(queenDist));
        memset(armyDist, -1, sizeof(armyDist));
        
        queenDist[queen.y][queen.x] = 0;
        armyDist[army.y][army.x] = 0;
        
        q.push(make_pair(queen, army));
        
        while (!q.empty()) {
            Point currQueen = q.front().first;
            Point currArmy = q.front().second;
            q.pop();
            
            for (int i = 0; i < 4; i++) {
                Point nextQueen = Point(currQueen.x + dx[i], currQueen.y + dy[i]);
                Point nextArmy = Point(currArmy.x + dx[i], currArmy.y + dy[i]);
                
                if (nextQueen.x >= 0 && nextQueen.x < W && nextQueen.y >= 0 && nextQueen.y < H && palace[nextQueen.y][nextQueen.x] != '#' &&
                    queenDist[nextQueen.y][nextQueen.x] == -1) {
                    queenDist[nextQueen.y][nextQueen.x] = queenDist[currQueen.y][currQueen.x] + 1;
                    q.push(make_pair(nextQueen, currArmy));
                }
                
                if (nextArmy.x >= 0 && nextArmy.x < W && nextArmy.y >= 0 && nextArmy.y < H && palace[nextArmy.y][nextArmy.x] != '#' &&
                    armyDist[nextArmy.y][nextArmy.x] == -1) {
                    armyDist[nextArmy.y][nextArmy.x] = armyDist[currArmy.y][currArmy.x] + 1;
                    q.push(make_pair(currQueen, nextArmy));
                }
            }
        }
        
        bool queenEscaped = false, armyCaughtQueen = true;
        for (auto exit : exits) {
            if (queenDist[exit.y][exit.x] <= armyDist[exit.y][exit.x] && queenDist[exit.y][exit.x] != -1) {
                queenEscaped = true;
                break;
            }
        }
        
        if (queenEscaped) {
            cout << "Queen can escape." << endl;
        } else {
            cout << "Queen can not escape and Army can not catch Queen." << endl;
        }
    }
    
    return 0;
}