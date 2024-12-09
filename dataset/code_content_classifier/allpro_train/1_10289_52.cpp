#include <iostream>

using namespace std;

int main(){
    int N;
    cin >> N;

    int A[N][N];
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> A[i][j];
        }
    }

    int fl = false;
    long ans = 0;
    for(int i=0; i<N-1; i++){
        for(int j=i+1; j<N; j++){
            int cnt = 0;
            int isconnected = true;
            for(int k=0; k<N; k++){
                if(A[i][j] > A[i][k]+A[k][j]) fl = true;
                if(A[i][j] == A[i][k]+A[k][j] && i!=k && j!=k)isconnected = false;
            }
            if(isconnected) ans += A[i][j];
            if(fl) break;
        }
        if(fl) break;
    }

    if(fl){
        cout << -1 <<endl;
        return 0;
    }

    cout << ans << endl;

    return 0;
}