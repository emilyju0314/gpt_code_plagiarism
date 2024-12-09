#include <bits/stdc++.h>
using namespace std;
 
struct Block{
    int b[2][2][2];
 
    void input(){
        string temp;
        for(int i = 0; i < 2; i++){
            for(int j = 0; j < 2; j++){
                cin >> temp;
                for(int k = 0; k < 2; k++){
                    if(temp[k] == '#'){
                        b[i][j][k] = 1;
                    }
                    else{
                        b[i][j][k] = 0;
                    }
                }
            }
        }
    }
 
    bool isOk(int dx, int dy){
        for(int i = 0; i < 2; i++){
            if(dx == -1 && (b[i][0][0] == 1 || b[i][0][1] == 1)){
                return false;
            }
            if(dx == 1 && (b[i][1][0] == 1 || b[i][1][1] == 1)){
                return false;
            }
            if(dy == -1 && (b[i][0][0] == 1 || b[i][1][0] == 1)){
                return false;
            }
            if(dy == 1 && (b[i][0][1] == 1 || b[i][1][1] == 1)){
                return false;
            }
        }
 
        return true;
    }
 
    void slide(int dx, int dy){
 
        int newB[2][2][2];
        memset(newB, 0, sizeof(newB));
        for(int k = 0; k < 2; k++){
            for(int i = 0; i < 2; i++){
                for(int j = 0; j < 2; j++){
                    int tempX = i + dx;
                    int tempY = j + dy;
 
                    if(0 <= tempX && tempX < 2 && 0 <= tempY && tempY < 2){
                        newB[k][tempX][tempY] = b[k][i][j];
                    }
                }
            }
        }
 
        swap(b, newB);
    }
};
 
int calcAll(int N, int cnt, vector<Block>& block, int dx, int dy, int field[20][2][2]){
    if(!block[cnt].isOk(dx, dy)){
        return -10000;
    }
 
    int ret = 0;
 
    Block tempBlock = block[cnt];
    tempBlock.slide(dx, dy);
 
    int lower[2][2];
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            if(tempBlock.b[0][i][j] == 1){
                lower[i][j] = 0;
                continue;
            }
            else if(tempBlock.b[1][i][j] == 1){
                lower[i][j] = 1;
            }
            else{
                lower[i][j] = 2;
            }
        }
    }
 
    int upper[2][2];
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            for(int k = 19; k >= 0; k--){
                if(field[k][i][j] == 1){
                    upper[i][j] = k;
                    break;
                }
            }
        }
    }
 
    int posH = -10;
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            if(lower[i][j] == 2){
                continue;
            }
            int temp = upper[i][j] + 1 - lower[i][j];
            posH = max(posH, temp);
        }
    }
 
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            for(int k = 0; k < 2; k++){
                if(tempBlock.b[i][j][k] == 1){
                    int tempH = posH + i;
                    field[tempH][j][k] = tempBlock.b[i][j][k];
                }
            }
        }
    }
 
    vector<bool> isDeleted(20, false);
    for(int i = 1; i < 19; i++){
        bool isOk = true;
        for(int j = 0; j < 2; j++){
            for(int k = 0; k < 2; k++){
                if(field[i][j][k] == 0){
                    isOk = false;
                }
            }
        }
        if(isOk){
            ret++;
            isDeleted[i] = true;
            for(int j = 0; j < 2; j++){
                for(int k = 0; k < 2; k++){
                    field[i][j][k] = 0;
                }
            }
        }
    }
 
    int deleteCnt = 0;
    for(int i = 1; i < 20; i++){
        if(isDeleted[i - 1]){
            deleteCnt++;
        }
        for(int j = 0; j < 2; j++){
            for(int k = 0; k < 2; k++){
                if(deleteCnt > 0){
                    field[i - deleteCnt][j][k] = field[i][j][k];
                    field[i][j][k] = 0;
                }
            }
        }
    }
 
    int maxCnt = 0;
    if(cnt != N - 1){
        for(int ndx = -1; ndx <= 1; ndx++){
            for(int ndy = -1; ndy <= 1; ndy++){
                int nextField[20][2][2];
                memcpy(nextField, field, 20 * 2 * 2 * sizeof(int));
                int temp = calcAll(N, cnt + 1, block, ndx, ndy, nextField);
                maxCnt = max(maxCnt, temp);
            }
        }
    }
 
    return ret + maxCnt;
}
 
int main(){
 
    while(true){
        int H, N;
        cin >> H >> N;
        if(H == 0){
            break;
        }
 
        int field[20][2][2];
        memset(field, 0, sizeof(field));
 
        for(int i = 0; i < 2; i++){
            for(int j = 0; j < 2; j++){
                field[0][i][j] = 1;
            }
        }
 
        for(int i = 1; i <= H; i++){
            string temp;
            for(int j = 0; j < 2; j++){
                cin >> temp;
                for(int k = 0; k < 2; k++){
                    if(temp[k] == '#'){
                        field[i][j][k] = 1;
                    }
                }
            }
        }
 
        vector<Block> block(N);
 
        for(int i = 0; i < N; i++){
            block[i].input();
        }
         
        int ans = 0;
        for(int dx = -1; dx <= 1; dx++){
            for(int dy = -1; dy <= 1; dy++){
                int nextField[20][2][2];
                memcpy(nextField, field, sizeof(field));
                int cnt = calcAll(N, 0, block, dx, dy, nextField);
                ans = max(ans, cnt);
            }
        }
         
        cout << ans << endl;
    }
 
    return 0;
}
