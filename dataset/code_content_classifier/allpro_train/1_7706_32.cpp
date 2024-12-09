#include <iostream>
using namespace std;
int main(){
    int N;
    cin >> N;
    char p[N];

    for(int i = 0; i < N; i++){
        cin >> p[i];
    }

    char ans = p[0];
    //cout << ans << endl;
    for(int i = 1; i < N; i++){
        if(ans == 'T' && p[i] == 'T') ans = 'T';
        else if(ans == 'T' && p[i] == 'F') ans = 'F';
        else if(ans == 'F' && p[i] == 'T') ans = 'T';
        else ans = 'T';
        //cout << i << ". " << ans << endl;
    }
    cout << ans << endl;
}

