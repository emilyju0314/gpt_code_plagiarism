#include<bits/stdc++.h>
using namespace std;

int main(){
    int N;
    double P;
    cin >> N >> P;

    int maps_to_study = 0;
    double probability = 0;

    while(probability < P){
        maps_to_study++;
        probability = 1 - pow((double)(N-maps_to_study)/N, 2);
    }

    cout << maps_to_study << endl;

    return 0;
}