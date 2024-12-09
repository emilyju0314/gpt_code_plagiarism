
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <utility>

#define ll (long long)
#define REP(i,n) for(int i = 0;i<(int)n;i++)
#define FOR(i,a,b) for(int i = (a);i < (b);i++)
#define RFOR(i,a,b) for(int i = (a);i>(b);i--)


using namespace std;


int main(void){
    
    int drugnumber;
    int drugcounter;
    /* x????¨????,y?????´????????? */
    double drugeffect[120][120] = {0};
    int i,j,k,l;
    double max = 0;
    double answer[100] = {0};
    
    while(cin >> drugnumber >> drugcounter,drugnumber+drugnumber)
    {
        double combination[120][120] = {0};
        /*??£??\*/
        FOR(j, 1, drugnumber+1)
        FOR(i, 1, drugnumber+1)
        cin >> drugeffect[j][i];
        
        //cout << drugeffect[2][1];
        
        for(k = 1;k <= drugnumber; k++)
            combination[1][k] = 1.0;
        //cout << combination[1][2] << endl;
        
        /* j?????¬?????°,i????????°*/
        
        for(i = 1; i< drugcounter;i++)
            for(j = 1; j<= drugnumber;j++)
            {
                for(k = 1; k<=drugnumber;k++)
                {
                    if((combination[i][j] * drugeffect[j][k]) >= combination[i+1][k])
                        combination[i+1][k] = combination[i][j]*drugeffect[j][k];
                     //cout << combination[i+1][j] << " ";
                    /*
                     if((combination[j][i] * drugeffect[j][i]) >= combination[j][i])
                     combination[j][i+1] = combination[j][i] * drugeffect[j][i];
                     */
                }
            }
        
    
    for(i = 1 ; i<= drugnumber;i++)
        if(max <  combination[drugcounter][i])
            max = combination[drugcounter][i];
    
        answer[l] = max;
        max = 0;
        l++;
        
    }
    REP(i,l)
    printf("%.2f\n",answer[i]);
    return 0;
    
}