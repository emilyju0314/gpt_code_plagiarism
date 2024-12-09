#include<iostream>
#include<vector>

using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        int r, c, k;
        cin >> r >> c >> k;

        vector<vector<char>> farm(r, vector<char>(c));
        int riceCount = 0;

        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                cin >> farm[i][j];
                if(farm[i][j] == 'R') riceCount++;
            }
        }

        int minRicePerChicken = riceCount / k;
        int extraChickens = riceCount % k;
        int assignedRice = 0;
        int currentChicken = 0;

        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(farm[i][j] == 'R'){
                    if(currentChicken < extraChickens){
                        farm[i][j] = 'a' + currentChicken;
                        currentChicken++;
                        assignedRice++;
                    } else {
                        farm[i][j] = 'A' + currentChicken;
                        if(assignedRice == minRicePerChicken){
                            currentChicken++;
                            assignedRice = 0;
                        } else {
                            assignedRice++;
                        }
                    }
                }
            }
        }

        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                cout << farm[i][j];
            }
            cout << endl;
        }
    }

    return 0;
}