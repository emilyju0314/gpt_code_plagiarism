#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 99999999999999999
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;



#define NUM 10000000
#define SIZE 2000005
//#define SIZE 25

struct Info{
    void set(int arg_num_3,int arg_num_4,int arg_num_5){
        num_3 = arg_num_3;
        num_4 = arg_num_4;
        num_5 = arg_num_5;
    }
    int num_3,num_4,num_5;
};

int MINUS[6] = {0,0,0,2,5,9};
int table[SIZE]; //table[i] = i本の直線を作れる最小の点の数
int dp[SIZE]; //dp[i] = マイナスiを作れる最小の点の数
Info info[SIZE]; //各iに対する、同一直線上3,4,5点の個数


int getNUM(int number){

    int L = 1,R = 4000,mid = (L+R)/2;
    int ret;

    while(L <= R){

        if((mid*(mid-1))/2 >= number){

            ret = mid;
            R = mid-1;

        }else{

            L = mid+1;
        }
        mid = (L+R)/2;
    }
    return ret;
}

int main(){

    dp[0] = 0;

    for(int i = 1; i < SIZE; i++){

        dp[i] = NUM;
        info[i].set(NUM,NUM,NUM);
    }

    info[0].set(0,0,0);

    int next_3,next_4,next_5;

    //3
    for(int i = MINUS[3]; i < SIZE; i++){

        next_3 = info[i-MINUS[3]].num_3+1;
        next_4 = info[i-MINUS[3]].num_4;
        next_5 = info[i-MINUS[3]].num_5;

        if(3*next_3+4*next_4+5*next_5 < dp[i]){

            dp[i] = 3*next_3+4*next_4+5*next_5;
            info[i].set(next_3,next_4,next_5);
        }
    }

    //4
    for(int i = MINUS[4]; i < SIZE; i++){

        next_3 = info[i-MINUS[4]].num_3;
        next_4 = info[i-MINUS[4]].num_4+1;
        next_5 = info[i-MINUS[4]].num_5;

        if(3*next_3+4*next_4+5*next_5 < dp[i]){

            dp[i] = 3*next_3+4*next_4+5*next_5;
            info[i].set(next_3,next_4,next_5);
        }
    }

    //5
    for(int i = MINUS[5]; i < SIZE; i++){

        next_3 = info[i-MINUS[5]].num_3;
        next_4 = info[i-MINUS[5]].num_4;
        next_5 = info[i-MINUS[5]].num_5+1;

        if(3*next_3+4*next_4+5*next_5 < dp[i]){

            dp[i] = 3*next_3+4*next_4+5*next_5;
            info[i].set(next_3,next_4,next_5);
        }
    }

    table[1] = 1;
    int tmp;

    for(int i = 3; i < SIZE; i++){

        if(i == 7 || i == 9 || i == 20)continue;

        tmp = getNUM(i);

        while(true){

            if(dp[(tmp*(tmp-1))/2-i] <= tmp){

                table[i] = tmp;
                break;
            }
            tmp++;
        }
    }

    int N;
    scanf("%d",&N);

    if(N == 1){

        printf("2\n");
        printf("0 0\n");
        printf("100 100\n");

        return 0;

    }else if(N == 2){

        printf("-1\n");
        return 0;

    }else if(N == 7){

        printf("6\n");
        printf("0 0\n");
        printf("24 0\n");
        printf("12 6\n");
        printf("8 8\n");
        printf("16 8\n");
        printf("12 12\n");
        return 0;

    }else if(N == 9){

        printf("6\n");
        printf("0 0\n");
        printf("4 0\n");
        printf("1 1\n");
        printf("2 1\n");
        printf("3 1\n");
        printf("2 2\n");
        return 0;

    }else if(N == 20){

        printf("8\n");
        printf("0 0\n");
        printf("24 0\n");
        printf("12 6\n");
        printf("8 8\n");
        printf("16 8\n");
        printf("12 12\n");
        printf("11 100\n");
        printf("13 9999\n");
        return 0;
    }

    printf("%d\n",table[N]);

    int minus = (table[N]*(table[N]-1))/2-N;
    int x = 1;

    for(int i = 0; i < info[minus].num_3; i++){

        for(int k = 0; k < 3; k++){

            printf("%d %d\n",x,13*x*x+k);
        }
        x++;
    }

    for(int i = 0; i < info[minus].num_4; i++){

        for(int k = 0; k < 4; k++){

            printf("%d %d\n",x,13*x*x+k);
        }
        x += 1;
    }

    for(int i = 0; i < info[minus].num_5; i++){

       for(int k = 0; k < 5; k++){

            printf("%d %d\n",x,13*x*x+k);
        }
        x += 1;
    }

    int rest = table[N]-dp[minus];

    for(int i = 0; i < rest; i++){

        printf("%d %d\n",x,13*x*x+i);

        x += 1;
    }

    return 0;
}

