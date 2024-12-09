#include <iostream>
#include <vector>

using namespace std;

struct Trap {
    char type;
    int damage;
};

int main() {
    int HPinit, HPmax;
    while (true) {
        cin >> HPinit >> HPmax;
        if (HPinit == 0 && HPmax == 0) break;

        int R, C;
        cin >> R >> C;

        vector<vector<char>> cave(R, vector<char>(C));
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                cin >> cave[i][j];
            }
        }

        int T;
        cin >> T;
        vector<Trap> traps(T);
        for (int i = 0; i < T; i++) {
            cin >> traps[i].type >> traps[i].damage;
        }

        int S;
        cin >> S;
        char direction;
        int steps;
        int agent_pos_x = 0, agent_pos_y = 0;
        int hit_points = HPinit;

        for (int i = 0; i < S; i++) {
            cin >> direction >> steps;
            for (int j = 0; j < steps; j++) {
                if (direction == 'U') agent_pos_x--;
                else if (direction == 'D') agent_pos_x++;
                else if (direction == 'L') agent_pos_y--;
                else if (direction == 'R') agent_pos_y++;

                if (agent_pos_x < 0 || agent_pos_x >= R || agent_pos_y < 0 || agent_pos_y >= C) {
                    break;  // agent went out of bounds
                }

                char trap_type = cave[agent_pos_x][agent_pos_y];
                for (const Trap& trap : traps) {
                    if (trap_type == trap.type) {
                        hit_points -= trap.damage;
                        break;
                    }
                }

                if (hit_points <= 0) {
                    break;  // agent died
                }
            }

            if (hit_points <= 0) {
                break;  // agent died
            }
        }

        int P;
        cin >> P;
        int potion;
        for (int i = 0; i < P; i++) {
            cin >> potion;
            hit_points = min(HPmax, hit_points + potion);
        }

        if (hit_points > 0) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}