#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

int main() {
    vector<int> red(6);
    vector<int> blue(6);
    
    for(int i=0; i<6; i++){
        cin >> red[i];
    }
    for(int i=0; i<6; i++){
        cin >> blue[i];
    }
    
    double dp[101][101] = {0};
    
    for(int p=0; p<=100; p++){
        for(int q=0; q<=100; q++){
            double petr_win = 0.0, tourist_win = 0.0;
            for(int i=0; i<6; i++){
                for(int j=0; j<6; j++){
                    if(i == j){
                        continue;
                    }
                    if(red[i] + p < 100 || blue[j] + q < 100){
                        continue;
                    }
                    if(red[i] + p == 100){
                        tourist_win += (double)blue[j] / 100.0;
                    }
                    else if(blue[j] + q == 100){
                        petr_win += (double)red[i] / 100.0;
                    }
                }
            }
            
            if(petr_win == 0 && tourist_win == 0){
                continue;
            }
            
            dp[p][q] = (double)(100.0 * tourist_win) / (100.0 * petr_win + 100.0 * tourist_win);
        }
    }
    
    cout << fixed << setprecision(12) << dp[100][100] << endl;
    
    return 0;
}