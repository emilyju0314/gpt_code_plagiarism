#include <cstdio>
#include <string>
using namespace std;

char board[60][60];
bool used[60][60][4];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
string pat = "^>v<";

int main() {
    int N, M; scanf("%d%d", &N, &M);
    int x = 0, y = 0, dir = 0, gx = 0, gy = 0;
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            scanf(" %c", &board[i][j]);
            if(pat.find(board[i][j]) != string::npos) {
                x = i, y = j;
                dir = pat.find(board[i][j]);
            }
            if(board[i][j] == 'G') {
                gx = i, gy = j;
            }
        }
    }

    used[x][y][dir] = true;
    while(1) {
        bool ok = false;
        for(int k=0; k<4; k++) {
            // printf("x = %d, y = %d, dir = %c\n", x+1, y+1, pat[dir]);
            int nd = (dir + k) % 4;
            int nx = x + dx[nd], ny = y + dy[nd];

            // 自分の右が壁でない → 右回りに方向転換
            int px = x + dx[(nd+1)%4], py = y + dy[(nd+1)%4];
            if(px >= 0 && px < N && py >= 0 && py < M && board[px][py] != '#') {
                dir = (dir + 1) % 4;
            }

            // 行き先が壁 → 左回りに
            nx = x + dx[dir], ny = y + dy[dir];
            if(nx < 0 || nx >= N || ny < 0 || ny >= M || board[nx][ny] == '#') {
                dir = (dir + 3) % 4;
                continue;
            }
            if(used[nx][ny][dir]) break;

            // printf("ok: x = %d -> %d, y = %d -> %d, dir = %d\n", x+1, nx+1, y+1, ny+1, dir);
            // とりあえず次には進めそう
            ok = true;
            used[nx][ny][dir] = true;
            x = nx, y = ny;

            // ゴールに辿り着いたら終了
            if(x == gx && y == gy) goto get_ans;

            break;
        }
        if(!ok) {
            printf("-1\n");
            return 0;
        }
    }

    get_ans:
    int ans = 0;
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            bool ok = false;
            for(int k=0; k<4; k++) {
                ok |= used[i][j][k];
            }
            ans += ok;
        }
    }
    printf("%d\n", ans);
    return 0;
}
