#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>

using namespace std;

const int INF = 1e9;

struct Cube {
    string faces[6];
    int top = 0;

    Cube(vector<string>& input_faces) {
        for(int i = 0; i < 6; i++) {
            faces[i] = input_faces[i];
        }
    }

    string getTopFace() {
        return faces[top];
    }

    void roll(char dir) {
        if(dir == '<') {
            int new_top;
            if(top == 0) new_top = 3;
            if(top == 1) new_top = 2;
            if(top == 2) new_top = 0;
            if(top == 3) new_top = 1;
            top = new_top;
        }
        if(dir == '>') {
            int new_top;
            if(top == 0) new_top = 2;
            if(top == 1) new_top = 3;
            if(top == 2) new_top = 1;
            if(top == 3) new_top = 0;
            top = new_top;
        }
        if(dir == '^') {
            int new_top;
            if(top == 0) new_top = 5;
            if(top == 1) new_top = 4;
            if(top == 4) new_top = 0;
            if(top == 5) new_top = 1;
            top = new_top;
        }
        if(dir == 'v') {
            int new_top;
            if(top == 0) new_top = 4;
            if(top == 1) new_top = 5;
            if(top == 4) new_top = 1;
            if(top == 5) new_top = 0;
            top = new_top;
        }
    }
};

bool isValid(int r, int c, int H, int W) {
    return r >= 0 && r < H && c >= 0 && c < W;
}

int main() {
    int H, W;
    cin >> H >> W;

    vector<vector<char>> map(H, vector<char>(W));
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            cin >> map[i][j];
        }
    }

    vector<string> faces;
    for(int i = 0; i < 6; i++) {
        string face;
        cin >> face;
        faces.push_back(face);
    }

    int RS, CS, RD, CD;
    cin >> RS >> CS >> RD >> CD;

    Cube start_cube(faces);
    Cube goal_cube(faces);

    int dr[] = {0, 0, -1, 1};
    int dc[] = {1, -1, 0, 0};
    string dp[12][12][6][12][12][6];

    for(int i = 0; i < 12; i++) {
        for(int j = 0; j < 12; j++) {
            for(int k = 0; k < 6; k++) {
                for(int p = 0; p < 12; p++) {
                    for(int q = 0; q < 12; q++) {
                        for(int r = 0; r < 6; r++) {
                            dp[i][j][k][p][q][r] = "infinite";
                        }
                    }
                }
            }
        }
    }

    dp[RS-1][CS-1][start_cube.top][RS-1][CS-1][start_cube.top] = start_cube.getTopFace();

    bool is_no = false;

    for(int step = 0; step < H*W; step++) {
        bool updated = false;
        for(int r1 = 0; r1 < H; r1++) {
            for(int c1 = 0; c1 < W; c1++) {
                for(int f1 = 0; f1 < 6; f1++) {
                    for(int r2 = 0; r2 < H; r2++) {
                        for(int c2 = 0; c2 < W; c2++) {
                            for(int f2 = 0; f2 < 6; f2++) {
                                if(dp[r1][c1][f1][r2][c2][f2] == "infinite") continue;

                                char instr = map[r1][c1];
                                string path = dp[r1][c1][f1][r2][c2][f2];

                                Cube current_cube = start_cube;
                                current_cube.top = f1;

                                for(int dir = 0; dir < 4; dir++) {
                                    if((instr == '+' || instr == '-' || instr == '<' || instr == '>') && (dir == 0 || dir == 1)) continue;
                                    if((instr == '+' || instr == '|' || instr == '^' || instr == 'v') && (dir == 2 || dir == 3)) continue;

                                    int nr1 = r1 + dr[dir];
                                    int nc1 = c1 + dc[dir];

                                    if(isValid(nr1, nc1, H, W)) {
                                        char next_instr = map[nr1][nc1];
                                        Cube next_cube = current_cube;
                                        next_cube.roll(dir == 0 ? '>' : (dir == 1 ? '<' : (dir == 2 ? 'v' : '^')));

                                        int nr2 = nr1;
                                        int nc2 = nc1;

                                        if(dir == 0) nc2++;
                                        if(dir == 1) nc2--;
                                        if(dir == 2) nr2--;
                                        if(dir == 3) nr2++;

                                        if(isValid(nr2, nc2, H, W)) {
                                            if(next_instr != '.' && next_cube.getTopFace() >= path) {
                                                path += next_cube.getTopFace();
                                                if(dp[nr1][nc1][next_cube.top][r2][c2][f2] == "infinite" || dp[nr1][nc1][next_cube.top][r2][c2][f2] > path) {
                                                    dp[nr1][nc1][next_cube.top][r2][c2][f2] = path;
                                                    updated = true;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }

        if(!updated) break;
    }

    string ans = "no";

    for(int f2 = 0; f2 < 6; f2++) {
        if(dp[RD-1][CD-1][f2][RD-1][CD-1][f2] == "infinite") {
            is_no = true;
            break;
        }

        if(ans == "no" || dp[RD-1][CD-1][f2][RD-1][CD-1][f2] < ans) {
            ans = dp[RD-1][CD-1][f2][RD-1][CD-1][f2];
        }
    }

    if(is_no) cout << "no" << endl;
    else cout << ans << endl;

    return 0;
}